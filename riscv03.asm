addi x1, x0, 1
addi x2, x0, 2
mul x3, x1, x2
sh x3, 8(x0)
blt x1, x2, L5
lui x4, 0x30000
jal x5, L6
L5:
 nop
 L6:
 nop