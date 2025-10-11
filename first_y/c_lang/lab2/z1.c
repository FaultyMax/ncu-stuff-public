
#include <stdio.h>

int tab[20];

int main(void){
	
	int i = 0;
	
	for( ; i < 20 ; i++ ){
	
		tab[i] = (i+1) * (i+1);
		
	}
	
	/* printf("%d\n",tab[10]); */
	
	return 0;
}
