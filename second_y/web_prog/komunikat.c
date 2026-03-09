#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {

	pid_t proces;
	int n;
	
	if((proces = fork()) == 0){
		// jestem forkiem!
		printf("(Potomek PID: %d): Podaj liczbe: ",getpid());
		scanf("%d",&n);
		exit(n);
	}else{
	
	wait(&n);
	
	printf("Macierz PID: %d): potomek o PID %d przekazal mi %d\n",getppid(),getpid(),WEXITSTATUS(n));
	}
	return 0;

}
