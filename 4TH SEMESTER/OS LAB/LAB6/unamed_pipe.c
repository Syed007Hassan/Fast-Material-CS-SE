#include<stdio.h>
#include<unistd.h>

int main(void) {
	int pipefd[2];
	int pid;
	char buffer[15];
	pipe(pipefd);
	pid = fork();

	if(pid > 0) {
		fflush(stdin);
		printf("unamed_pipe [INFO] Parent Process\n");
		write(pipefd[1],"Hellow Mr.Linux",15);
	}
	else if(pid == 0) {
		sleep(5);
		fflush(stdin);
		printf("unamed_pipe [INFO] Child Process\n");
		read(pipefd[0], buffer, sizeof(buffer));
		write(1,buffer, sizeof(buffer));
		printf("\n");	
	}
	else {
		printf("unamed_pipe [ERROR] Error in creating child process\n");	
	}
	if(pid > 0) wait();
	return 0;
}





































































#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include<unistd.h>
#include<sys/wait.h>



int main(){

  int p1,p2,p3,p4,i;

 p1 = fork();

 if(p1){
   wait(NULL);
  // sleep(3);
   printf("P1 \n");
  
   system("/home/syed/sh.sh");

}

 if(!p1){

  printf("P1 \n"); }
  


return 0;



}
	
