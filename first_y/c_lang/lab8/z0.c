
#include <stdio.h>

int main(void){
	
	FILE *plik = fopen("files/text1.txt","r");

	if(plik == NULL){ return 1; }
	/*
	char line[256];

	while(fgets(line,sizeof(line),plik) != NULL){
	
		printf("%s",line);
		
	}
	*/
	int c = 0;

	while((c = fgetc(plik)) != EOF){
		
		if(c >= '0' && c <= '9'){
			//printf("%c",c);
			fputc(c,"wynik.txt");
		}
		
	}

	fclose(plik);
	return 0;
}
