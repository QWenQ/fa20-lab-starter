.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # prologue
    addi sp, sp, -8
    sw s0, 0(sp)
    sw ra, 4(sp)
    
    
    # YOUR CODE HERE
    mv s0, a0
    li t0, 1
    beq s0, t0, Else
    addi a0, s0, -1
    jal ra, factorial
    jal x0, End
Else:
    li a0, 1
    
End:
    mul a0, a0, s0
    
    # epilogue 
    lw s0, 0(sp)
    lw ra, 4(sp)
    addi sp, sp, 8
    jr ra