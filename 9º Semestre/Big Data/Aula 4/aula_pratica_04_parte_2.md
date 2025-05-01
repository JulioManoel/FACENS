# Aula 04 - Parte 2

## Configuração do Ambiente

1. Certifique-se de ter o Docker instalado em sua máquina.
2. Utilize o Docker Compose para subir o ambiente Hadoop:

```bash
docker-compose up -d
```

3. Acesse o container do namenode:

```bash
docker exec -it docker-hive-namenode-1 /bin/bash
```

```bash
export HADOOP_CLASSPATH=/usr/lib/jvm/java-8-openjdk-amd64/lib/tools.jar
```

## Tarefa 1: Executando um Word Count

### 1.1 Implementação do MapReduce

1.1.1. Crie um diretório para o código MapReduce:

```bash
mkdir ~/wordcount
cd ~/wordcount
```

1.1.2. Utilize um editor de texto para criar os arquivos Java `WordCountMapper.java` e `WordCountReducer.java` com base no exemplo fornecido pelo Hadoop.

1.1.3. Utilize um editor de texto para criar um arquivo chamado WordCountMapper.java:

```bash
import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WordCountMapper extends Mapper<Object, Text, Text, IntWritable> {

  private final static IntWritable one = new IntWritable(1);
  private Text word = new Text();

  public void map(Object key, Text value, Context context) throws IOException, InterruptedException {
    StringTokenizer itr = new StringTokenizer(value.toString());
    while (itr.hasMoreTokens()) {
      word.set(itr.nextToken());
      context.write(word, one);
    }
  }
}

```

docker cp WordCountMapper.java docker-hive-namenode-1:/root/wordcount

1.1.4. Crie um arquivo chamado WordCountReducer.java:

```bash
import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class WordCountReducer extends Reducer<Text, IntWritable, Text, IntWritable> {

  private IntWritable result = new IntWritable();

  public void reduce(Text key, Iterable<IntWritable> values, Context context)
      throws IOException, InterruptedException {
    int sum = 0;
    Iterator<IntWritable> iterator = values.iterator();
    while (iterator.hasNext()) {
      sum += iterator.next().get();
    }
    result.set(sum);
    context.write(key, result);
  }
}

```

docker cp WordCountReducer.java docker-hive-namenode-1:/root/wordcount

1.1.5. Utilize um editor de texto para criar um arquivo chamado WordCount.java:

```bash
import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WordCount {

  public static class TokenizerMapper
       extends Mapper<Object, Text, Text, IntWritable>{

    private final static IntWritable one = new IntWritable(1);
    private Text word = new Text();

    public void map(Object key, Text value, Context context
                    ) throws IOException, InterruptedException {
      StringTokenizer itr = new StringTokenizer(value.toString());
      while (itr.hasMoreTokens()) {
        word.set(itr.nextToken());
        context.write(word, one);
      }
    }
  }

  public static class IntSumReducer
       extends Reducer<Text,IntWritable,Text,IntWritable> {
    private IntWritable result = new IntWritable();

    public void reduce(Text key, Iterable<IntWritable> values,
                       Context context
                       ) throws IOException, InterruptedException {
      int sum = 0;
      for (IntWritable val : values) {
        sum += val.get();
      }
      result.set(sum);
      context.write(key, result);
    }
  }

  public static void main(String[] args) throws Exception {
    Configuration conf = new Configuration();
    Job job = Job.getInstance(conf, "word count");
    job.setJarByClass(WordCount.class);
    job.setMapperClass(WordCountMapper.class);
    job.setCombinerClass(WordCountReducer.class);
    job.setReducerClass(WordCountReducer.class);
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(IntWritable.class);
    FileInputFormat.addInputPath(job, new Path(args[0]));
    FileOutputFormat.setOutputPath(job, new Path(args[1]));
    System.exit(job.waitForCompletion(true) ? 0 : 1);
  }
}

```

docker cp WordCount.java docker-hive-namenode-1:/root/wordcount

1.1.6. Compile os arquivos Java:

```bash
hadoop com.sun.tools.javac.Main WordCountMapper.java WordCountReducer.java WordCount.java
jar cf wc.jar WordCount*.class
```

### 1.2 Execução do Job MapReduce

#### 1.2.1. Execute o Word Count:

```bash
hadoop fs -mkdir /user/hive/input
echo "Hello World Hello Hadoop" | hadoop fs -put - /user/hive/input/input.txt
```

#### 1.2.2. Execute o Word Count:

```bash
hadoop jar wc.jar WordCount /user/hive/input /user/hive/output
```

### 1.3 Verificação dos Resultados

1.3.1. Visualize a saída do Word Count:

```bash
hadoop fs -cat /user/hive/output/*
```

Claro, vou explicar o processo do MapReduce no contexto do exemplo WordCount:

1. **Divisão (Splitting)**:

   - O primeiro passo do MapReduce é dividir o conjunto de dados de entrada em pedaços chamados "splits". Cada split contém uma parte dos dados e é processado por uma instância de mapper. Os splits são tipicamente do tamanho de blocos HDFS.

2. **Mapeamento (Mapping)**:

   - Cada instância de mapper processa um split. Durante a fase de mapeamento, os dados de entrada são lidos e transformados em pares chave-valor. No exemplo WordCount, o mapper lê cada linha do arquivo de texto, quebra as palavras e emite pares (palavra, 1) para cada palavra encontrada.

3. **Ordenação e Particionamento (Shuffling)**:

   - Os pares chave-valor emitidos pelos mappers são ordenados e particionados para garantir que todas as ocorrências da mesma chave (no nosso exemplo, a palavra) sejam agrupadas e enviadas para o mesmo reducer. Isso envolve um processo chamado "shuffling".

4. **Redução (Reducing)**:

   - Cada instância de reducer recebe um conjunto de pares chave-valor agrupados por chave. No exemplo WordCount, o reducer recebe pares (palavra, [1, 1, 1, ...]) para cada palavra. O reducer, então, soma as contagens para cada palavra, resultando em pares finais (palavra, contagem_total).

5. **Escrita de Saída**:
   - O resultado final, que consiste nos pares (palavra, contagem_total), é escrito no sistema de arquivos de saída, geralmente HDFS.

Entendendo essas etapas, podemos voltar ao resultado final que você forneceu. No arquivo `part-r-00000`, você vê as palavras "Hadoop", "Hello" e "World" com suas respectivas contagens. Cada linha deste arquivo é o resultado do processo de MapReduce aplicado ao conjunto de dados de entrada. O `_SUCCESS` é um marcador de que o job foi concluído com sucesso.

# Exercícios Práticos de MapReduce com Hadoop

Nestes exercícios, exploraremos o funcionamento básico do MapReduce usando o exemplo clássico do WordCount. O objetivo é fornecer uma compreensão prática do processo de mapeamento e redução no contexto do Hadoop.

## Pré-Requisitos

- Ambiente Hadoop configurado e funcional.
- Código-fonte do WordCountMapper.java e WordCountReducer.java disponível.

## Exercício 1: WordCountMapper

### Alteração 1: Ignorar Palavras Curtas

1. Abra o arquivo `WordCountMapper.java`.
2. Localize o método `map`.
3. Adicione a seguinte verificação antes de emitir a palavra como saída, ignorar qualquer palavra com menos de 3 caracteres.

### Alteração 2: Conversão para Minúsculas

1. Abra o arquivo `WordCountMapper.java`.
2. Localize o método `map`.
3. Adicione a trasformação de todas palavras pra minusculo, evitando Diferenças de Caixa alta e baixa

## Exercício 2: WordCountReducer

### Alteração 1: Exibir Apenas Palavras com Contagens Específicas

1. Abra o arquivo `WordCountReducer.java`.
2. Localize o método `reduce`.
3. Adicione uma condição de não printar no resultado final palavras com menos de 5 contadores

### Alteração 2: Alterar Formato de Saída

1. Abra o arquivo `WordCountReducer.java`.
2. Localize o método `reduce`.
3. Altere a linha de emissão da palavra para o seguinte formato:
   ```java
   Text outputKey = new Text(key.toString() + ": ");
   context.write(outputKey, result);
   ```
