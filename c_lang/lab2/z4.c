
#include <stdio.h>

int main(void){
	
	int tab[5][7] = {0};
	int n = 0;
	int i = 0;
	int j = 0;
	
	scanf("%d",&n);
	
	for( ; i < 5 ; i++ ){
		for( ; j < 7 ; j++ ){
			tab[i][j] = n;
			n++;
			printf("%d ",tab[i][j]);
		}
		j = 0;
		printf("\n");
	}
	
	return 0;
}
