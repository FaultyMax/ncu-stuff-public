#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/* bez obslugi bledow! */

int main() {

	pid_t potomek;
	int n = 100;

	if((potomek = fork()) == 0) {  /* proces potomny */
		
		printf("Potomek: PID: %d, PPID %d\n",
				getpid(), getppid());
		n = n + 10;


	} else { /* proces macierzysty */
		
		printf("Macierz: PID: %d, PPID %d, PID potomka: %d\n",
				getpid(), getppid(), potomek);
		n = n + 20;

	}

	n = n + 1000;
	printf("Napis wyswietlany przez oba procesy: n = %d\n", n);
	exit(0);
	
}
