
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
} Firma;

int main() {
    int n = 10;
    int i = 0;
    Firma* firmy = malloc(n * sizeof(Firma));
    if (firmy == NULL) {
        perror("malloc");
        exit(1);
    }

    for (; i < n; i++) {
        snprintf(firmy[i].name, sizeof(firmy[i].name), "firma%d", i + 1);
        printf("Firma: %s\n", firmy[i].name);
    }

    free(firmy);
    return 0;
}
