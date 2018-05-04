-- Ejercicio 17

select *
from clientes
where clt_num not in (select vnt_clt
                      from ventas
                     );
select *
from clientes
where clt_num = any (select vnt_clt
                     from ventas);

-- Ejercicio 18

select clt_num, clt_apell, clt_nom, clt_pob, vnt_fch as 'Fecha Ultima Compra'
from clientes c left join ventas v1 on c.clt_num = v1.vnt_clt
where cast(vnt_fch as SIGNED) >= all (select cast(vnt_fch as SIGNED)
                                             from ventas v2
                                             where v1.vnt_clt = v2.vnt_clt
                                      );

-- Ejercicio C2

select prv_num as 'NUM', prv_nom as 'TIENDA', count(art_num) as 'ARTICULOS', count(distinct art_num) as 'DISTINTOS'
from proveedores p
     right join articulos a
     on p.prv_num = a.art_prv
     left join ventas v
     on a.art_num = v.vnt_art
group by prv_num, prv_nom;
