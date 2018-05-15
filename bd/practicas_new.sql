CREATE TABLE Articulos (
    `ART_NUM` INT,
    `ART_NOM` VARCHAR(17) CHARACTER SET utf8,
    `ART_PESO` INT,
    `ART_COL` VARCHAR(6) CHARACTER SET utf8,
    `ART_PC` INT,
    `ART_PV` INT,
    `ART_PRV` INT
);

INSERT INTO Articulos VALUES (1,'Auriculares abc',30,'blanco',10,20,1);
INSERT INTO Articulos VALUES (2,'Auriculares wit',30,'blanco',7,15,1);
INSERT INTO Articulos VALUES (3,'Auriculares abc',30,'negro',10,20,1);
INSERT INTO Articulos VALUES (4,'Auriculares wit',1000,'rojo',8,17,1);
INSERT INTO Articulos VALUES (5,'Tablet abc',3000,'blanco',150,250,1);
INSERT INTO Articulos VALUES (6,'Tablet abc D4',3000,'blanco',190,315,1);
INSERT INTO Articulos VALUES (7,'Tablet Ignon',2000,'rosa',300,590,1);
INSERT INTO Articulos VALUES (8,'TFT',7000,'negro',90,175,1);
INSERT INTO Articulos VALUES (9,'TFT',7000,'blanco',90,175,1);
INSERT INTO Articulos VALUES (10,'PC',12000,'blanco',300,560,1);
INSERT INTO Articulos VALUES (11,'PC',12000,'negro',300,560,1);
INSERT INTO Articulos VALUES (12,'Mouse',30,'blanco',5,11,1);
INSERT INTO Articulos VALUES (13,'Mouse',30,'negro',5,11,1);
INSERT INTO Articulos VALUES (14,'Mouse',1000,'azul',5,11,1);
INSERT INTO Articulos VALUES (15,'Mouse',30,'rojo',5,11,1);
INSERT INTO Articulos VALUES (16,'Mouse',30,'rojo',5,11,1);
INSERT INTO Articulos VALUES (17,'pendrive 1GB',60,NULL,5,11,NULL);
INSERT INTO Articulos VALUES (18,'pendrive 4GB',60,'verde',8,15,NULL);
INSERT INTO Articulos VALUES (19,'pendrive 8GB',60,'rojo',9,19,NULL);
INSERT INTO Articulos VALUES (20,'pendrive 32GB',60,'azul',10,21,NULL);
INSERT INTO Articulos VALUES (21,'Cuaderno',NULL,NULL,5,10,1);
INSERT INTO Articulos VALUES (22,'calculadora',100,'negro',10,21,1);
INSERT INTO Articulos VALUES (23,'calendario',5,'blanco',1,2,4);
INSERT INTO Articulos VALUES (24,'lampara',550,'rojo',15,35,5);
INSERT INTO Articulos VALUES (25,'lampara',550,'blanco',15,35,5);
INSERT INTO Articulos VALUES (26,'lampara',550,'azul',15,35,5);
INSERT INTO Articulos VALUES (27,'lampara',550,'verde',15,35,5);
INSERT INTO Articulos VALUES (28,'pesacartas 1-500',NULL,NULL,20,35,3);
INSERT INTO Articulos VALUES (29,'pesacartas 1-1000',NULL,NULL,24,41,3);
INSERT INTO Articulos VALUES (30,'boligrafo',20,'rojo',1,3,2);
INSERT INTO Articulos VALUES (31,'boligrafo',20,'azul',1,3,2);
INSERT INTO Articulos VALUES (32,'boligrafo lujo',20,'rojo',60,100,2);
INSERT INTO Articulos VALUES (33,'boligrafo lujo',20,'verde',60,100,2);
INSERT INTO Articulos VALUES (34,'boligrafo lujo',20,'azul',60,100,2);
INSERT INTO Articulos VALUES (35,'boligrafo lujo',20,'negro',60,100,2);
INSERT INTO Articulos VALUES (36,'papel',80,'rosa',3,6,2);
INSERT INTO Articulos VALUES (37,'coche',20000000,'verde',5000,6000,3);
INSERT INTO Articulos VALUES (38,'impresora',800,'morado',30,55,3);
INSERT INTO Articulos VALUES (39,'calendario',5,'negro',1,2,4);
INSERT INTO Articulos VALUES (40,'manta',NULL,'malva',7,12,10);
INSERT INTO Articulos VALUES (41,'papel',NULL,'rosa',3,6,NULL);
INSERT INTO Articulos VALUES (42,'papel',80,'morado',3,6,1);
INSERT INTO Articulos VALUES (43,'impresora',800,'rojo',30,55,4);

CREATE TABLE Clientes (
    `CLT_NUM` INT,
    `CLT_APELL` VARCHAR(12) CHARACTER SET utf8,
    `CLT_NOM` VARCHAR(9) CHARACTER SET utf8,
    `CLT_PAIS` VARCHAR(1) CHARACTER SET utf8,
    `CLT_POB` VARCHAR(9) CHARACTER SET utf8
);
INSERT INTO Clientes VALUES (1,'borras','margarita','e','madrid');
INSERT INTO Clientes VALUES (2,'perez','miguel','e','madrid');
INSERT INTO Clientes VALUES (3,'dupret','pierre','f','paris');
INSERT INTO Clientes VALUES (4,'roman','consuelo','e','sevilla');
INSERT INTO Clientes VALUES (5,'cortes','diego','e','cadiz');
INSERT INTO Clientes VALUES (6,'lara','francisco','e','jerez');
INSERT INTO Clientes VALUES (7,'duran','jacinto','e','cadiz');
INSERT INTO Clientes VALUES (8,'borras','macarena','e','almeria');
INSERT INTO Clientes VALUES (9,'borrinho','miguel','p','lisboa');
INSERT INTO Clientes VALUES (10,'roca','Pablo','e','barcelona');
INSERT INTO Clientes VALUES (11,'ruiz','roberto','e','pamplona');
INSERT INTO Clientes VALUES (12,'velez','alberto','e','pamplona');
INSERT INTO Clientes VALUES (13,'dupont','jean','f','paris');
INSERT INTO Clientes VALUES (14,'llopis','antoni','e','barcelona');
INSERT INTO Clientes VALUES (15,'Messi','Leo','a','Rosario');
INSERT INTO Clientes VALUES (16,'souris','marcel','f','paris');
INSERT INTO Clientes VALUES (17,'goni','pablo','e','pamplona');
INSERT INTO Clientes VALUES (18,'courbon','gerad','f','lyon');
INSERT INTO Clientes VALUES (19,'roman','marta','e','jaen');
INSERT INTO Clientes VALUES (20,'roca','pau','e','gerona');
INSERT INTO Clientes VALUES (21,'mancha','jorge','e','valencia');
INSERT INTO Clientes VALUES (22,'curro','pablo','e','barcelona');
INSERT INTO Clientes VALUES (23,'cortes','diego','e','madrid');
INSERT INTO Clientes VALUES (24,'fernandez','joaquin','c','HADRID');
INSERT INTO Clientes VALUES (25,'duran','jacinto','e','pamplona');
INSERT INTO Clientes VALUES (26,'minguin','pedro','e','pamplona');
INSERT INTO Clientes VALUES (27,'ubrique','jesus','e','pamplona');
INSERT INTO Clientes VALUES (28,'mazapato','sophie','e','madrid');
INSERT INTO Clientes VALUES (29,'bigote','jose mari','p','oporto');
INSERT INTO Clientes VALUES (30,'dalima sorda','romualdo','b','san jose');
INSERT INTO Clientes VALUES (31,'clavel rojo','paco','e','mala');
INSERT INTO Clientes VALUES (32,'Alonso','Fernando','e','Gijon');
INSERT INTO Clientes VALUES (33,'Rodriguez','Pedrito','e','Arico');
INSERT INTO Clientes VALUES (34,'Florero','Mar','e','madrid');
INSERT INTO Clientes VALUES (35,'Florero','Mar','e','barcelona');

CREATE TABLE Pesos (
    `PESO_NOM` VARCHAR(6) CHARACTER SET utf8,
    `PESO_MIN` INT,
    `PESO_MAX` INT
);
INSERT INTO Pesos VALUES ('leve',0,100);
INSERT INTO Pesos VALUES ('ligero',101,500);
INSERT INTO Pesos VALUES ('medio',501,2500);
INSERT INTO Pesos VALUES ('pesado',2501,9999);

CREATE TABLE Proveedores (
    `PRV_NUM_PRV_NOM` VARCHAR(33) CHARACTER SET utf8
);
INSERT INTO Proveedores VALUES ('         1 catio electronic');
INSERT INTO Proveedores VALUES ('         2 infogesa');
INSERT INTO Proveedores VALUES ('         3 electriprecios');
INSERT INTO Proveedores VALUES ('         4 robotik');
INSERT INTO Proveedores VALUES ('         5 maquinaria ramirez SL');
INSERT INTO Proveedores VALUES ('         6 papeleria frutos SA');
INSERT INTO Proveedores VALUES ('         7 catio electronic II');
INSERT INTO Proveedores VALUES ('         8 estilografica reunidas');
INSERT INTO Proveedores VALUES ('         9 mecanica de precision');
INSERT INTO Proveedores VALUES ('        10 sanjita');
INSERT INTO Proveedores VALUES ('        11 electrolamp');
INSERT INTO Proveedores VALUES ('        12 copisteria');
INSERT INTO Proveedores VALUES ('        13 el corte ingles');
INSERT INTO Proveedores VALUES ('        14 Mercadiz');
INSERT INTO Proveedores VALUES ('        15 El ahorramas');

CREATE TABLE Tiendas (
    `TDA_NUM` INT,
    `TDA_POB` VARCHAR(15) CHARACTER SET utf8,
    `TDA_GER` VARCHAR(17) CHARACTER SET utf8
);
INSERT INTO Tiendas VALUES (1,'madrid-batan','rodriguez, moises');
INSERT INTO Tiendas VALUES (2,'madrid-vallecas','jemez, patricia');
INSERT INTO Tiendas VALUES (3,'pamplona','leon, francisco');
INSERT INTO Tiendas VALUES (4,'barcelona','ortega, lorena');
INSERT INTO Tiendas VALUES (5,'trujillo','mendez, pedro');
INSERT INTO Tiendas VALUES (6,'jaen','galeano, esther');
INSERT INTO Tiendas VALUES (7,'valencia','mina, rodrigo');
INSERT INTO Tiendas VALUES (8,'requena','marcos, pilar');
INSERT INTO Tiendas VALUES (9,'gerona','gomez, gabriel');
INSERT INTO Tiendas VALUES (10,'palencia','romeva, luis');
INSERT INTO Tiendas VALUES (11,'lyon','madoux, jean');
INSERT INTO Tiendas VALUES (12,'paris','foutex, paul');

CREATE TABLE Ventas (
    `VNT_CLT` INT,
    `VNT_TDA` INT,
    `VNT_ART` INT,
    `VNT_CANT` INT,
    `VNT_PRECIO` INT,
    `VNT_FC` INT
);
INSERT INTO Ventas VALUES (22,10,17,1,6000,991231);
INSERT INTO Ventas VALUES (5,4,4,1,2980,910106);
INSERT INTO Ventas VALUES (7,3,10,1,40,910106);
INSERT INTO Ventas VALUES (7,3,11,2,80,910106);
INSERT INTO Ventas VALUES (7,3,14,3,300,910106);
INSERT INTO Ventas VALUES (8,11,2,1,4700,910109);
INSERT INTO Ventas VALUES (6,12,3,2,1200,910109);
INSERT INTO Ventas VALUES (6,12,15,2,200,910109);
INSERT INTO Ventas VALUES (13,1,4,1,2980,910109);
INSERT INTO Ventas VALUES (13,1,3,1,600,910110);
INSERT INTO Ventas VALUES (1,2,2,1,4700,910110);
INSERT INTO Ventas VALUES (1,2,12,1,100,910110);
INSERT INTO Ventas VALUES (1,2,13,10,1000,910110);
INSERT INTO Ventas VALUES (4,11,1,8,4640,910111);
INSERT INTO Ventas VALUES (4,11,10,7,280,910111);
INSERT INTO Ventas VALUES (3,7,6,1,2980,910111);
INSERT INTO Ventas VALUES (3,7,9,2,10000,910111);
INSERT INTO Ventas VALUES (1,2,3,3,1800,910120);
INSERT INTO Ventas VALUES (7,8,3,1,600,910203);
INSERT INTO Ventas VALUES (4,5,3,6,3000,910114);
INSERT INTO Ventas VALUES (10,11,3,1,600,910116);
INSERT INTO Ventas VALUES (6,7,3,1,600,910111);
INSERT INTO Ventas VALUES (3,4,3,2,1200,910206);
INSERT INTO Ventas VALUES (9,10,3,1,600,910201);
INSERT INTO Ventas VALUES (2,3,3,4,2400,910102);
INSERT INTO Ventas VALUES (8,9,3,1,500,910130);
INSERT INTO Ventas VALUES (5,6,3,3,1800,910116);
INSERT INTO Ventas VALUES (26,4,17,2,12000,990101);
INSERT INTO Ventas VALUES (19,7,3,1,NULL,960601);
INSERT INTO Ventas VALUES (17,4,3,10,NULL,961028);
INSERT INTO Ventas VALUES (18,1,3,1,NULL,961130);
INSERT INTO Ventas VALUES (10,4,2,NULL,NULL,920822);
INSERT INTO Ventas VALUES (3,13,3,NULL,NULL,940430);
INSERT INTO Ventas VALUES (7,11,1,1,100,180420);
INSERT INTO Ventas VALUES (7,3,9,1,175,180107);
INSERT INTO Ventas VALUES (7,3,14,3,33,180109);
INSERT INTO Ventas VALUES (7,3,15,3,30,180109);
INSERT INTO Ventas VALUES (8,11,11,1,560,180111);
INSERT INTO Ventas VALUES (6,11,10,2,1120,180203);
INSERT INTO Ventas VALUES (6,12,1,2,40,180206);
INSERT INTO Ventas VALUES (1,1,1,1,20,180302);
INSERT INTO Ventas VALUES (1,1,3,1,17,180303);
INSERT INTO Ventas VALUES (11,11,3,1,20,180107);
INSERT INTO Ventas VALUES (11,11,8,1,175,180310);
INSERT INTO Ventas VALUES (3,7,4,1,17,180311);

CREATE TABLE Comentarios (
    `Tabla` VARCHAR(9) CHARACTER SET utf8,
    `Campo` VARCHAR(8) CHARACTER SET utf8,
    `Comentario` VARCHAR(6) CHARACTER SET utf8
);
INSERT INTO Comentarios VALUES ('Articulos','art_peso','gramos');
INSERT INTO Comentarios VALUES ('Articulos','art_pc','euros');
INSERT INTO Comentarios VALUES ('Articulos','art_pv','euros');