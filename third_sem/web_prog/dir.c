#include <stdio.h>
#include <dirent.h>
#include <string.h>

// brak obslugi bledow!

int main() {
	DIR* dirp;
	struct dirent* direntp;

	dirp = opendir("."); // zwraca DIR*
	for(;;) {
		direntp = readdir(dirp);
		if(direntp == NULL) {break;}
		if(strcmp()); // DOKONCZ		
		printf( "%s\n", direntp->d_name);
	}
	
	closedir(dirp);																			    
	return 0;
}
