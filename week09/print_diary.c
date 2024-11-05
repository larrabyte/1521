#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *home = getenv("HOME");

    if (home == NULL) {
        perror("HOME");
        return 1;
    }

    char *buf = malloc(strlen(home) + 7 + 1);

    if (buf == NULL) {
        perror("malloc");
        return 1;
    }

    sprintf(buf, "%s/.diary", home);

    FILE *f = fopen(buf, "r");

    if (f == NULL) {
        perror(buf);
        return 1;
    }

    /* Character by character */
    int c;

    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }

    fclose(f);
}
