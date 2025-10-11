
#include <stdio.h>
#include <string.h>

int main(void){
	
	int i = 0;
	
	char idk[] = "abc";
	
	printf("%ld\n",sizeof(idk));
	printf("%ld\n",strlen(idk));
	
	for( ; i < sizeof(idk) ; i++){
		printf("%c %d\n",idk[i],idk[i]);
	}
	
	return 0;
}
