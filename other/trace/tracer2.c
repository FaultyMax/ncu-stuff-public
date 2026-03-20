#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <address>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    unsigned long addr = strtoul(argv[2], NULL, 0);

    // Attach
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        perror("ptrace(ATTACH)");
        return 1;
    }
    waitpid(pid, NULL, 0);

    // Odczytaj starą wartość
    errno = 0;
    long data = ptrace(PTRACE_PEEKDATA, pid, (void*)addr, NULL);
    if (data == -1 && errno) {
        perror("ptrace(PEEKDATA)");
        goto detach;
    }

    int old_value;
    memcpy(&old_value, &data, sizeof(int));
    printf("Old value at %p: %d\n", (void*)addr, old_value);

    // Przygotuj nową wartość
    int new_value = 54321;
    memcpy(&data, &new_value, sizeof(int));

    // Zapisz nową wartość w pamięci tracee
    if (ptrace(PTRACE_POKEDATA, pid, (void*)addr, (void*)data) == -1) {
        perror("ptrace(POKEDATA)");
        goto detach;
    }

    printf("New value %d written to %p\n", new_value, (void*)addr);

detach:
    ptrace(PTRACE_DETACH, pid, NULL, NULL);
    return 0;
}

