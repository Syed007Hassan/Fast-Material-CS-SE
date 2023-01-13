#include<stdio.h>
int main(){
	int account;
	char name[30];
	double balance;
	
	FILE *cptr;
	
	if((cptr=fopen("clients.txt","r+"))== NULL){
		puts("FILE COULD NOT BE OPENED");
	}
	
	else{
	//	fscanf(cptr,"%d %s %lf",&account,name,&balance);
	
	while(!feof(cptr)){
		
		fscanf(cptr,"%d %s %lf" ,&account,name,&balance);
		printf("%d %s %.2f\n",account,name,balance);
	}

    fclose(cptr);

} 

}
