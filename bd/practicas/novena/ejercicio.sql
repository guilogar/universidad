-- Ejercicio 1
insert ignore into CodigosPostales(cp_cp, cp_ciudad)
            values(11405, 3),
                  (41001, 4),
                  (41002, 4),
                  (11519, 1);

insert into Clientes(cli_dni, cli_apellidos, cli_nombre,
                     cli_direccion, cli_cp)
            values('12345682E', 'Iglesias Copero', 'Jose', 'Paseo Rosaleda, 15', 11405),
                  ('12345683F', 'Sánchez Romero', 'Damián', 'C/ Luis XIX, 7', 41001),
                  ('12345684G', 'Romero Gil', 'Sofia', 'Urb. Las Flores, 4 5ºS', 11519);

-- Ejercicio 2
insert into Cuentas(cue_cliente, cue_ccc)
            values(1, '21000003134567811144'),
                  (2, '21000024003102575722'),
                  (3, '21000024003102570121');

-- Ejercicio 3
insert into Hipotecas(hip_cuenta, hip_importe, hip_meses, hip_interes, hip_cuotas, hip_fecha_inicio)
            values(3, 180000, 300, 2, 300, '2018-05-31');

-- Ejercicio 4
update Clientes
set cli_apellidos = 'Sánchez Ropero'
where cli_dni = '12345683F';

-- Ejercicio 5
update Clientes
set cli_cp = 41002
where cli_dni = '12345683F';

-- Ejercicio 6
delete from Hipotecas
where hip_cuenta = (select cli_id from Clientes where cli_dni = '12345684G' limit 1);
delete from Cuentas
where cue_cliente = (select cli_id from Clientes where cli_dni = '12345684G' limit 1);
delete from Clientes
where cli_dni = '12345684G';
