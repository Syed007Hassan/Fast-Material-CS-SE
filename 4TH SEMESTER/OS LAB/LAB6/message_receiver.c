#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf {
	long mtype;
	char msgtxt[200];
};

int main(void) { 
	struct msgbuf msg;
	int msgid;
	key_t key;

	if((key = ftok("message_send.c",'b')) == -1 ) {
		perror("key");
		exit(1);
	}
	
	if((msgid=msgget(key,0644)) == -1 ) {
		perror("msgid");
		exit(1);
	}
	for(;;) {
		if(msgrcv(msgid,&msg,sizeof(msg),1,0) == -1) {
			perror("msgrcv");
			exit(1);		
		}
		printf("message_receive [INFO] Message: %s\n",msg.msgtxt);
	}

	return 0;
}


	

