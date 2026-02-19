// tracee.c
#include <stdio.h>
#include <unistd.h>

int x = 12345;    // globalna zmienna, której adres znamy

int main(void) {
    printf("tracee PID: %d\n", getpid());
    printf("address of x: %p\n", (void*)&x);
    fflush(stdout);

    // co sekundę wypisuj zmienną, żeby widzieć efekt (i mieć czas na attach)
    for (int i = 0; i < 60; ++i) {
        printf("tracee: x = %d\n", x);
        fflush(stdout);
        sleep(10);
    }
    return 0;
}

