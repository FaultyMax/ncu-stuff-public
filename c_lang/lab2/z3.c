
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int tab[20] = {0};

float avrg = 0;

int max = 0;

int main(void){
	
	int i = 0;
	
	srand(time(NULL));
	
	for(; i < 20 ; i++){
		tab[i] = rand() % 101;
		avrg += tab[i];
		if(tab[i] > max){
			max = tab[i];
		}
		printf("%d\n",tab[i]);
	}
	
	printf("Wartość największa: %d\nŚrednia: %f\n",max,avrg/20); 
	
	return 0;
}
