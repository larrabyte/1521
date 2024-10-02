FLAG_ROWS = 6
FLAG_COLS = 12

main:
main__row_init:
    # row = $t0
    li      $t0, 0

main__row_cond:
    bge     $t0, FLAG_ROWS, end

main__row_body:
main__col_init:
    # col = $t1
    li      $t1, 0

main__col_cond:
    bge     $t1, FLAG_COLS, main__col_end

main__col_body:
    # offset into flag array = $t2
    mul     $t2, $t0, 12
    add     $t2, $t2, $t1
    lb      $a0, flag($t2)

    li      $v0, 11
    syscall

    add     $t1, $t1, 1
    j       main__col_cond

main__col_end:
    li      $v0, 11
    li      $a0, '\n'
    syscall

    add     $t0, $t0, 1
    j       main__row_cond

end:
    jr      $ra

.data
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
