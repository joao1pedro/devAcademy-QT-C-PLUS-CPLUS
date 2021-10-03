--CREATE TABLE IF NOT EXISTS usuario (
--    id INTEGER PRIMARY KEY AUTOINCREMENT,
--    nome TEXT,
--    email TEXT
--);

CREATE TABLE IF NOT EXISTS anotacao (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT,
    descricao TEXT,
    cor TEXT,
    date_time TEXT
);

INSERT INTO anotacao (nome, descricao, cor, date_time) VALUES("Caminhar","As 5h30 da manha","blue", "Tue 2013-09-17 10:56:06");
INSERT INTO anotacao (nome, descricao, cor, date_time) VALUES("Codar","Sabado de noite","yellow", "Wed 2013-09-18 10:56:06");
