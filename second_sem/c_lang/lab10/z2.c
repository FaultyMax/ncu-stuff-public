
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
	
	const int* wskA = (const int*)a;
    const int* wskB = (const int*)b;
	
	return (*(wskA) - *(wskB));
}

int main(void){
	
	int i;
	
	int tablica[20];
	
	for(i = 0 ; i < 20 ; i++){
		
		tablica[i] = rand() % 1500;
		
		printf("%d\n",tablica[i]);
		
	}
	
	qsort(tablica,20,sizeof(int),compare);
	
	printf("Posortowane:\n");
	
	for(i = 0 ; i < 20 ; i++){
		
		printf("%d\n",tablica[i]);
		
	}
	
	return 0;
}
