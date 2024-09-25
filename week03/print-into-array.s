N_SIZE = 10

.data
numbers:
.word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

.text
main:
    # i = $t0
    li  $t0, 0

cond:
    bge $t0, N_SIZE, end

body:
    li  $v0, 1
    mul $t1, $t0, 4
    lw  $a0, numbers($t1)
    syscall

    li  $v0, 11
    li  $a0, '\n'
    syscall

    add $t0, $t0, 1
    b   cond

end:
    li  $v0, 0
    jr  $ra
