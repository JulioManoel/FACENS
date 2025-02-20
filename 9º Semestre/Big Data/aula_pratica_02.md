# Aula 01

## Docker

Breve Explicação sobre o Docker
O Docker é uma plataforma de código aberto que permite a automação do processo de implantação de aplicativos em contêineres. Contêineres são unidades leves e portáteis que incluem tudo o que é necessário para executar um software, incluindo o código, bibliotecas e dependências. Essa abordagem simplifica a implementação e garante consistência entre diferentes ambientes. Durante o curso, utilizaremos o Docker para configurar ambientes de maneira rápida e eficiente.

## Instalação do Docker

### Windows e Mac

1. Acesse [Docker Desktop](https://www.docker.com/products/docker-desktop) e siga as instruções de instalação.

### Linux

1. Execute os seguintes comandos no terminal:
   ```bash
   sudo apt-get update
   sudo apt-get install docker.io
   sudo systemctl start docker
   sudo systemctl enable docker
   ```

## Instalação do Docker Compose

O Docker Compose é uma ferramenta que permite definir e executar aplicativos Docker multi-container de maneira fácil. Abaixo estão as instruções para instalar o Docker Compose em diferentes sistemas operacionais.

### Linux:

1. **Baixar o Docker Compose:**

   ```bash
   sudo curl -L "https://github.com/docker/compose/releases/latest/download/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
   ```

2. **Tornar Executável:**

   ```bash
   sudo chmod +x /usr/local/bin/docker-compose
   ```

3. **Verificar a Instalação:**
   ```bash
   docker-compose --version
   ```

### macOS:

1. **Instalar via Homebrew:**

   ```bash
   brew install docker-compose
   ```

2. **Verificar a Instalação:**
   ```bash
   docker-compose --version
   ```

### Windows:

1. **Baixar o Instalador:**
   Baixe o instalador do Docker Compose no [site oficial](https://github.com/docker/compose/releases).

2. **Instalar:**
   Execute o instalador baixado e siga as instruções.

3. **Verificar a Instalação:**
   Abra o terminal ou PowerShell e digite:
   ```bash
   docker-compose --version
   ```

Após a instalação, você deve ver a versão do Docker Compose instalada no seu sistema. Agora, você está pronto para usar o Docker Compose para orquestrar aplicativos Docker complexos.

Lembre-se de que pode ser necessário reiniciar o terminal ou o shell após a instalação para que as alterações tenham efeito.

**Observação:** As instruções podem variar com base nas atualizações do Docker Compose, por isso, recomenda-se verificar a documentação oficial para informações mais recentes: [Docker Compose - Install](https://docs.docker.com/compose/install/).

# Imagens Docker e Comandos Úteis

## Imagens Docker

As imagens Docker são pacotes leves e executáveis que contêm tudo o que é necessário para executar um aplicativo, incluindo o código, bibliotecas, dependências e configurações do ambiente. Elas são a base para a criação de contêineres.

### Gerenciamento de Imagens

Listar Imagens.

```bash
docker images
```

## Comandos Úteis

### 1. Criar um Container

Cria um novo container com o nome especificado a partir da imagem.

```bash
docker create --name meu-container minha-imagem
```

### 2. Subir um Container

Inicia um container que foi criado anteriormente.

```bash
docker start meu-container
```

### 3. Desligar um Container

Para a execução de um container sem removê-lo.

```bash
docker stop meu-container
```

### 4. Baixar uma Imagem

Faz o download de uma imagem do Docker Hub ou de outro registro.

```bash
docker pull nome-da-imagem
```

### 5. Entrar num Container por Linha de Comando

Permite a entrada interativa em um container.

```bash
docker exec -it meu-container /bin/bash
```

## Manipulação de Arquivos no Contêiner

### Copiar Arquivos do Host para o Contêiner

Para copiar arquivos do seu sistema local para o contêiner, utilize o comando `docker cp`. Substitua `arquivo.txt` pelo nome do arquivo que deseja copiar e `nome_do_container:/caminho/destino/` pelo destino desejado dentro do contêiner.

```bash
docker cp arquivo.txt nome_do_container:/caminho/destino/
```

### Copiar Arquivos do Contêiner para o Host

Para copiar arquivos do contêiner de volta para o seu sistema local, use novamente o comando`docker cp`. Substitua `nome_do_container:/caminho/origem/arquivo.txt` pelo caminho do arquivo dentro do contêiner e . representa o diretório atual no seu sistema local.

```bash
docker cp nome_do_container:/caminho/origem/arquivo.txt .
```

Observação: Lembre-se de substituir "meu-container" e "minha-imagem" pelos nomes reais que serão utilizados nas aulas.

## Funcionalidades

- **Portabilidade:** As imagens garantem que o ambiente seja consistente em diferentes máquinas.

- **Eficiência:** Os contêineres compartilham recursos do sistema operacional host, tornando-os leves e eficientes.

- **Isolamento:** Cada contêiner é isolado, garantindo que as dependências não entrem em conflito com o ambiente host ou com outros contêineres.

- **Reprodutibilidade:** As imagens e contêineres são definidos por código, permitindo a reprodução consistente do ambiente em qualquer lugar.

- **Facilidade de Uso:** Os comandos Docker simplificam a criação, execução e gerenciamento de contêineres.

# Exercício Prático com Docker

**Objetivo:**
Familiarizar-se com o Docker, criar e gerenciar contêineres.

**Instruções:**

1. **Instalação do Docker:**

   - Se ainda não tiver o Docker instalado, siga as instruções para instalação em [Docker Installation Guide](https://docs.docker.com/get-docker/).

2. **Verificação da Instalação:**

   - Abra um terminal e execute o comando:
     ```bash
     docker --version
     ```
     Certifique-se de que o Docker foi instalado corretamente.

3. **Baixando e Executando uma Imagem:**

   - Baixe a imagem oficial do Ubuntu e crie um contêiner:
     ```bash
     docker run -it ubuntu /bin/bash
     ```
     Isso abrirá um shell interativo dentro do contêiner Ubuntu.

4. **Dentro do Contêiner:**

   - Dentro do contêiner, execute comandos como se estivesse em um ambiente Ubuntu normal.
     ```bash
     apt update
     apt install -y wget
     wget https://instructure-uploads.s3.amazonaws.com/account_137200000000000001/attachments/1898682/Facens_logo360%20x%20140.png
     ```

5. **Sair e Retornar ao Contêiner:**

   - Saia do contêiner, mantendo-o em execução em segundo plano:

     ```bash
     exit
     ```

   - Liste os contêineres em execução:

     ```bash
     docker ps
     ```

   - Retorne ao contêiner em execução:
     ```bash
     docker exec -it <ID_do_Conteiner> /bin/bash
     ```

6. **Persistência de Dados:**

   - Crie um arquivo dentro do contêiner e verifique se ele persiste após a saída e reinício do contêiner.

7. **Limpeza:**

   - Remova os contêineres que não estão em uso:

     ```bash
     docker ps -a
     docker rm <ID_do_Conteiner>
     ```

   - Remova as imagens que não estão em uso:
     ```bash
     docker images
     docker rmi <ID_da_Imagem>
     ```
