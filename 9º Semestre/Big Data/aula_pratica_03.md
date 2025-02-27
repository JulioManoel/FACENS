# Aula 03

# Instalando o MongoDB Community com Docker

Você pode executar o MongoDB Community Edition como um contêiner Docker usando a imagem oficial do MongoDB Community. O uso de uma imagem Docker para executar sua implantação MongoDB é útil para:

- Configurar rapidamente uma implantação.
- Auxiliar na gestão de arquivos de configuração.
- Testar diferentes recursos em várias versões do MongoDB.

## Sobre esta Tarefa

Este tutorial descreve as instruções de instalação do Docker para a edição Community do MongoDB. A imagem Docker do MongoDB Enterprise, em conjunto com o MongoDB Kubernetes Operator, são recomendadas para implantações de produção. Para instruções empresariais, consulte a instalação do MongoDB Enterprise com Docker.

Este procedimento utiliza a imagem oficial da comunidade mongo, mantida pela MongoDB. Uma descrição completa do Docker está além do escopo desta documentação.

### Antes de Começar

Antes de executar um contêiner Docker MongoDB Community, você deve instalar o Docker.

## Procedimento

### 1. Baixar a Imagem Docker do MongoDB

```bash
docker pull mongodb/mongodb-community-server
```

### 2. Executar a Imagem como um Contêiner

```bash
docker run --name mongo -d mongodb/mongodb-community-server:latest
```

### 3. Verificar se o Contêiner está em Execução

Para verificar o status do contêiner Docker, execute o seguinte comando:

```bash
docker container ls
```

### 4. Conectar ao Deployment do MongoDB com mongosh

Abra uma instância interativa do contêiner mongo e conecte-se ao deployment com mongosh.

```bash
docker exec -it mongo mongosh
```

### 5. Validar sua Implantação

Para confirmar se a instância do MongoDB está em execução, execute o comando Hello:

```bash
db.runCommand(
   {
      hello: 1
   }
)
```

O resultado deste comando retornará um documento descrevendo sua implantação mongodb.

### CRUD

# Criar uma coleção chamada "agenda"

```bash
db.createCollection("agenda")
```

# Inserir dados na coleção "agenda"

```bash
db.agenda.insertOne({ nome: "John Doe", idade: 30, cidade: "Gotham" })
```

#### Leitura (Read)

Listar todas as coleções em um banco de dados

```bash
show collections
```

Consultar todos os documentos em uma coleção

```bash
db.agenda.find()
```

Consultar com critérios específicos

```bash
db.agenda.find({ cidade: "Gotham"  })
```

#### Escrita (Create)

Inserir um único documento em uma coleção

```bash
db.agenda.insertOne({ nome: "Clark", idade: 30, cidade: "Smallville" })
```

Inserir múltiplos documentos em uma coleção

```bash
db.agenda.insertMany([{ nome: "valor" }, { nome: "valor" }])
```

#### Atualização (Update)

Atualizar um único documento

```bash
db.agenda.updateOne({ nome: "Clark" }, { $set: { nome: "Clark Kent" } })
```

Atualizar múltiplos documentos

```bash
db.agenda.updateMany({ nome: "valor" }, { $set: { nome: "novoValor" } })
```

#### Exclusão (Delete)

Excluir um único documento

```bash
db.agenda.deleteOne({ cidade: "Smallville" })
```

Excluir múltiplos documentos

```bash
db.agenda.deleteMany({ nome: "novoValor" })
```

## Exercício Prático: Explorando o MongoDB com Docker

1. **Criação de Coleção e Inserção de Dados:**

   - Crie uma coleção chamada "alunos" no MongoDB.
   - Insira pelo menos 5 documentos na coleção, representando informações fictícias de alunos (nome, idade, curso, etc.).

2. **Transformações e Consultas:**

   - Realize as seguintes operações:
     - **Atualização:** Modifique a idade de um aluno específico na coleção.
     - **Leitura:** Consulte todos os alunos na coleção.
     - **Consulta Avançada:** Execute uma consulta para encontrar alunos com idade superior a 25 anos.
     - **Remoção:** Remova um aluno da coleção.

3. **Coleta de Dados:**
   - Colete e registre os resultados de suas operações em um documento ou arquivo.

**Documentos de Exemplo:**

```json
{
  "nome": "João Silva",
  "idade": 22,
  "curso": "Engenharia de Software"
}

{
  "nome": "Maria Oliveira",
  "idade": 28,
  "curso": "Ciência da Computação"
}

{
  "nome": "Carlos Santos",
  "idade": 24,
  "curso": "Sistemas de Informação"
}

{
  "nome": "Ana Souza",
  "idade": 20,
  "curso": "Design Digital"
}

{
  "nome": "Pedro Rocha",
  "idade": 26,
  "curso": "Análise e Desenvolvimento de Sistemas"
}
```
