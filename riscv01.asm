addi x8, x0, 5
addi x9, x0, 10
add x10, x8, x9
sw x10, 0(x0)
beq x10, x0, L1
lui x11, 0x10000
jal x0, L2
L1:
 nop
L2:
 nop