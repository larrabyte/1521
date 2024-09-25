N_SIZE = 10

.data
numbers:
.space 4 * N_SIZE

.text
main:
    # i = $t0
    li  $t0, 0

cond:
    bge $t0, N_SIZE, end

body:
    li  $v0, 5
    syscall

    # offset = $t2
    mul $t2, $t0, 4
    sw  $v0, numbers($t2)

    add $t0, $t0, 1
    b   cond

end:
    li  $v0, 0
    jr  $ra

