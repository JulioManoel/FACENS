# Docker
Rodando no Ubuntu 22.4


## Instalação

### Configurar o repositório
1. Atualize o `apt` índice do pacote e instale os pacotes para permitir `apt` o uso de um repositório por HTTPS:
```bash
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg
```
2. Adicione a chave GPG oficial do Docker:
```bash
sudo install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
sudo chmod a+r /etc/apt/keyrings/docker.gpg
```

3. Use o seguinte comando para configurar o repositório:
```bash
echo \
  "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

### Instalar Docker Engine
1. Atualize o `apt` índice do pacote:
```bash
sudo apt-get update
```

2. Instale o Docker Engine, o containerd e o Docker Compose.
```bash
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

3. Verifique se a instalação do Docker Engine foi bem-sucedida executando a `hello-world` imagem.
```bash
sudo docker run hello-world
```

## Comandos Docker
Rodar um contaneir
```bash
sudo docker run <image>
```

Rodar um contaneir em background
```bash
sudo docker run -d <image>
```

Rodar um container com uma porta
```bash
sudo docker run -p 8080:80 <image>
```

Rodar um container definindo o nome
```bash
sudo docker run --name <nome> <image>
```

Exibir todos os containers que estção rodando
```bash
sudo docker ps
```

Exibir todos os containers
```bash
sudo docker ps -a
```

Excluir um container
```bash
sudo docker rm <CONTAINER ID>
```

Exibir todas as imagens já instaladas
```bash
sudo docker images
```

Apagar Image do Docker
```bash
sudo docker rmi <image>
```

Criar uma Image
```bash
sudo docker build -t <name> .
```

## Criando Imagem Docker

1. Crie um novo diretório para image

2. Dentro do diretório, crie um arquivo chamado `app.js` e adicione o seguinte código ao arquivo:
```JavaScript
console.log('Hello World')
```

3. Crie um arquivo `dockerfile` e adicione o seguintes comandos ao arquivo:
```docker
# Use a imagem do Node.js como base
FROM node:14

# Copie o arquivo index.js para o conteiner
COPY index.js .

# Execute o comando "node index.js" ao iniciar o conteiner
CMD ["node", "index.js"]
```

4. Abra um terminal e navegue até o diretório do projeto. 

5. Construa a imagem Docker.
```bash
sudo docker build -t <nomeImage> .
```

6. Após a construção da imagem, execute o conteiner.
```bash
sudo docker run meu-projeto
```

Irá ficar assim:
![Alt text](setupDocker.png)

