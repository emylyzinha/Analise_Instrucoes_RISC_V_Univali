addi x5, x0, 20
addi x6, x0, 15
sub x7, x5, x6
sb x7, 4(x0)
bne x7, x0, L3
auipc x1, 0x20000
jal x2, L4

L3: 
    nop        # Instrução vazia só para ter algo no label

L4:
    nop
