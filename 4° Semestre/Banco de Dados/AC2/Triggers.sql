--1. Criar a tabela do Log chamada LogFull conforme detalhes descritos. 
CREATE TABLE LogFull
(
	IDLogFull int Primary Key identity not null,
	Tabela varchar(255) not null,
	Operacao varchar(255) not null,
	Detalhes varchar(1000) not null,
	DataEvento datetime not null
)
GO

--2. Criar uma Trigger que no momento da inserção do Personagem verifique se a idade é maior ou  igual  a  18  anos  (verificar  através  do  campo  DataNascimento).  Caso  não  seja  a  operação deve ser cancelada (rollback). 
CREATE or ALTER TRIGGER tgrMaiorIdade
ON Personagem
AFTER INSERT
AS
BEGIN
	DECLARE @anoAtual INT
	SET @anoAtual = YEAR(GETDATE())
	DECLARE @anoNascimento INT
	SELECT @anoNascimento = YEAR(Datadenascimento) FROM INSERTED
	IF((@anoAtual-@anoNascimento) < 18)
	BEGIN
		RAISERROR('Cadastro somente de Personagens com no minimo 18 anos', 16, 1)
		ROLLBACK
	END
END
GO

INSERT INTO Personagem VALUES ('Astoufo', 'Cao chato', DATEFROMPARTS(2003, 06, 30), 2, 3)
SELECT * FROM Personagem
 
--3. Criar  um  Trigger  para  gravar  na  tabela  LogFull  as  informações  referentes  a inserção realizada na tabela Personagem. O campo detalhes deve conter o Nome do Personagem, Nome da Raça, Nome da Classe e Nome da Habilidade. 
CREATE or ALTER TRIGGER tgrLogFullInsertPersonagem
ON Personagem
AFTER INSERT
AS
BEGIN
	DECLARE @nomePersonagem varchar(100)
	DECLARE @nomeRaca varchar(100)
	DECLARE @nomeClasse varchar(100)
	DECLARE @nomeHabilidade varchar(200)
	SELECT
		@nomePersonagem = A.Nome, 
		@nomeRaca = B.Nome,
		@nomeClasse = C.Nome,
		@nomeHabilidade = D.Nome
	FROM
		INSERTED A INNER JOIN RACA B 
			ON A.IDRACA = B.IDRaca 
		INNER JOIN  Classe C
			ON A.IDClasse = C.IDClasse 
		INNER JOIN Habilidade D
			ON C.IDHabilidade = D.IDHabilidade
	INSERT INTO LogFull (Tabela, Operacao, Detalhes, DataEvento) 
		VALUES ('Personagens', 'INSERT', CONCAT(@nomePersonagem, ' ', @nomeRaca, ' ', @nomeClasse, ' ', @nomeHabilidade), GETDATE())
END
GO

INSERT INTO Personagem VALUES ('Peka', 'Escudeiro', DATEFROMPARTS(2001, 09, 03), 3, 1)
SELECT * FROM Personagem
SELECT * FROM LogFull

--4. Existe a possibilidade de criar o item 2 e 3 em uma única Trigger. Se sim, como ela ficaria? 
CREATE or ALTER TRIGGER tgrLogFullInsertPersonagem
ON Personagem
AFTER INSERT
AS
BEGIN
	DECLARE @nomePersonagem varchar(100)
	DECLARE @nomeRaca varchar(100)
	DECLARE @nomeClasse varchar(100)
	DECLARE @nomeHabilidade varchar(200)
	SELECT
		@nomePersonagem = A.Nome, 
		@nomeRaca = B.Nome,
		@nomeClasse = C.Nome,
		@nomeHabilidade = D.Nome
	FROM
		INSERTED A INNER JOIN RACA B 
			ON A.IDRACA = B.IDRaca 
		INNER JOIN  Classe C
			ON A.IDClasse = C.IDClasse 
		INNER JOIN Habilidade D
			ON C.IDHabilidade = D.IDHabilidade
	INSERT INTO LogFull (Tabela, Operacao, Detalhes, DataEvento) 
		SELECT
			'Personagens',
			'INSERT',
			A.Nome + ' ' + B.Nome + ' ' + C.Nome + ' ' + D.Nome,
			GETDATE()
		FROM
			INSERTED A INNER JOIN RACA B
				ON A.IDRACA = B.IDRaca
			INNER JOIN Classe C
				ON A.IDClasse = C.IDClasse
			INNER JOIN Habilidade D
				ON C.IDHabilidade = D.IDHabilidade
END
GO

INSERT INTO Personagem VALUES 
('Peka', 'Escudeiro', DATEFROMPARTS(2001, 09, 03), 3, 1),
('Yugi', 'Jogador', DATEFROMPARTS(2000, 12, 23), 1, 2)
SELECT * FROM Personagem
SELECT * FROM LogFull

--5. Criar  uma  Trigger  para  gravar  na  tabela  LogFull  todas  as  alterações  realizadas  na  tabela Raça. No campo Detalhes dever conter o valor antigo e atual do Nome e Origem. 
CREATE or ALTER TRIGGER tgrUpdadeRaca
ON RACA
AFTER UPDATE
AS 
BEGIN
	INSERT INTO LogFull (Tabela, Operacao, Detalhes, DataEvento)
		SELECT
			'Raca',
			'UPDATE',
			B.Nome + '-' + A.Nome + ' ' + B.Origem + '-' + A.Origem,
			GETDATE()
		FROM INSERTED A INNER JOIN DELETED B ON A.IDRaca = B.IDRaca
END
GO

UPDATE RACA SET Nome = 'Isca' WHERE IDRaca = 2
SELECT * FROM RACA
SELECT * FROM LogFull

--6. Criar  uma  Trigger  para  gravar  na  tabela  LogFull  todas  as  exclusões  realizadas  na  tabela Habilidade.  No  campo  Detalhes  deve  conter  o  ID,  Nome  e  o  valor  do  Poder  que  está  sendo excluído. 
CREATE or ALTER TRIGGER tgrDeleteHabilidade
ON Habilidade
AFTER DELETE
AS
BEGIN
	INSERT INTO LogFull (Tabela, Operacao, Detalhes, DataEvento)
		SELECT
			'Habilidade',
			'Delete',
			CONCAT(IDHabilidade, ' ', Nome, ' ', Poder),
			GETDATE()
		FROM DELETED
END
GO

INSERT INTO Habilidade VALUES ('Bola de Fogo', 10)
DELETE FROM Habilidade WHERE IDHabilidade = 1004
SELECT * FROM Habilidade
SELECT * FROM LogFull