set foreign_key_checks = 0;

drop table if exists estudiantes;
create table estudiantes(
    est_id             int auto_increment primary key,
    est_dni            varchar(9) unique not null,
    est_apellidos      varchar(40)       not null,
    est_nombre         varchar(20)       not null,
    est_direccion      varchar(150),
    est_cp             int,
    est_fec_nacimiento date
);

drop table if exists asignaturas;
create table asignaturas(
    asi_id         int auto_increment primary key,
    asi_nombre     varchar(20),
    asi_titulacion varchar(50),
    asi_semestre   char(1)
);

drop table if exists matriculas;
create table matriculas(
    mat_estudiante   int,
    mat_asignatura   int,
    mat_curso        char(1),
    mat_calificacion float,
    
    primary key(mat_estudiante, mat_asignatura, mat_curso),
    
    constraint FK_estudiantes_matriculas foreign key (mat_estudiante)
    references estudiantes(est_id),
    
    constraint FK_asignaturas_matriculas foreign key (mat_asignatura)
    references asignaturas(asi_id),
);

set foreign_key_checks = 1;
