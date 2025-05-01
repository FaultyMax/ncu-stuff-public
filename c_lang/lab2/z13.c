
#include <stdio.h>

int tab[9] = {1,2,3,4,5,4,3,2,1};

int n = 9;

int main(void){
	
	int i,j;
	
	j = n-1;
	
	for(i=0 ; i < (n/2)+1 ; i++){
		
		if(tab[i] != tab[j]){
			printf("nie palindrom\n");
			break;
		}
		j--;
	}
	
	if(i == (n/2)+1){
		printf("palindrom\n");
	}
	
	return 0;
}
