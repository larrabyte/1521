baz:
    jr      $ra

foobar:
    push    $ra
    push    $s0
    li      $s0, 6

    # do some more computation
    jal     baz

    pop     $s0
    pop     $ra
    jr      $ra

main:
    li      $s0, 5

    # do some computation
    jal     foobar

    # $s0 must equal 5 here
    syscall
