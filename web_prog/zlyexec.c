#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {

	pid_t proces;
	
	printf("Uruchamiam ls -l za pomoca exec\n");
	if((proces = fork()) == 0){
		execlp("ls","ls","-l", (char *)0);
	}
	wait(0);
	printf("Wazny komunikat na koniec\n");
	return 0;

}
