/*Declare - declara uma variavel*/
/*Sendo que o nome da variavel sempre tem que possuir no inicio um @*/
DECLARE @String1 char(10) = 'Hello'
DECLARE @String2 varchar(10) = 'World'

SELECT @String1 + @String2
SELECT LEN(@String1), LEN(@String2) /*Tamanho do texto*/
SELECT DATALENGTH(@String1), DATALENGTH(@String2) /*Tamanho do texto alocado na memoria*/