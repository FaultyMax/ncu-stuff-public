
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	int n = atoi(argv[1]);
	int i;
	int j;
	
	for(i = 0 ; i < n ; i++){
		
		for(j = n ; j > n-i-1 ; j--){
			printf("*");
		}
		printf("\n");
	}
	
	return 1;
}
