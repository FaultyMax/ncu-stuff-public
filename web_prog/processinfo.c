#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pwd.h>
#include<grp.h>


int main() {

	struct passwd *uzyt;
	struct group  *grupa;
	uid_t uzytid;
	gid_t grpid;
	pid_t pid;
	pid_t ppid;
	pid_t pgrp;
	
	uzytid = getuid();
	uzyt = getpwuid(uzytid);
	printf("Rzeczywisty uzytkownik (id, nazwa):  %4d, %s\n",
		uzytid, uzyt->pw_name); 


	grpid = getgid();
	grupa = getgrgid(grpid);
	printf("Rzeczywista grupa (id, nazwa):       %4d, %s\n",
		grpid, grupa -> gr_name);

	uzytid = geteuid();
	uzyt = getpwuid(uzytid);
	printf("Obowiazujacy uzytkownik (id, nazwa): %4d, %s\n",
		uzytid, uzyt->pw_name);

	
	grpid = getegid();
	grupa = getgrgid(grpid);
	printf("Obowiazujaca grupa (id, nazwa):      %4d, %s\n",
		grpid, grupa -> gr_name);

	pid = getpid();
	ppid = getppid();
	pgrp = getpgrp();

	printf("PID: %u, PPID: %d, PGRP: %d\n",pid,ppid,pgrp);

	return 0;

}
