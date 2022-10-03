-- Desenvolver uma consulta para exibir o Nome e Tipo do Modelo e o respectivo Nome do Fabricante
SELECT A.Nome NomeModelo, A.Tipo, B.Nome NomeFabricante from Modelo A INNER JOIN Fabricante B ON A.IDFabricante = B.IDFabricante

-- Desenvolver uma consulta para exibir o Proprietário e Placa do Veículo e o Nome do Modelo.
SELECT A.Proprietario, A.Placa, B.Nome NomeModelo from Veiculo A inner join Modelo B ON A.IDModelo = B.IDModelo

-- Desenvolver uma consulta para exibir o Nome do Fabricante e a quantidade de Modelos cadastrados.
select B.Nome NomeFabricante, COUNT(*) QtdModelos from Modelo A inner join Fabricante B ON A.IDFabricante = B.IDFabricante group by B.Nome order by B.Nome

-- Desenvolver uma consulta para exibir o Nome do Proprietário, Nome do Modelo e Nome do Fabricante
select A.Proprietario, B.Nome NomeModelo, C.Nome NomeFabricante from Veiculo A inner join Modelo B ON A.IDModelo = B.IDModelo inner join Fabricante C ON B.IDFabricante = C.IDFabricante

-- Desenvolver uma consulta para exibir o Nome e Tipo de todos os Modelo e o respectivo Nome do Fabricante quando existirem.
select A.Nome NomeModelo, B.Nome NomeFabricante from Modelo A left join Fabricante B ON A.IDFabricante = B.IDFabricante

-- Desenvolver uma consulta para exibir o Nome de todos os Fabricante e a quantidade de Modelos cadastrados de cada um deles.
select B.Nome NomeFabricante, COUNT(A.IDFabricante) QtdModelo from Modelo A right join Fabricante B ON A.IDFabricante = B.IDFabricante group by B.Nome order by B.Nome
