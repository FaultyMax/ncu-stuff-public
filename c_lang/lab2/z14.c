
#include <stdio.h>

int zlicz(int tab[],int n){
	
	int j;
	int count = 0;
	
	for(j = 0; j < 10 ; j++){
		
		if(n == tab[j]){
			count++;
			tab[j] = 0;
		}
		
	}
	
	return count;
	
}

int l[10] = {0};

int main(void){
	
	int i,n;
	
	for(i = 0 ; i < 10 ; i++){
		scanf("%d",&l[i]);
	} 
	
	printf("szukana liczba?\n");
	
	scanf("%d",&n);
	
	printf("liczba wystąpień: %d\n",zlicz(l,n));
	
	return 0;
}
