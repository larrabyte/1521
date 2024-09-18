string:
.asciiz "Enter a number: "

too_large:
.asciiz "square too big for 32 bits\n"

main:
    # x = $t0
    # y = $t1

    li      $v0, 4
    la      $a0, string
    syscall

    li      $v0, 5
    syscall
    move    $t0, $v0

    ble $t0, 46340, if_false

if_true:
    li      $v0, 4
    la      $a0, too_large
    syscall

    j   end

if_false:
    mul     $t1, $t0, $t0

    li  $v0, 1
    move    $a0, $t1
    syscall

    li  $v0, 11
    li  $a0, '\n'
    syscall

end:
    li  $v0, 0
    jr  $ra
