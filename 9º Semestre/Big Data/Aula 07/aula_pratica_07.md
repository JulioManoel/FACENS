# Aula 07

Utilizaremos um conjunto de dados fictício relacionado a compras online.

O objetivo desta aula prática é familiarizar os alunos com o Apache Pig, uma plataforma para análise de grandes conjuntos de dados que rodam no topo do Hadoop. Vamos realizar operações básicas de manipulação de dados usando o Pig Latin, a linguagem de script do Pig.

## Preparação do Ambiente

### 1. Docker com Pig e Hadoop

```bash
wget https://downloads.apache.org/pig/pig-0.17.0/pig-0.17.0.tar.gz
tar -xzvf pig-0.17.0.tar.gz
docker cp pig-0.17.0 docker-hive-hive-server-1:/opt
docker exec -it docker-hive-hive-server-1 /bin/bash
export PIG_HOME=/opt/pig-0.17.0
export PATH=$PATH:$PIG_HOME/bin
source ~/.bashrc
pig --version
```

## Análise de Dados com Apache Pig

Vamos trabalhar com um conjunto de dados simulado representando compras de produtos por clientes. O arquivo `compras.txt` possui as seguintes colunas: Produto, Valor, Cliente.

### 1. Upload do Arquivo

Copie o arquivo `compras.txt` para o container:

```bash
docker cp compras.txt docker-hive-hive-server-1:/hadoop-data
docker exec -it docker-hive-hive-server-1 /bin/bash
hadoop fs -mkdir /user/hive/compras
hadoop fs -put /hadoop-data/compras.txt  /user/hive/compras
```

### 2. Execução do Apache Pig

Acesse o container do Pig e Hadoop:

```bash
docker exec -it pig-hadoop /bin/bash
```

#### 2. Explorando o Pig Latin:

2.1. **Criação do Script Pig:**

- Crie um script Pig chamado `processamento.pig`.

  2.2. **Carregando Dados:**

- Carregue os dados de um arquivo de texto (por exemplo, `compras.txt`) usando o comando `LOAD`.

```pig
compras = LOAD '/user/hive/compras/compras.txt' USING PigStorage(',') AS (Produto:chararray, Valor:float, Cliente:chararray);
```

2.3. **Visualizando Dados:**

- Utilize `DUMP` para visualizar algumas linhas dos dados carregados.

```pig
DUMP compras;
```

2.4. **Filtragem de Dados:**

- Realize uma filtragem para incluir apenas as transações com um valor superior a R$ 100,00.

```pig
compras_clienteA = FILTER compras BY Cliente == 'ClienteA';
```

2.5. **Agrupamento e Contagem:**

- Agrupe os dados por produto e conte o número de transações para cada produto.

```pig
soma_clienteA = FOREACH (GROUP compras_clienteA ALL) GENERATE SUM(compras_clienteA.Valor);
```

2.7. **Armazenamento do Resultado:**

- Armazene o resultado em um diretório no HDFS.

```pig
STORE soma_clienteA INTO '/user/hive/soma_clienteA';
```

#### 3. Execução do Script:

- Execute o script Pig no ambiente Hadoop utilizando o comando `pig -f processamento.pig`.

```pig

-- processamento.pig

-- Carregar dados
compras = LOAD '/user/hive/compras/compras.txt' USING PigStorage(',') AS (Produto:chararray, Valor:float, Cliente:chararray);

-- Filtrar compras para o cliente 'ClienteA'
compras_clienteA = FILTER compras BY Cliente == 'ClienteA';

-- Calcular a soma dos valores para o cliente 'ClienteA'
soma_clienteA = FOREACH (GROUP compras_clienteA ALL) GENERATE SUM(compras_clienteA.Valor) AS total;

-- Armazenar resultados
STORE soma_clienteA INTO '/user/hive/compras/soma_clienteA';

```

```bash
docker cp processamento.pig docker-hive-hive-server-1:/hadoop-data
docker exec -it docker-hive-hive-server-1 /bin/bash
pig -f processamento.pig
hadoop fs -cat /user/hive/compras/soma_clienteA/part-r-00000
```

#### 4. Exploração Adicional:

4.1. **Criação de Funções UDF (User-Defined Functions):**

Para criar funções definidas pelo usuário (UDFs) no Pig, você precisa seguir alguns passos.

### Passos para Criar uma Função UDF no Pig:

1. **Escrever a Função UDF em Java ou Python**:

   - Você pode criar UDFs em Java ou Python.
   - Em Java, você precisa compilar o código para um arquivo JAR.
   - Em Python, você precisa ter um script Python.

2. **Registrar a UDF no Script Pig**:

   - No script Pig, você precisa registrar a UDF usando a declaração `REGISTER`.

3. **Usar a UDF em Operações Pig**:
   - Depois de registrar a UDF, você pode usá-la nas operações Pig como qualquer outra função embutida.

### Exemplo de UDF em Python

3.1 **Escrever a Função UDF em Python**:

```python
# Exemplo de UDF em Python
@outputSchema("uppercased_text:chararray")
def to_uppercase(text):
    if text is None:
        return None
    return text.upper()
```

3.2 **Salvar a UDF em um Arquivo Python**:

- Salve a função Python em um arquivo, por exemplo, `udf.py`.

  3.3 **Registrar a UDF no Script Pig**:

  ```pig
    -- Carregar dados e aplicar a UDF
    data = LOAD '/user/hive/compras/compras.txt' AS (cliente: chararray, valor: float);

    -- Aplicar transformação para deixar os nomes em maiúsculas
    transformed_data = FOREACH data GENERATE UPPER(cliente) AS cliente_maiusculo, valor;

    -- Armazenar resultados
    STORE transformed_data INTO '/user/hive/compras/clientes_maiusculos';

  ```

```bash
docker cp udf.py docker-hive-hive-server-1:/hadoop-data
docker cp udf.pig docker-hive-hive-server-1:/hadoop-data
docker exec -it docker-hive-hive-server-1 /bin/bash
pig -f udf.pig
hadoop fs -cat /user/hive/compras/clientes_maiusculos/*

```

#### 5. Exercicio:

- Crie um script Pig que envolva múltiplas etapas de transformação, incluindo filtragem, agrupamento, e ordenação.
