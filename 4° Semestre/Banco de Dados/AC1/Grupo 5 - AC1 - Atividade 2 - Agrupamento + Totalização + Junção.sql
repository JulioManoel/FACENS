--1. Criar uma consulta para exibir a quantidade de Habilidades cadastradas. 
select COUNT(*) QtdHabilidade from Habilidade

--2. Criar uma consulta para exibir a Data de Nascimento do Personagem mais velho e mais novo. 
select MAX(Datadenascimento) MaisVelho, MIN(Datadenascimento) MaisNovo from Personagem

--3. Criar uma consulta para exibir o Nome da Classe e a quantidade de personagens associados a cada uma delas.
select A.Nome NomeClasse, COUNT(*) PersonagensAssociados from Classe A inner join Personagem B on A.IDClasse = B.IDClasse group by A.Nome order by A.Nome

--4.-Criar  uma  consulta  para  exibir  o  Nome  de  TODAS  as  Raças  e  a  quantidade  de  personagens associadas a cada uma delas. Quando a raça não estiver associada a nenhum personagem deve ser exibido o valor 0 (zero). 
select A.Nome NomeRaça, COUNT(A.IDRaca) PersonagensAssociados from RACA A left join Personagem B ON A.IDRaca = B.IDRACA group by A.Nome order by A.Nome

--5. Criar uma consulta para exibir o Nome da classe e o valor médio dos seus poderes. Somente devem ser exibidas as classes que o valor médio do poder for maior ou igual a 100. 
select A.Nome NomeClasse, AVG(B.Poder) MédiaPoder from Classe A inner join Habilidade B ON A.IDHabilidade = B.IDHabilidade group by A.Nome having AVG(B.Poder) >= 100 order by A.Nome

--6. Criar uma consulta para exibir o Nome da classe e a soma do valor dos seus poderes. Somente devem ser exibidas as classes cuja soma dos poderes esteja entre 150 e 250. 
select A.Nome NomeClasse, SUM(B.Poder) from Classe A inner join Habilidade B ON A.IDHabilidade = B.IDHabilidade group by A.Nome having SUM(B.Poder) between 150 AND 250

--7. Criar uma consulta para exibir o Nome e Data de Nascimento do Personagem, o Nome da sua Raça, o Nome da sua Classe e o Nome da sua Habilidade. 
select A.Nome NomePersonagem, A.Datadenascimento, B.Nome NomeRaca, C.Nome NomeClasse, D.Nome NomeHabilidade from Personagem A inner join RACA B ON A.IDRACA = B.IDRaca inner join Classe C ON A.IDClasse = C.IDClasse inner join Habilidade D ON C.IDHabilidade = D.IDHabilidade