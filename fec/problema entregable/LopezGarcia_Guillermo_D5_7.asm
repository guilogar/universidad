.data
vector:      .word 1,0,300,4
tamanio:     .word 4

             .align 2

valor_text:  .asciiz "Valor: "
y_text:      .asciiz ", y "
indice_text: .asciiz "Índice: "

.text
.globl main
main:
	li $s0, 1             # int i = 1
	lw $s1, tamanio       # tamanio
	lw $s2, vector($zero) # int mayor = vector[0]
	li $s3, 0             # int indice_del_mayor = 0
	
	bucle:
		bge $s0, $s1, fin_bucle    # while(i < tamanio) {
		
		sll $t0, $s0, 2            # i = i + 1 (i << 2)
		
		lw $t1, vector($t0)        # aux = vector[i]
		
		ble $t1, $s2, fin_if           # if(aux > mayor) {
		
		if:
			move $s2, $t1          # mayor = aux
			move $s3, $s0          # indice = i
			
		fin_if:
		
		addi $s0, $s0, 1           # i += 1
		
		j bucle
	
	fin_bucle:                     # } end while
	
	# Se imprime el valor.
	la $a0, valor_text
	li $v0, 4
	syscall
	
	move $a0, $s2
	li $v0, 1
	syscall
	
	la $a0, y_text
	li $v0, 4
	syscall
	
	# Se imprime el indice.
	la $a0, indice_text
	li $v0, 4
	syscall
	
	move $a0, $s3
	li $v0, 1
	syscall
	
	# Fin del programa.
	li $v0, 10
	syscall
