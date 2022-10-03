-- 1. Criar as tabelas do modelo ER indicado abaixo.
create table RACA
(  
  IDRaca Int Not null identity,
  Nome Varchar(100) Not null,
  Descricao Varchar(500),
  Origem Varchar(100) Not null,
  Perdido datetime,
  CONSTRAINT PKIDRaca PrimaRy key (IDRaca)
  )

create table Habilidade 
(
 IDHabilidade Int Not null identity,
 Nome Varchar (200) Not null,
 CONSTRAINT PKIDHabilidade  PrimaRy key (IDHabilidade)
)

create table Classe
(
IDClasse Int Not null identity,
Nome Varchar (100) Not null,
Caracteristicas Varchar (1000),
IDHabilidade int Not null,
CONSTRAINT PKIDClasse PrimaRy key (IDClasse),
CONSTRAINT FKIDHabilidade Foreign key (IDHabilidade) references Habilidade (IDHabilidade)
)

create table Personagem 
(
IDPersonagem int Not null identity,
Nome Varchar (100) Not null,
Descricao Varchar (500) Not null,
Datadenascimento datetime Not null ,
IDRACA int Not null,
IDClasse int Not null,
CONSTRAINT PKPersonagem PrimaRy key (IDPersonagem),
CONSTRAINT FKIDRACA Foreign key (IDRACA) references RACA (IDRaca),
CONSTRAINT FKIClasse Foreign key (IDClasse) references Classe(IDClasse)
)

-- 2. Adicionar na tabela Habilidade o campo Poder do tipo int
ALTER TABLE Habilidade ADD Poder int

-- 3. Alterar o campo Características da tabela Classe para varchar(500).
ALTER TABLE Classe ALTER COLUMN Caracteristicas varchar(500)

-- 4. Excluir o campo Perdido da tabela Raça
ALTER TABLE RACA DROP COLUMN Perdido

-- 5. Inserir pelo menos 3 (três) linhas de dados para cada uma das tabelas (atenção para a ordem de inserção nas tabelas).
INSERT INTO RACA values ('Pitbull', null, 'Asiatico');
INSERT INTO RACA values ('Pastor Alemã', 'Porte grande', 'Alemanha');
INSERT INTO RACA values ('Husck', 'Russo', 'Alasca');
select * from RACA

INSERT INTO Habilidade values ('Morder', 100);
INSERT INTO Habilidade values ('Correr', null);
INSERT INTO Habilidade values ('Armado', 50);
select * from Habilidade

INSERT INTO Classe values ('DOG', 'Bravo', 1)
INSERT INTO Classe values ('Cachorro', 'Docio', 2)
INSERT INTO Classe values ('Cao', 'Bebado', 3)
INSERT INTO Classe values ('Gato', null, 3)
select * from Classe

INSERT INTO Personagem values ('Jorge', 'Park', GETDATE(), 1, 3)
INSERT INTO Personagem values ('Rex', 'LEGAL', GETDATE(), 2, 1)
INSERT INTO Personagem values ('Bambi', 'Prisidiario', GETDATE(), 3, 2)
select * from Personagem

-- 6. Atualizar as Caracteristicas da tabela Classe para “Características Gerais” quando o seu valor estiver null
UPDATE Classe SET Caracteristicas = 'Caracteristicas Gerais' where Caracteristicas is null
select * from Classe

-- 7. Excluir todos os Personagens com ano de nascimento (DataNascimento) entre 1970 e 1990
DELETE Personagem where Datadenascimento BETWEEN 1970 AND 1990 
select * from Personagem

-- 8. Selecionar todas as informações da tabela Personagem.
select * from Personagem

-- 9. Selecionar o Nome e Poder da tabela Habilidade quando o valor do poder estiver entre 0 e 100.
select Nome, Poder from Habilidade where Poder BETWEEN 0 AND 100

-- 10. Selecionar o Nome Descrição e Data de Nascimentos da tabela Personagem quando o nome possuir “Big” (em qualquer parte do texto) e o ano de nascimento estiver entre 1990 e 2000
select Nome, Descricao, Datadenascimento from Personagem where Nome like '%big%' and Datadenascimento BETWEEN 1990 AND 2000