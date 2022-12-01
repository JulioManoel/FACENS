--1. Criar uma Stored Procedure que recebe via parâmetro o nome do personagem e retorna (via select) o Nome do Personagem, Ano de Nascimento do Personagem, Nome da Raça, Nome da Classe e Nome da Habilidade
CREATE or ALTER PROCEDURE dadosPersonagens 
	@nome varchar(100)
AS 
BEGIN
	SELECT 
		A.Nome NomePersonagem,
		B.Nome NomeRaca,
		C.Nome NomeClasse,
		D.Nome NomeHabilidade
	FROM
		Personagem A INNER JOIN RACA B
			ON A.IDRACA = B.IDRaca
		INNER JOIN Classe C
			ON A.IDClasse = C.IDClasse
		INNER JOIN Habilidade D
			ON C.IDHabilidade = D.IDHabilidade
	WHERE A.Nome = @nome
END
GO
exec dadosPersonagens 'Jorge'

--2. Criar uma Stored Procedure que recebe via parâmetro um inteiro referente ao ano de nascimento do personagem e retorna via parâmetro de OUTPUT a quantidade de personagens que nasceram no ano informado via parâmetro.
CREATE or ALTER PROCEDURE contadorAno
	@anoNascimento int,
	@qtde int OUTPUT
AS
BEGIN
	select @qtde = COUNT(*) from Personagem where YEAR(Datadenascimento) = @anoNascimento
END
GO

declare @pessoas int
exec contadorAno 2022, @pessoas OUTPUT
select @pessoas QtdePessoas

--3. Criar uma Stored Procedure para atualizar a quantidade o valor do Poder da tabela Habilidade. Devem ser informados como parâmetros o ID da Habilidade e a quantidade de pontos a adicionar ou subtrair. Deve ser utilizado o conceito de transações para evitar que a quantidade de pontos fique negativa ou acima de 100 (cem), quando isso ocorrera operação deve ser “desfeita” e uma mensagem de erro personalizada/customizada deve ser exibida.
CREATE or ALTER PROCEDURE alterHabilidade
	@idHabilidade int,
	@valor int
AS
BEGIN TRANSACTION
	UPDATE Habilidade SET Poder += @valor WHERE IDHabilidade = @idHabilidade
	if (SELECT Poder FROM Habilidade WHERE IDHabilidade = @idHabilidade) > 100
	BEGIN
		PRINT('O poder não pode ser maior que 100')
		ROLLBACK TRANSACTION
	END
	else
	BEGIN
		if(SELECT Poder FROM Habilidade WHERE IDHabilidade = @idHabilidade) < 0
			BEGIN
			PRINT('O poder não pode ser menor que 0')
			ROLLBACK TRANSACTION
		END
		else
			COMMIT TRANSACTION
	END
GO

exec alterHabilidade 1, 10

--4. Criar uma Scalar Function que recebe como parâmetro o IDClasse e retorna à quantidade de Personagens associados/cadastrados. O parâmetro informado deve ser utilizado para filtrar o resultado.
CREATE or ALTER FUNCTION dbo.lenghtPersonagem(@idClasse INT)
RETURNS INT
AS
BEGIN
	DECLARE @numPersonagens int
	select @numPersonagens = COUNT(*) from Personagem WHERE IDClasse = 1
	RETURN @numPersonagens
END
GO

select dbo.lenghtPersonagem(2) Personagem

--5. Criar uma Table Function (Multi-Statement) que recebe como parâmetro um inteiro e conforme o valor recebido deve retornar:
--a. Valor informado 1: Nome da Classe e a quantidade de personagens associados
--b. Valor informado 2: Nome da Raça e a quantidade de personagens associados
--c. Valor informado 3: Nome da Habilidade e a quantidade de personagens associados
CREATE or ALTER FUNCTION dbo.personagensAssociados(@valor int)
RETURNS @associados TABLE(Nome varchar(200) not null, PersonagensAssociados int)
AS
BEGIN
	if (@valor) = 1
	BEGIN
		INSERT INTO @associados
			SELECT 
				B.Nome, COUNT(*) Personagens 
			FROM 
				Personagem A INNER JOIN Classe B 
					ON A.IDClasse = B.IDClasse 
		GROUP BY B.Nome
	END
	
	else if @valor = 2
	BEGIN
		INSERT INTO @associados
			SELECT 
				B.Nome, COUNT(*) Personagens 
			FROM 
				Personagem A INNER JOIN RACA B 
					ON A.IDRACA = B.IDRaca 
		GROUP BY B.Nome
	END

	else if @valor = 3
	BEGIN
		INSERT INTO @associados
			SELECT 
				C.Nome, COUNT(*) Personagens 
			FROM 
				Personagem A INNER JOIN Classe B 
					ON A.IDClasse = B.IDClasse
				INNER JOIN Habilidade C
					ON B.IDHabilidade = C.IDHabilidade
		GROUP BY C.Nome
	END
	RETURN
END
GO

select * from dbo.personagensAssociados(1)
select * from dbo.personagensAssociados(2)
select * from dbo.personagensAssociados(3)