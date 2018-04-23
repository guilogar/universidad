-- Ejercicio 1

select *
from articulos
where art_peso < (select art_peso
                  from articulos
                  where art_num = 2);

-- Ejercicio 2

select art_num, art_nom
from articulos
where art_peso > (select min(art_peso)
                  from articulos
                  where art_nom = 'calendario')
      or
      art_col in (select art_col
                  from articulos
                  where art_nom = 'impresora');

-- Otra forma del ejercicio 2
select art_num, art_nom
from articulos
where art_peso > all (select art_peso
                  from articulos
                  where art_nom = 'calendario')
      or
      art_col in (select art_col
                  from articulos
                  where art_nom = 'impresora');

-- Ejercicio 3

select *
from articulos
where art_col = (select art_col
                 from articulos
                 where art_num = 10)
      and
      art_peso >= (select avg(art_peso)
                   from articulos);

-- Ejercicio 4

select *
from proveedores
where prv_num in (select art_prv
                  from articulos
                  where art_col = 'negro');

-- Ejercicio 5

select clt_nom, clt_apell
from clientes
where clt_pais = 'e'
      and
      clt_pob in (select clt_pob
                  from clientes
                  where clt_nom = 'Pablo')
order by clt_num;

-- Ejercicio 6

select *, art_pv as Euros, art_pv/166 as Pesetas
from articulos a1
where art_pv = (select max(art_pv)
                 from articulos a2
                 where a1.art_col = a2.art_col
                 group by art_col);

-- Ejercicio 7

select *
from articulos a1
where art_pv = (select max(art_pv)
                from articulos a2
                where a1.art_col = a2.art_col
                or
                (a1.art_col is NUll and a2.art_col is NULL)
                group by art_col);

-- Ejercicio 8


-- Ejercicio 11
select *
from articulos a1
where exists (select art_pv
              from articulos a2
              where art_col = 'blanco' and a1.art_pv > a2.art_pv);


-- Ejercicio C2
select *
from clientes
where clt_pob in ('madrid', 'barcelona', 'cadiz')
      and
      clt_num in (select vnt_clt
                  from ventas
                  group by vnt_clt
                  having count(distinct vnt_tda) > 2);
