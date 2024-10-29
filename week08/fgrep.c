#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv) {
    // Zero arguments (fail)
    if (argc == 1) {
        printf("not enough arguments\n");
        return 1;
    }

    // One argument case (read from stdin)
    if (argc == 2) {
        while (1) {
            char *substring = argv[1];
            char input[512] = {0};

            if (fgets(input, 512, stdin) == NULL) {
                break;
            }

            if (strstr(input, substring) != NULL) {
                printf("%s", input);
            }
        }
    }

    // Two or more arguments (read from file instead of stdin)
    else {
        char *substring = argv[1];
        char input[512] = {0};

        for (int i = 2; i < argc; i++) {
            FILE *f = fopen(argv[i], "rb");

            if (f == NULL) {
                perror(argv[i]);
                return 1;
            }

            while (fgets(input, 512, f) != NULL) {
                char *found = strstr(input, substring);

                if (found != NULL) {
                    printf("%s", input);
                }
            }

            fclose(f);
        }
    }
}
