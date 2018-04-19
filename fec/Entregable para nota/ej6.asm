.data
regexpr:      .asciiz "Yo soy un %s, un gran %s. Por lo t%cnto, hoy puede ser mi gran %s. La %dº de verdad."
parametro1:   .asciiz "trúan"
parametro2:   .asciiz "señor"
parametro3:   .asciiz "a"
parametro4:   .asciiz "noche"
parametro5:   .word 1

.text
.globl main
main:
	la $a0, parametros
	li $v0, 4
	syscall