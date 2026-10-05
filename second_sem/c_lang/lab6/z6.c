
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	
	int* pointer;
	int size;
	
} Array;

Array* create_array(int n){
	
	Array* new_arr = (Array*)malloc(sizeof(Array));
	new_arr->size = n;
	new_arr->pointer = (int*)malloc(new_arr->size*sizeof(int));
	
	return new_arr;
}

void free_space(Array** arr){
	
	if (arr && *arr){
		
		free((*arr)->pointer);
		(*arr)->pointer = NULL;
		free(*arr);
		*arr = NULL;
		
	}
	
}

int main(int argc, char* argv[]){

	int i;
	int n = 10;
	
	Array* ptr_arr = create_array(n);
	
	for(i = 0 ; i < ptr_arr->size ; i++){
		
		ptr_arr->pointer[i] = (i+1)*(i+1);
		printf("%d\n",ptr_arr->pointer[i]);
		
	}

	free_space(&ptr_arr);
	
	return 0;
	
}
