CREATE DATABASE BD_JOIN
Go

USE BD_JOIN
GO

CREATE TABLE Modelo
(
	IDModelo int not null identity,
	Nome varchar(200) not null,
	Descricao varchar(500)
	--IDFabricante int REFERENCES Fabricante(IDFabricante),
	CONSTRAINT PKIDModelo PRIMARY KEY (IDModelo)
)
go

CREATE TABLE Veiculo
(
	IDVeiculo int not null identity,
	Proprietario varchar(200) not null,
	Placa varchar(50) not null,
	DataCompra datetime,
	--AnoFrabricacao	int not null,
	IDModelo int not null,
	--Cor varchar(50),
	Valor numeric(18,2) not null,
	CONSTRAINT PKIDVeiculo PRIMARY KEY (IDVeiculo),
	CONSTRAINT FKVeiculoModelo FOREIGN KEY (IDModelo) REFERENCES Modelo(IDModelo)
)
go
--
--Tabela Modelo
--Adicionar Colunas
ALTER TABLE Modelo ADD NumeroLugares int 
go
ALTER TABLE Modelo ADD Tipo varchar(100)
go

--Adicionar Consistência
ALTER TABLE Modelo ADD CHECK (Tipo in ('Sedan', 'SUV', 'Hatch', 'Outros', null))
go

--Valor Padrão - Tipo igual Outros
ALTER TABLE Modelo ADD CONSTRAINT defLugares DEFAULT 5 FOR NumeroLugares
go


--Tabela Veiculo
--Adicionar Colunas
ALTER TABLE Veiculo ADD VouApagar numeric(18,2)
go
ALTER TABLE Veiculo ADD AnoFabricacao int
go
ALTER TABLE Veiculo ADD Cores varchar(10)
go

--Adicionar Consistência
ALTER TABLE Veiculo ALTER COLUMN AnoFabricacao int not null
go
--Tamanho da Coluna
ALTER TABLE Veiculo ALTER COLUMN Cores varchar(50)
go
--Excluir coluna
ALTER TABLE Veiculo DROP COLUMN VouApagar
go
--Renomear Coluna
SP_RENAME 'Veiculo.Cores', Cor

--------------------
INSERT INTO Modelo (Nome, NumeroLugares, Tipo) VALUES
    ('HB20s', 5, 'Sedan'),
    ('HB20', 5, 'Hatch'),
    ('Porsche Spyder', 2, 'Outros'),
    ('Fiesta',  null, 'Hatch'),
    ('Onix', null, 'Hatch'),
    ('TCross', null, 'SUV'),
    ('Tiguan', 7, 'SUV')
go
--Nome, Descricao, NumeroLugares, Tipo
INSERT INTO Modelo VALUES
    ('C3', null, null, 'Hatch'),
    ('Gol', 'Geracao 3', 5, null)


SET DATEFORMAT DMY
go
INSERT INTO Veiculo (Proprietario, Placa, DataCompra, IDModelo, Valor, AnoFabricacao) VALUES
    ('Anna Clara', 'ABC1234', '28-10-2013', 1, 50000, 2013),
    ('Enzo Gabriel', 'DEF1234', '27-07-2012', 1, 20000, 2012),
    ('Geovana', 'GHI5678', '31-07-2013', 2, 40000,  2013),
    ('Manuela', 'ABC9090', '11-12-2013', 3, 10000, 2012)
go
INSERT INTO Veiculo (Proprietario, Placa, IDModelo, Valor, AnoFabricacao) VALUES
    ('Bernardo', 'BER2301', 4, 50000, 2020)

INSERT INTO Veiculo VALUES
    ('Lucas', 'LUC9988', '14-05-2020', 2, 25000, 2020, 'Branca'),
    ('Murilo', 'MUU5334', '20-02-2021', 3, 35000, 2021, 'Azul'),
    ('Marcelo', 'MAH2376', '05-04-2022', 2, 50000, 2022, 'Cinza')
go


------------------------
--Tabela Fabricante
CREATE TABLE Fabricante
(
	IDFabricante int not null identity,
	Nome varchar(200) not null,
	Descricao varchar(500),
	Cidade varchar(150) not null,
	Estado varchar(10) not null,
	CONSTRAINT PKIDFabricante PRIMARY KEY (IDFabricante)
)
go

--Inclusão de Fabricantes
INSERT INTO Fabricante (Nome, Cidade, Estado) VALUES
   ('Hyundai', 'Piracicaba', 'SP'), --1	Creta, IX35
   ('Kia', 'Belo Horizonte', 'MG'), --2	Sportage
   ('Caoa Chery', 'Anápolis', 'GO'), --3	Tiggo, Arrizo
   ('Chevrolet', 'São Caetano', 'SP'), --4	Cruze, Tracker, Spin
   ('Ford', 'São Paulo', 'SP'), --5	Ranger
   ('Fiat', 'São Paulo', 'SP'), --6	Palio
   ('Citroen', 'Niterói', 'RJ'),
   ('Toyota', 'Itu', 'SP'),
   ('Jeep', 'Uberlândia', 'MG')
go
--SELECT * FROM Fabricante

--Criação da Coluna IDFabricante na Tabela Modelo
ALTER TABLE Modelo ADD IDFabricante INT
go
--Criação da Foreign Key de Fabricante na Tabela Modelo
ALTER TABLE Modelo ADD CONSTRAINT FKModeloFabricante FOREIGN KEY (IDFabricante) REFERENCES Fabricante(IDFabricante)
go
--Inclusão de Novos Modelos com Fabricante
INSERT INTO Modelo (Nome, Tipo, IDFabricante) VALUES
    ('Creta', 'SUV', 1), --10
    ('IX35', 'SUV', 1), --11
    ('Sportage', 'SUV', 2), --12
    ('Tiggo', 'Outros', 3), --13
    ('Arrizo', 'Hatch', 3), --14
    ('Cruze', 'Hatch', 4), --15
    ('Tracker', 'SUV', 4), --16
    ('Spin', 'Sedan', 4), --17
    ('Ranger', 'Outros', 5), --18
    ('Palio', 'Hatch', 6) --19
go
--Inclusão de Novos Veiculos 
INSERT INTO Veiculo (Proprietario, Placa, DataCompra, IDModelo, valor, AnoFabricacao, Cor) VALUES
    ('Bella', 'AAA111', GETDATE(), 10, 25000, 2020, 'Preto'),
    ('Larissa', 'BBB222', GETDATE(), 11, 30000, 2020, 'Branco'),
    ('Zoe', 'CCC3333', GETDATE(), 12, 35000, 2020, 'Branco'),
    ('Gabriela', 'DDD4444', GETDATE(), 13, 40000, 2020, 'Prata'),
    ('Benjamin', 'EEE5555', GETDATE(), 14, 45000, 2020, 'Prata'),
    ('Bento', 'FFF6666', GETDATE(), 15, 50000, 2020, 'Branco'),
    ('Davi', 'GGG7777', GETDATE(), 16, 55000, 2020, 'Preto')
go