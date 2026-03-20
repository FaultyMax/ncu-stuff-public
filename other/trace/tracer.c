// tracer.c
#define _GNU_SOURCE
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

    int new_one = 54321;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <hex-address>\nExample: %s 12345 0x7ffd1234abcd\n", argv[0], argv[0]);
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    unsigned long addr = strtoul(argv[2], NULL, 0); // odczyt adresu w hex lub dec

    // Attach
    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        perror("ptrace(ATTACH)");
        return 1;
    }

    // Czekaj aż tracee zatrzyma się
    int status;
    if (waitpid(pid, &status, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status)) {
        fprintf(stderr, "Target exited\n");
        ptrace(PTRACE_DETACH, pid, NULL, NULL);
        return 1;
    }

    errno = 0;
    long data = ptrace(PTRACE_PEEKDATA, pid, (void*)addr, NULL);
    if (data == -1 && errno) {
        perror("ptrace(PEEKDATA)");
        ptrace(PTRACE_DETACH, pid, NULL, NULL);
        return 1;
    }

    // int prawdopodobnie 4 bajty — wydobądź
    int value;
    memcpy(&value, &data, sizeof(int)); // bezpieczne względem endianness
    printf("Read at %p : int = %d (0x%x)\n", (void*)addr, value, value);

    // Odłącz i pozwól tracee działać dalej
    if (ptrace(PTRACE_DETACH, pid, NULL, NULL) == -1) {
        perror("ptrace(DETACH)");
        return 1;
    }

    return 0;
}

