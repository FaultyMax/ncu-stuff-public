
#include <stdio.h>
#include <stdlib.h>

int* fill(int n, int x);

int main(void){
	
	int* my_array = fill(5,33);
	
	printf("index 2: %d\n",my_array[2]);
	
	free(my_array);
	my_array = NULL;
	
	return 0;
}

int* fill(int n,int x){
	
	int i = 0;
	int* arr = (int*)malloc(n * sizeof(int));
	
	if(arr == NULL){
		printf("allocation fail.\n");
		return NULL;
	}
	
	for( ; i < n ; i++){
		printf("index %d\n",i);
		arr[i] = x;
	}
	
	return arr;
	
}
