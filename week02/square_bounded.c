// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= SQUARE_MAX) goto if_false; 

    /* if (x > SQUARE_MAX) {
        printf("square too big for 32 bits\n");
    } else {
        y = x * x;
        printf("%d\n", y);
    } */


if_true:
    printf("square too big for 32 bits\n");
    goto end;

if_false:
    y = x * x;
    printf("%d\n", y);

end:
    return 0;
}
