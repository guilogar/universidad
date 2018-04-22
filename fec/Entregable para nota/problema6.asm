.data
regexpr:      .asciiz "Yo soy un %s, un gran %s. Por lo t%cnto, hoy puede ser mi gran %s. La %iº de verdad."
parametro1:   .asciiz "trúan"
parametro2:   .asciiz "señor"
parametro3:   .asciiz "a"
parametro4:   .asciiz "noche"
parametro5:   .word   1

.text
.globl main
main:
	# Se cargan todos los parametros en pila
	la $s0, regexpr
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	
	la $s0, parametro1
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	
	la $s0, parametro2
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	
	la $s0, parametro3
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	
	la $s0, parametro4
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	
	la $s0, parametro5
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	
	move $a0, $sp
	li $a1, 6
	
	jal printf
	
	li $v0, 10
	syscall
	
printf:
	move $t0, $a0        # copia del puntero a pila
	move $t1, $a1        # max = numero de elementos
	
	addi $t1, $t1, -1    # Se le quita uno al numero de parametros para despues hacerle el desplazamiento
	                     # De bits y sumarle al puntero de la pila para obtener la direccion de memoria del
	                     # primer parametro de la funcion
	sll $t5, $t1, 2      # Se realiza el desplazamiento
	add $t0, $t0, $t5    # Se le suma el desplazamiento al puntero de la pila
	
	lw $t2, 0($t0)       # Se obtiene la direccion de memoria del primer parametro introducido en la pila
	                     # Asi pues, como tiene estructura LIFO, el primer entrar es el primero en salir
						 
	while:
		lbu $t3, 0($t2)      # char aux = cad[i]
		beqz $t3, end_while  # while(aux != '\0') {
		
		bne $t3, '%', print  # if(aux != '%' ||
		blez $t1, print      #    max < 0) {
		
		switch:
			addi $t1, $t1, -1  # max -= 1
		    addi $t0, $t0, -4  # puntero a pila decrementado, siguiendo la estructura contraria a lifo para enseñar los datos en orden
		    
			lbu $t3, 1($t2)    # aux = cad[i + 1]
			
			beq $t3, 's', case_s  # caso para enseñar cadenas
			beq $t3, 'c', case_c  # caso para enseñar un caracter
			beq $t3, 'i', case_i  # caso para enseñar un numero entero con signo
			beq $t3, 'f', case_f  # caso para enseñar un numero en precision simple con signo
			beq $t3, 'd', case_d  # caso para enseñar un numero en precision doble con signo
			
			case_s:
				lw $t3, 0($t0)
				move $a0, $t3
				li $v0, 4
				syscall
				j end_switch
			case_c:
				lw $t3, 0($t0)
				lbu $a0, 0($t3)
				li $v0, 11
				syscall
				j end_switch
			case_i:
				lw $t3, 0($t0)
				lw $a0, 0($t3)
				li $v0, 1
				syscall
				j end_switch
			case_f:
				lw $t3, 0($t0)
				lw $a0, 0($t3)
				li $v0, 2
				syscall
				j end_switch
			case_d:
				lw $t3, 0($t0)
				lw $a0, 0($t3)
				li $v0, 3
				syscall
			end_switch:
			
			addi $t2, $t2, 1
			j end_print
		
		print:
		    move $a0, $t3
		    li $v0, 11
		    syscall
		
		end_print:
		
		addi $t2, $t2, 1           # *cad = (*cad + 1) Propio de las caracteristicas del C al bajo nivel
		j while
	
	end_while:
	
	jr $ra
