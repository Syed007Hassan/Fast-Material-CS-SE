#include <stdio.h>
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <pthread.h>  // POSIX Threads
#include <semaphore.h> // Semaphore 
#include <sys/types.h> 
#include <errno.h> 


  sem_t s; // a counting semaphore 
    
    //N -> S
    void *P1() {
          printf("Car about to enter from North.\n");
	sem_wait(&s);
	printf("Car moves North to South.\n");
	sem_post(&s);
	printf("Car exits from South.\n");
            }
    
    
    //W -> E
    void *P2() {
        printf("Car about to enter from West.\n");
        sem_wait(&s);
        printf("Car moves West to East.\n");
        sem_post(&s); 
        printf("Car exits from East.\n");
        }

int main() {
	
	int c = 0;
	pthread_t t1, t2, t3, t4, t5, t6;   
	sem_init(&s,1,3);  //initializing the value to 3 since at intersection 
                           //section at most 3 cars can enter
	while(1){
	//creating 6 threads t1,t2,t3,t4,t5,t6 and assigning each funtion 3	
	
	pthread_create(&t1,NULL,P1,NULL);
	pthread_create(&t2,NULL,P1,NULL);
	pthread_create(&t3,NULL,P1,NULL);
	
	pthread_create(&t4,NULL,P2,NULL);
	pthread_create(&t5,NULL,P2,NULL);
	pthread_create(&t6,NULL,P2,NULL);

    //joining all those threads 
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL); 
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	pthread_join(t6,NULL);	
	}
	
	return 0;
}


