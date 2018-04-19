.data
num_filas:    .word 4
num_columnas: .word 4

matriz1:      .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
matriz2:      .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16

              .align 2

res:          .space 64
              
              .align 2
              
space:        .asciiz " "
salto:        .asciiz "\n"


.text
.globl main
main:
	move $t0, $zero        # i = 0
	
	lw $t1, num_filas
	lw $t2, num_columnas
	mulu $t3, $t2, $t1    # max = 16
	
	move $t8, $zero
	
	while:
	    bge $t0, $t3, end_while # i < 16
		
		sll $t7, $t0, 2
		
		lw $t4, matriz1($t7)	# int var1 = matriz1[i]
		lw $t5, matriz2($t7)	# int var2 = matriz2[i]
		
	    add $t6, $t4, $t5		# int var3 = var1 + var2
	    
	    sw $t6, res($t7)
	    
	    move $a0, $t6
		li $v0, 1
		syscall
	    
	    
	    addi $t8, $t8, 1                  # cont += 1
		bge $t8, $t2, if
		
		la $a0, space
		li $v0, 4
		syscall
		
		j fin_if
		
		if:
			li $t8, 0                     # cont = 0
			
			la $a0, salto
			li $v0, 4
			syscall
		
		fin_if:
	    
		addi $t0, $t0, 1
		
		j while
	end_while:
	
	li $v0, 10
	syscall