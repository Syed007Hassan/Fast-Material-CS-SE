#include<stdio.h>
int main(){
	int i,j; int cand1=0,cand2=0,cand3=0,cand4=0;
	float perct1,perct2,perct3,perct4;
	int totalv;
	int arr[5][5]={     {1,192,48,206,37},
	                    {2,147,90,312,21},
	                    {3,186,12,121,38},
						{4,114,21,408,39},
						{5,267,13,382,29},
																
	              };
	int (*ptr)[5]=arr;              
	              
printf("\tThe results from the mayor's race have been reported by each precinct as follows:\n\n");  
printf("         Precinct        Candidate(A)        Candidate(B)        Candidate(C)       Candidate(D)\n");
printf("        ________________________________________________________________________________________");
printf("\n");
	        

for(i=0;i<5;i++){
	for(j=0;j<5;j++){
		printf("%18d",*(*(ptr+i)+j)
	}

printf("\n");

}
printf("        ________________________________________________________________________________________");



for(i=0;i<5;i++){
	for(j=1;j<=1;j++){
		cand1= *(*(ptr+i)+j) + cand1;
	}
	
}
printf("\n");


for(i=0;i<5;i++){
	for(j=2;j<=2;j++){
		cand2= *(*(ptr+i)+j)+ cand2;
	}
	
}
printf("\n");


for(i=0;i<5;i++){
	for(j=3;j<=3;j++){
		cand3= *(*(ptr+i)+j) + cand3;
	}
	
}
printf("\n");


for(i=0;i<5;i++){
	for(j=4;j<=4;j++){
		cand4=*(*(ptr+i)+j)  + cand4;
	}
	
}
printf("\n");

totalv=cand1+cand2+cand3+cand4;
printf("\tThe total no of votes casted are: %d \n\n\t",totalv);

printf("Candidate A got %d votes\n\t",cand1);
perct1=(float)cand1 / totalv *100;
printf("The Percent of votes is %.2f%% \n\n\t",perct1);

printf("Candidate B got %d votes\n\t",cand2);
perct2= (float)cand2 / totalv *100;
printf("The Percent of votes is %.2f%% \n\n\t",perct2);

printf("Candidate C got %d votes\n\t",cand3);
perct3= (float)cand3 / totalv *100;
printf("The Percent of votes is %.2f%% \n\n\t",perct3);

printf("Candidate A got %d votes\n\t",cand4);
perct4= (float)cand4 / totalv *100;
printf("The Percent of votes is %.2f%% \n\n\t",perct4);

if(perct1 > 50){
	printf("Candidate A is the winner\n\t");
}
else if(perct2 > 50){
	printf("Candidate B is the winner\n\t");
	
}
else if(perct3 > 50 ){
	printf("Candidate C is the winner\n\t");
}
else if(perct4 > 50){
	printf("Candidate D is the winner\n\t");
}
//this condition is particularly for 108 votes for Candidate C in precinct 4

if((perct1 < 50) && (perct2 < 50) && (perct3 < 50) && (perct4 < 50))
{        
	if(perct1 > perct2 && perct3 > perct4)
		printf("Candidate A and Candidate C got highest vote\n\t");
	else if(perct2 > perct1 && perct4 > perct3)
		printf("Candidate B and Candidate D got highest vote\n\t");
	else if(perct1 > perct4 && perct2 > perct3)
		printf("Candidate A and Candidate B got highest vote\n\t");
	else if(perct4 > perct1 && perct3 > perct2)
		printf("Candidate C and Candidate D got highest vote\n\t");
	
}


return 0;

}

