/*------------------*/ 
/*	Bases de Datos  */
/*	Curso 2017-18   */	
/*------------------*/

/*------------------*/
/* Tabla provincias */
/*------------------*/

CREATE TABLE Provincias (
	pro_id INT  AUTO_INCREMENT PRIMARY KEY,
	pro_provincia VARCHAR(20)
);

/*------------------*/
/* Tabla ciudades   */
/*------------------*/

CREATE TABLE Ciudades (
	ciu_id INT  AUTO_INCREMENT PRIMARY KEY,
	ciu_nombre VARCHAR(20),
	ciu_provincia Int,
	FOREIGN KEY(ciu_provincia) REFERENCES Provincias(pro_id)
);

/*-----------------------*/
/* Tabla CodigosPostales */
/*-----------------------*/

CREATE TABLE CodigosPostales(
	cp_cp INT PRIMARY KEY,
	cp_ciudad INT,
	FOREIGN KEY(cp_ciudad) REFERENCES Ciudades(ciu_id)
);

/*------------------*/
/* Tabla clientes   */
/*------------------*/

CREATE TABLE Clientes (
	cli_id INT  AUTO_INCREMENT PRIMARY KEY,
	cli_dni VARCHAR(9),
	cli_apellidos VARCHAR(40),
	cli_nombre VARCHAR(20),
	cli_direccion VARCHAR(150),
	cli_cp INT,
	cli_fec_nac date,
	FOREIGN KEY(cli_cp) REFERENCES CodigosPostales(cp_cp)
);

/*------------------*/
/* Tabla cuentas    */
/*------------------*/

create table Cuentas(
	cue_id int auto_increment primary key,
	cue_ccc varchar(20),
	cue_cliente int,
	FOREIGN KEY(cue_cliente)REFERENCES Clientes(cli_id)
);

/*------------------*/
/* Tabla hipotecas  */
/*------------------*/

create table Hipotecas (
	hip_id int auto_increment primary key,
	hip_cuenta int,
	hip_importe float not null,
	hip_meses int not null,
	hip_interes int not null,
	hip_cuotas float,
	hip_fecha_inicio date not null,
	foreign key(hip_cuenta)references Cuentas(cue_id)
);

/* Alta de algunos datos */

/* Datos provincias */

INSERT INTO Provincias (pro_id, pro_provincia) VALUES
(1, 'Sevilla'),
(2, 'Cádiz'),
(3, 'Almería'),
(4, 'Málaga'),
(5, 'Córdoba'),
(6, 'Huelva'),
(7, 'Jaen'),
(8, 'Granada'),
(9, 'Madrid');

INSERT INTO `Provincias` (`pro_id`, `pro_provincia`) VALUES (NULL, 'Barcelona');

INSERT INTO `Ciudades` (`ciu_id`, `ciu_nombre`, `ciu_provincia`) VALUES (NULL, 'Cádiz', '2'), (NULL, 'Puerto Real', '2'), (NULL, 'Jerez', '1'), (NULL, 'Sevilla', '1'), (NULL, 'Huelva', '6');

INSERT INTO `CodigosPostales` (`cp_cp`, `cp_ciudad`) VALUES ('11001', '1'), ('11002', '1'), ('11402', '3'), ('11403', '3'), ('11500', '2');