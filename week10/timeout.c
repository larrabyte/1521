#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <spawn.h>

char BIG_ARRAY[512] = {0};

void *timeout(void *arg) {
    int *chars = arg;
    sleep(1);

    for (int i = 0; i < 512; i++) {
        if (chars[i] == EOF) {
            exit(1);
        }
    }

    return NULL;
}

int main(void) {
    FILE *f = fopen("diary.txt", "r");
    assert(f != NULL);

    pthread_t thread;
    int chars[512] = {EOF};
    pthread_create(&thread, NULL, timeout, chars);

    for (int i = 0; i < 512; i++) {
        chars[i] = fgetc(f);
    }
}
