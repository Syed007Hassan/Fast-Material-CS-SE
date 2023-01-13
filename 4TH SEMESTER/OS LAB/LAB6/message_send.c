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
	
	if((msgid=msgget(key,0644|IPC_CREAT)) == -1 ) {
		perror("key");
		exit(1);
	}
	printf("message_send [INFO] The message ID is: %d\n", msgid);
	printf("message_send [PROMPT] Enter a text: ");
	msg.mtype = 1;
	while(gets(msg.msgtxt),!feof(stdin)) { 
		if(msgsnd(msgid,&msg,sizeof(msg),0) == -1) {
			perror("msgsnd");
			exit(1);
		}
	}

	if(msgctl(msgid,IPC_RMID,NULL) == -1) {
		perror("msgctl");
		exit(1);
	}
	return 0;
}

//to delete the msgid through command line with can use the following command
// ipcrm -q <msgid>

	

