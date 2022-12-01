-- Exibir a quantidade de modelos cadastrados (count)
select COUNT(*) QtdModelo from Modelo 

-- Exibir a quantidade de veículos cadastrados (count)
select COUNT(*)	QtdeVeiculo from Veiculo

-- Exivir a soma dos valores de todos os veículos (sum)
select SUM(valor) from Veiculo

-- Exibir a media de valores de todos os veículos (avg)
select AVG(valor) from Veiculo

-- Exibir o valor do veiculo mais barato
select MAX(valor) MaisCaro, MIN(valor) MaisBarato from Veiculo

-- Exibir a soma dos valores dos veículos frabricados entre 2020 e 20222 (sum + where)
select SUM(valor) from Veiculo where AnoFabricacao between 2020 and 2022

-- Exibir a media dos vlores dos veiculos fabricados entre 2000 e 2019 (avg + where)
select AVG(valor) from Veiculo where AnoFabricado between 2000 and 2019

-- Exibir a soma do valor dos veiculos agrupados por ano de fabricação (sum + group by)
select AnoFabricacao, SUM(valor) SomaPorAno from Veiculo group by AnoFabricacao

-- Exibir valor médio dos veículos agrupados por ANo de Fabricação (avg + group by)
select AnoFabricacao, AVG(valor) MédiaPorAno from Veiculo  group by AnoFabricacao

-- Exibir a quantidade de veículo agrupados por Ano de Fabricação (cout + group by)
select AnoFabricacao, COUNT(*) Qtde from Veiculo  group by AnoFabricacao