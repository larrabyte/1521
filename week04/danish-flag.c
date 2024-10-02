// This program prints out a danish flag, by
// looping through the rows and columns of the flag.
// Each element inside the flag is a single character.
// (i.e., 1 byte).
//
// (Dette program udskriver et dansk flag, ved at
// sløjfe gennem rækker og kolonner i flaget.)
//

#include <stdio.h>

#define FLAG_ROWS 6
#define FLAG_COLS 12

char flag[FLAG_ROWS][FLAG_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {
    for (int row = 0; row < FLAG_ROWS; row++) {
        for (int col = 0; col < FLAG_COLS; col++) {
            printf("%c", flag[row][col]);
        }
        printf("\n");
    }
}

int main(void) {
row_init:
    int row = 0;

row_cond:
    while (row >= FLAG_ROWS) goto end;

row_body:
col_init:
    int col = 0;

col_cond:
    while (col >= FLAG_COLS) goto col_end;

col_body:
    printf("%c", flag[row][col]);
    col++;

    goto col_cond;

col_end:

    printf("\n");
    row++;

    goto row_cond;

end:
}
