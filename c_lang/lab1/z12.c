
#include <stdio.h>

int n = 0;

int wynik = 0;

int tmp = 0;

int main(void){
	
	int i = 1;
	
	scanf("%d",&n);
	
	scanf("%d",&wynik);
	
	for(; i < n ; i++){
		
		scanf("%d",&tmp);
		
		if(wynik < tmp){
		
			wynik = tmp;
			
		}
		
	}
	
	printf("%d\n",wynik);
	
	return 0;
}
