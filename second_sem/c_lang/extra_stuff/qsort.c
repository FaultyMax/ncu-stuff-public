
#include <stdio.h>
#include <stdlib.h>

int compar(const void* a, const void* b){
	
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	
	return arg1 - arg2;
}

int main(void){
	
	int arr[5] = {5,3,8,1,2};
	int i;
	for(i = 0 ; i < 5 ; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	qsort(arr,5,sizeof(int),compar);
	for(i = 0 ; i < 5 ; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return 0;
}
