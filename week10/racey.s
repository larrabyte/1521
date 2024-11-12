global_total:
.word 0

add_to_counter:
    # possible race condition if two threads execute the same set of instructions at the same time
    lw      $t0, global_total
    add     $t0, $t0, 1
    sw      $t0, global_total

add_to_counter_2:
    # hypothetical atomic "adda" instruction would be safe to use with multiple threads,
    # since there is no way for a thread to see an in-between state
    adda   global_total, 1
