CREATE TABLE Modelo
(
	IDModelo int not null identity, -- Ou seja a IDModelo é um inteiro que não pode ser nulo, sendo preencendo sequencialmente
	Nome varchar(200) not null, -- Ou seja nome com um tamanho no maximo de 200 caracteres e não pode ser nulo
	Descriacao varchar(500) -- Ou seja descrição com um tamanho no maximo de 500 caracteres e pode ser nulo
	CONSTRAINT PKIDModelo PRIMARY KEY (IDModelo) -- Ou seja cria uma primary key com o nome PKIDModelo com a IDModelo
)

CREATE TABLE Veiculo
(
	IDVeiculo int not null identity,
	Proprietario varchar(200) not null,
	Placa varchar(50) not null,
	DataCompra datetime,
	IDModelo int not null, -- Ou seja a IDModelo é um inteiro que não pode ser nulo
	Valor numeric(18,2) not null
	CONSTRAINT PKIDVeiculo PRIMARY KEY (IDVeiculo),
	CONSTRAINT FKVeiculoModelo FOREIGN KEY (IDModelo) REFERENCES Modelo(IDModelo)  -- Ou seja cria uma foreign key com o nome FKVeiculoModelo com a IDModelo
)

--DROP TABLE Veiculo
--DROP TABLE Modelo

CREATE TABLE ChaveComposta
(
	IDChave1 int not null,
	IDChave2 int not null,
	CONSTRAINT PKChaveComposta PRIMARY KEY (IDChave1, IDChave2)
)

ALTER TABLE ChaveComposta ADD Nome varchar(150) not null -- ALTER TABLE "nome da tabela" ADD "oq quer adiconar"

-- Alteração Modelo

ALTER TABLE Modelo ADD NumeroLugares int
ALTER TABLE Modelo ADD Tipo varchar(100)
ALTER TABLE Modelo ADD data datetime

ALTER TABLE Modelo ADD CHECK(Tipo in('Sedan', 'SUV', 'Hatch', 'Outros')) -- ALTER TABLE "nome da tabela" ADD CHECK("campo" in("restrições)) // Cria restrições
ALTER TABLE Modelo ADD CONSTRAINT padraoLugares DEFAULT 5 FOR NumeroLugares -- ALTER TABLE "nome da tabela" ADD CONSTRAINT "nome da restrição" DEFAULT "valor default" FOR "campo" //Cria um default

-- Alteração Veiculko
ALTER TABLE Veiculo ADD VouApagar numeric(18,2)
ALTER TABLE Veiculo ADD AnoFabricacao int
ALTER TABLE Veiculo ADD Cores varchar(10)

ALTER TABLE Veiculo ALTER COLUMN AnoFabricacao int not null -- ALTER TABLE "nome da tabela" ALTER COLUMN "campo" "oq quer modificar" // Altera tabela
ALTER TABLE Veiculo ALTER COLUMN Cores varchar(50)
ALTER TABLE Veiculo DROP COLUMN VouApagar -- ALTER TABLE "nome da tabela" DROP COLUMN "campo" // Apaga Campo



select *from Modelo

