set foreign_key_checks = 0;

-- create in noob mode

drop table if exists mascota;
create table mascota(
    id            int         auto_increment primary key,
    nombre        varchar(20) not null,
    propietario   varchar(20),
    especie       varchar(20),
    sexo          char(1)
);

-- alter table

alter table mascota add fec_nacimiento DATE;
alter table mascota modify propietario varchar(30);

insert into mascota values(null, 'Dana', 'Jose', 'Perro, pastor alemán',
                           'H', NULL);

drop table if exists veterinarios;
create table veterinarios(
    codigo        int         auto_increment primary key,
    nombre        varchar(20),
    apellidos     varchar(40),
    clinica       varchar(40)
);

drop table if exists consultas;
create table consultas(
    fecha         date,
    veterinario   int,
    mascota       int,
    diagnostico   varchar(100),
    
    constraint FK_veterinarios_consultas foreign key (veterinario)
    references veterinarios(codigo),
    constraint FK_mascota_consultas foreign key (mascota)
    references mascota(id),
    
    primary key(veterinario, mascota)
);

set foreign_key_checks = 1;
