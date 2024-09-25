// A simple program that will read 10 numbers into an array

#define N_SIZE 10

#include <stdio.h>

int main(void) {
    int i;
    int numbers[N_SIZE] = {0};

    int array[2] = {0};

    i = 0;

    /* while (i < N_SIZE) {
        scanf("%d", &numbers[i]);
        i++;
    } */

cond:
    if (i >= N_SIZE) goto end;

body:
    scanf("%d", &numbers[i]);
    i++;
    goto cond;

end:
}
