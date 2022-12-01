/*Insert*/

-- INSERT INTO "tabela" ("colunas") values ("dados")
-- Se for colocar todas as colunas não precisa inserir as colunas
-- INSERT INTO "tabela" ("colunas","colunas") values ("dados","dados") 

/*Select*/

-- Select * from "tabala"
-- Select ("coluna") from "tabela"

/*Formata data */

-- SET DATEFORMAT DMY

/*COMEÇA AQUI CODE*/
INSERT INTO Modelo (Nome, NumeroLugares, Tipo) VALUES ('HB20s', 4, 'Sedan')
INSERT INTO Modelo (Nome) VALUES ('TCross')
INSERT INTO Modelo VALUES ('Tcross', 'Legal', 7, 'SUV'), ('Onix', null, null, 'Hatch')
INSERT INTO Modelo (Nome, data) VALUES ('ok', )

UPDATE Modelo SET Descriacao = 'Nova descrição' WHERE IDModelo = 1

DELETE FROM Modelo WHERE IDModelo = 4

SELECT * from Modelo
