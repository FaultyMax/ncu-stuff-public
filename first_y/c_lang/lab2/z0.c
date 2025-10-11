
#include <stdio.h>

int tab[4][6];

int main(void){
	
	int c = 0;
	int i, j;
	
	for(i = 0 ; i < 4; i++){
		for (j = 0 ; j < 6 ; j++){
			tab[i][j] = c;
			printf("%d ",tab[i][j]);
			c += 2;
		}
		printf("\n");
		
	}
	
	return 0;
}
