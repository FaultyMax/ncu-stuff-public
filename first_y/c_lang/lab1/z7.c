
#include <stdio.h>

int wynik = 0;

int main(void){
	
	int i = 0; /* w założeniu że 0 jest naturalne */
	for(; i < 10;i++){
		wynik += i;
	}
	
	printf("%d\n",wynik);
	
	return 0;
}
