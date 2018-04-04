# Declaracion de variables

.data
ciudad:    .asciiz "Cádiz"
           .align 2
poblacion: .word 121000
msg:       .asciiz "La ciudad de $ tiene # habitantes\n"

.text
	la $a0, msg
	la $a1, ciudad
	la $a2, poblacion
	jal     myprintf

	li $v0, 10
	syscall
	
	
	myprintf: 
		move $s0, $a0
		move $s1, $a1
		move $s2, $a2
		
		do:
			lbu $s3, 0($s0)
			
			beq $s3, '$', if
			
			else:
				beq $s3, '#', elseif
				move $a0, $s3
				li $v0, 11
				syscall
				j fin_if
				
				elseif:
					lw $a0, 0($s2)
					li $v0, 1
					syscall
					j fin_if
			if:
				la $a0, 0($s1)
				li $v0, 4
				syscall
				
			fin_if:
			
			addi $s0, $s0, 1
		bnez $s3, do
		
		jr $ra
