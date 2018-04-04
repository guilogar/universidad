.data
nums: .half 1,-3,5,-7,9,-11,13,-15,17,-19
N:    .half 10

.text
.globl main

main:
	li $s0, 0  #Cargo en $s0 el valor para el contador del bucle
	li $s1, 0  #Cargo en $s1 el valor que le ire sumando para hacer el direccionamiento
	lh $s7, N
	
	#la $s7, N
	#lh $s7, 0($s7)
	
	for:
		bge $s0, $s7, fin_for
		addi $s0, $s0, 1
		
		#################################
		lh $t0, nums($s1)
		addi $s1, $s1, 2
		
		if:
		blez $t0, else
		move $a0, $t0
		j fin_if
		
		else:
		move $a0, $zero
		
		fin_if:
		li $v0, 1
		syscall
		################################
		
		j for
	
	fin_for:
		li $v0, 10
		syscall
