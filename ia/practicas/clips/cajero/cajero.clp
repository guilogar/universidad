(watch facts)
(watch rules)
(watch activations)
(watch agenda)

(clear)
(reset)

(defglobal
    ?*anio* = 2018
)

(deftemplate usuario
    (slot dni (type INTEGER))
    (slot pin (type INTEGER))
    (slot cantidad (type FLOAT))
)

(deftemplate tarjeta
    (slot dni (type INTEGER))
    (slot pin (type INTEGER))
    (slot n_intentos (type INTEGER) (default 3))
    (limite_dinero (type FLOAT) (default 500))
    (anio_exp (type INTEGER) (default ?*anio*))
    (tarjeta_valid (allowed-values Si No))
)

(deftemplate cuenta
    (slot dni (type INTEGER))
    (slot saldo (type FLOAT))
    (slot estado (allowed-values EnPantalla DineroEntregado Inicial SuperaLimite SinSaldo))
)

(deffacts facts_on_init
    (usuario (dni 123456)
             (pin 1212)
             (cantidad 300)
    )
    (usuario (dni 123456)
             (pin 1211)
             (cantidad 200)
    )
    (usuario (dni 123456)
             (pin 4545)
             (cantidad 3000)
    )
)

(defrule Supera_Intentos
    (usuario (dni ?d))
    (tarjeta (dni ?d) (intentos 0))
    =>
    (printout t crlf)
    (printout t "---------------------------------------------------------------------" crlf)
    (printout t "Usuario con DNI: " ?d " ha excedido el numero de intentos permitidos." crlf)
    (printout t "---------------------------------------------------------------------" crlf)
    (printout t crlf)
)

(defrule Pin_Invalido
    ?u <- (usuario (dni ?d) (pin ?pinUser))
    ?t <- (tarjeta (dni ?d) (pin ?pinTarjeta) (n_intentos ?intentos))
    (test (<> ?pinUser ?pinTarjeta))
    (test (> ?intentos 0))
    =>
    (modify ?t (intentos(- intentos 1)))
    (retract ?u)
    (printout t crlf)
    (printout t "--------------------------------------------------------------------" crlf)
    (printout t "Usuario con DNI: " ?d " ha introducido un pin incorrecto." crlf)
    (printout t "--------------------------------------------------------------------" crlf)
    (printout t crlf)
)

(defrule Valida_Tarjeta
    (usuario (dni ?d) (pin ?pinUser))
    (tarjeta (dni ?d) (pin ?pinTarjeta&~?pinUser) (n_intentos ?intentos) (anio_exp ?anioExp))
    (test (= ?intentos 0))
    (test (>= ?anioExp ?*anio*))
    =>
    (printout t crlf)
    (printout t "--------------------------------------------------------------------" crlf)
    (printout t "La tarjeta con DNI: " ?d " no se ha  validado." crlf)
    (printout t "--------------------------------------------------------------------" crlf)
    (printout t crlf)
)



