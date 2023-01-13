#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27

void die(char *str) {
	perror(str);
	exit(1);
}

int main(void) {
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	key = 2211;
	
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");
	s = shm;
	for(c = 'a'; c <= 'z'; c++) 
		*s++ = c;

	while(*shm != '*')
		sleep(1);

	exit(0);
}

