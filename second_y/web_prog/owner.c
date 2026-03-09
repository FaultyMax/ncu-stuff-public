#include<stdio.h>
#include<sys/types.h>
#include<pwd.h>
#include <grp.h>
#include<sys/stat.h>

/* Brak obslugi bledow! */

int main(int argc, char **argv) {

	struct stat statbuf;
	
	struct passwd *pwd;
	struct group *grp;

	stat(argv[1], &statbuf);
	
	pwd = getpwuid(statbuf.st_uid);
	
	grp = getgrgid(statbuf.st_gid);
	
	printf("Wlasciciel: %s\n", pwd -> pw_name);
	printf("Grupa: %s\n", grp -> gr_name);

	return 0;
}
