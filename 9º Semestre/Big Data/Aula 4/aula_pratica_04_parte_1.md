# Aula 04 - Parte 1

# Introdução ao Hadoop com Docker

No mundo do Big Data, o Hadoop desempenha um papel significativo, sendo um framework open-source usado para processamento de dados em larga escala. Neste tutorial, exploraremos como instalar e executar o Hadoop em um ambiente Docker, especificamente utilizando o Docker Datanode.

## Curiosidades sobre o Hadoop

### Velocidade das Mudanças

O ecossistema do Hadoop está em constante evolução. Layouts, ferramentas e interfaces podem mudar rapidamente, exigindo atualizações frequentes em conhecimentos e práticas.

### Tendências

O Hadoop é um framework amplamente utilizado em empresas para processar grandes volumes de dados. Sua popularidade pode variar por região e organização.

### Custo

Soluções de Big Data oferecidas por grandes provedores geralmente visam empresas, resultando em custos significativos. Alternativas para estudo individual podem ser limitadas.

## Alternativa com Docker

Para facilitar os testes e reduzir requisitos de recursos, podemos usar o Docker com o repositório [docker-hive](https://github.com/big-data-europe/docker-hive). Este repositório simplifica a configuração do Hadoop.

### Passos para Instalação

1. Instale o Docker em seu computador. [Tutorial de Instalação Docker](https://github.com/EmanuelZiga/docker-tutorial/blob/main/docker-installation-guide.md).

2. Baixe o repositório [docker-hive](https://github.com/big-data-europe/docker-hive) e extraia em uma pasta de sua escolha.

3. Abra o terminal e navegue até a pasta onde o repositório foi extraído.

4. Execute o seguinte comando para iniciar os containers:

   ```bash
   docker-compose up -d
   ```

   Isso inicializará servidores como NameNode, DataNode, etc.

### Testando o Hadoop

1. Verifique se os containers estão em execução:

   ```bash
   docker ps
   ```

   Certifique-se de que os containers do Hadoop estão listados.

2. Acesse o terminal do container Datanode:

   ```bash
   docker exec -it docker-hive-datanode-1 bash
   ```

3. Liste os arquivos no HDFS:

   ```bash
   hadoop fs -ls /
   ```

4. Agora você pode utilizar comandos do Hadoop. Por exemplo, crie um diretório no HDFS:

   ```bash
   hadoop fs -mkdir /user/hive/warehouse/my_folder
   ```

5. Envie um arquivo para o HDFS:

   ```bash
   # Copie o arquivo da máquina local para o container Datanode
   docker cp local_file.txt docker-hive-datanode-1:/home

   # Copie o arquivo do container para o HDFS
   hadoop fs -copyFromLocal /home/local_file.txt /user/hive/warehouse/my_folder
   ```

6. Visualize o conteúdo do arquivo no HDFS:

   ```bash
   hadoop fs -cat /user/hive/warehouse/my_folder/local_file.txt
   ```

7. Remova um diretório do HDFS:

   ```bash
   hadoop fs -rm -r /user/hive/warehouse/my_folder
   ```

## Configuração de Múltiplos Datanodes

```bash

docker-compose --file docker-compose-3dn.yml up -d

docker cp cars.parquet datanode1:/hadoop-data
docker exec -it datanode1 /bin/bash
hadoop fs -mkdir /user/hive/cars
hadoop fs -put /hadoop-data/cars.parquet /user/hive/cars

```

## 5. Dashboard do Namenode

Acesse a dashboard do Namenode em http://localhost:9870 para monitorar o estado do Hadoop Cluster.

### Considerações sobre o Hadoop e o Docker

O Hadoop opera em um modelo de armazenamento distribuído chamado HDFS (Hadoop Distributed File System). Em contraste com bancos de dados relacionais, onde as operações ocorrem diretamente no banco, o Hadoop manipula arquivos no HDFS.

O Docker simplifica a criação de ambientes de teste, mas é importante reconhecer as complexidades subjacentes do Hadoop, projetado para lidar com grandes volumes de dados e múltiplos usuários simultaneamente.

# Exercício - Manipulação de Dados no Hadoop com Docker

Crie um diretório no HDFS:

```bash
hadoop fs -mkdir /user/hadoop/employee_data
```

Envie um arquivo JSON para o HDFS:

```bash
hadoop fs -copyFromLocal local_data.json /user/hadoop/employee_data/
```

Crie uma tabela externa no Hadoop:

```bash
hadoop fs -put local_data.json /user/hadoop/employee_data/
```

Liste os dados:

```bash
hadoop fs -cat /user/hadoop/employee_data/local_data.json
```

Busque um dado específico:

```bash
hadoop fs -cat /user/hadoop/employee_data/local_data.json | grep 'name'
```

`local_data.json` :

```json
[
  { "id": 1, "name": "Alice", "salary": 50000 },
  { "id": 2, "name": "Bob", "salary": 60000 },
  { "id": 3, "name": "Charlie", "salary": 75000 },
  { "id": 4, "name": "David", "salary": 80000 },
  { "id": 5, "name": "Eva", "salary": 55000 }
]
```
