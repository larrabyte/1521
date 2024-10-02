max:
    # array = $a0
    # length = $a1
    # first_element = $t0
    push    $ra
    push    $s0
    lw      $s0, ($a0)

max__length_check:
    bne     $a1, 1, max__first_element

max__recurse:
    add     $a0, $a0, 4
    sub     $a1, $a1, 1
    jal     max
    # max_so_far = $v0
    # TODO

max__intermediate_check:
    ble     $s0, $v0, max__early_return

    move    $v0, $s0

max__early_return:
    pop     $s0
    pop     $ra
    jr      $ra

max__first_element:
    move    $v0, $t0
    pop     $s0
    pop     $ra
    jr      $ra
