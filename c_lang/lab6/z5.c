
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	
	char title[32];
	int sum;
	
} Bill;

Bill total_bill(Bill* arr,int n){

	Bill zbiorczy = {0};
	int j = 0;
	
	strcpy(zbiorczy.title,"Rachunek zbiorczy");
	
	for( ; j < n; j++){
		
		zbiorczy.sum += arr[j].sum;
		
	}
	
	return zbiorczy;
}

void wypisz(Bill* arr,int n){

	int k;
	
	for(k = 0 ; k < n ; k++){
	
		printf("Rachunek \"%s\": %d\n",arr[k].title,arr[k].sum);
		
	}
	
}

int main(void){
	
	/* printf("%ld\n",sizeof(Bill)); */
	
	int n = 10;
	int i = 0;
	Bill zbiorczy;
	
	Bill* ptr = (Bill*)malloc(n * sizeof(Bill));
	
	for(i = 0 ; i < n ; i++){
		
		snprintf(ptr[i].title, sizeof(ptr[i].title), "firma%d",i+1);
		ptr[i].sum = (i+1) * 1000;
		
	}
	
	zbiorczy = total_bill(ptr,n);
	
	wypisz(ptr,n);
	
	printf("%s %d\n",zbiorczy.title,zbiorczy.sum);
		
	free(ptr);
	
	return 0;
	
}
