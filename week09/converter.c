#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char big_buffer[512];
    fgets(big_buffer, 512, stdin);

    int x = atoi(big_buffer);

    char buf[512];
    printf("%x\n", x);
}
