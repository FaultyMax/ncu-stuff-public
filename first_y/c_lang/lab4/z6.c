
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* copy(void* ptr,int n,int type);

int main(void){
	
	int arr[20];
	int i;
	
	for(i = 0 ; i < 20 ; i++){
		arr[i] = i;
	}
	
	int* ptr = (int*)copy(arr,20,sizeof(int));
	
	for(i = 0 ; i < 20 ; i++){
		printf("%d\n",ptr[i]);
	}
	
	free(ptr);
	ptr = NULL;
	
	return 0;
}


void* copy(void* ptr,int n,int type){
	
	void* new = malloc(n * type);
	
	memcpy(new, ptr, n * type);
	
	return new;
	
}
