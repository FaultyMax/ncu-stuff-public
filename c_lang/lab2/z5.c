
#include <stdio.h>

int main(void){
	
	char tab[10][10];
	int i,j;
	
	for(i = 0 ; i < 10 ; i++){
		
		for(j = 0 ; j < 10 ; j++){
			
			if( (j + i) % 2 == 0){
			
				tab[i][j] = '_';
			
			}
			else{
				
				tab[i][j] = '#';
				
			}
			
			printf("%c",tab[i][j]);
			
		}
		printf("\n");
	}
	
	
	
	return 0;
	
}
