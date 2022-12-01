CREATE TABLE GameServer
(
	IDGameServer int not null identity,
	IP varchar(30),
	Type varchar(100),
	Creation datetime,
	DNSServer int
	CONSTRAINT PKIDGameServer PRIMARY KEY (IDGameServer)
)

CREATE TABLE Player
(
	IDPlayer int not null identity,
	Name varchar(100),
	UserName varchar(20),
	Password varchar(20),
	Points int,
	IDGameServer int,
	CONSTRAINT PKIDPlayer PRIMARY KEY (IDPlayer),
	CONSTRAINT FKIDGameServer FOREIGN KEY (IDGameServer) REFERENCES GameServer(IDGameServer)
)

ALTER TABLE Player ADD Age int
ALTER TABLE Player ALTER COLUMN Name varchar(200)
ALTER TABLE	GameServer DROP COLUMN DNSServer