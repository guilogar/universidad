(clear)
(reset)

(deftemplate coche 
	(slot modelo)
	(slot precio (type INTEGER) (default 13000))
	(slot maletero (allowed-values Pequeño Mediano Grande) (default Grande))
	(slot n_caballos (type INTEGER) (default 80))
	(slot abs (default Si))
	(slot consumo_litros (type FLOAT) (default 8.0))
)

(list-deftemplates)

(deffacts facts_iniciales
	(coche (modelo modelo1)
	       (precio 12000)
	       (maletero Pequeño)
		(n_caballos 65)
		(abs No)
		(consumo_litros 4.7)
        )
	(coche (modelo modelo2)
	       (precio 12500)
	       (maletero Pequeño)
		(n_caballos 80)
		(consumo_litros 4.9)
        )
	(coche (modelo modelo3)
	       (precio 13000)
	       (maletero Mediano)
		(n_caballos 100)
		(consumo_litros 7.8)
        )
	(coche (modelo modelo4)
	       (precio 14000)
	       (maletero Grande)
		(n_caballos 125)
		(consumo_litros 6.0)
        )
	(coche (modelo modelo5)
	       (precio 15000)
	       (maletero Pequeño)
		(n_caballos 147)
		(consumo_litros 8.5)
        )
)
(reset)
(facts)

(assert (configuracion_coche_cliente (precio 12500)))


