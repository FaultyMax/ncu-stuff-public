
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	int i;
	
	
	/*
	printf("%d\n",argc);
	printf("%s\n",argv[0]);
	*/
	
	for(i = 0 ; i < argc ; i++){
		printf("Argument numer %d: %s\n",i+1,argv[i]);
	}
	
	return 0;
	
}
