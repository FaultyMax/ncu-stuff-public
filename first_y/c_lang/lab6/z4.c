
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	
	int* pointer;
	int size;
	
} Array;

Array create_array(int n){
	
	Array new_arr;
	new_arr.size = n;
	new_arr.pointer = (int*)malloc(new_arr.size*sizeof(int));
	
	return new_arr;
}

void free_space(Array* arr){
	
	free(arr->pointer);
	arr->pointer = NULL;
	
}

int main(int argc, char* argv[]){

	int i;
	int n = 10;
	
	Array powers = create_array(n);
	
	for(i = 0 ; i < powers.size ; i++){
		
		powers.pointer[i] = (i+1)*(i+1);
		printf("%d\n",powers.pointer[i]);
		
	}

	free_space(&powers);

	return 0;
	
}
