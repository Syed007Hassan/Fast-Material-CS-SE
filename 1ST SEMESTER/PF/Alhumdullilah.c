#include<stdio.h>
#include<string.h>
#include<windows.h>

int totalruns();
void dat();
void ven();
void inning();
void toss();
  struct cricketer
{
   
    char name[25];
}  
     t1[11],t2[11];     
 
int main()
{ 
   	system("color 5e");
   	char filen[50];

  FILE *ptr;
	 printf("WRITE NEW SCORESHEET\n");
		printf("Enter name of new scoresheet\n");
	 scanf("%s.bin", filen);
	 ptr=fopen(filen, "wb");             
	 if (ptr== NULL)
	 {
	 printf("failed to create new file");
	 }
	 
    int maxp1=0;
   	int max1=0;
    int totalruns1=0;
    int totalballs1=0;
    int totalwickets1=0;
    int totalovers1=0;
    int maxp2=0;
	   int max2=0;
    int totalruns2=0;
    int totalballs2=0;
    int totalwickets2=0;
    int totalovers2=0;
    char tmnm2[50];
    int subchoice1;
				int subchoice2;
	   char tmnm1[50];
	
	
	int i;
	int j;
	int c,c1;
	int n;
	int date;
	int year;
	
	printf("\t\t\t\t-------*---------\n");	
	printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t\t CRICKET SCORE BOARD\n");
	printf("\t\t\t----------------------------------------\n");
	printf("\t\t\t\t-------*---------\n");	
	
	dat();
	
	ven();

	printf("\t---------------------------------------------------------------\n");
	printf("\t\t\t\t*T20*\n");
	printf("\t---------------------------------------------------------------\n");
	
 printf("Enter the name of team 1\n");
 scanf("%s",tmnm1);
 fwrite(tmnm1,sizeof(tmnm1),1,ptr);   
 printf("Enter the name of team 2\n");
 scanf("%s",tmnm2);
 fwrite(tmnm2,sizeof(tmnm2),1,ptr);   
 printf("\t\t\t\t%s VS %s\n",tmnm1,tmnm2);
 printf("\t===============================================================\n");

    printf("ENTER NUMBER OF PLAYERS IN EACH TEAMS: (maximum 11)\n");
    scanf("%d",&n);
    y:
    printf("Enter players name of %s\n",tmnm1);
    
    for(i=1;i<=n;i++)
    {
        scanf("%s",t1[i].name);
    }
    
    fwrite(t1[i].name,sizeof(t1[i]),n,ptr);  
    printf("IF you want to change the player's name press y else n\n ");
    scanf(" %c",&c);

   if(c=='y')
			{
				goto y;
			}
			else if(c=='n')
			{
				goto q;
            }
  
    q:
    printf("\n\t\t\t\tPLAYERS OF %s\t\n",tmnm1);
    printf("\t===============================================================\n");
    
    for(i=1;i<=n;i++)
    {
    	  
        printf("\t\t\t\t\t%s\n",t1[i].name);
    
    }
    
  z:  
	  printf("Enter players name of %s\n",tmnm2);
	
    for(i=1;i<=n;i++)
    {
        scanf("%s",t2[i].name);
    }
    
    fwrite(t2[i].name,sizeof(t2[i]),n,ptr);  
    printf("IF you want to change the player's name press y else n\n ");
    scanf(" %c",&c1);
    
    
   if(c1=='y')
			{
				goto z ;
			}
			else if(c1=='n')
			{
				goto b ;
		 }    
            
    b:
    printf("\n\t\t\t\tPLAYERS OF %s\t\t\n",tmnm2);
    printf("\t===============================================================\n");
    
    for(i=1;i<=n;i++)
    {
        printf("\t\t\t\t\t%s\n",t2[i].name);
    }
    printf("\t---------------------------------------------------------------\n");

	char h;
	char t;
	char choice;
 printf("Which team won the toss\n");
 printf("Enter h if heads t for tail?\n");
 scanf("%s",&choice);
 
	switch (choice)
{
		case 'h':
		
			{
		    printf("\t===============================================================\n");
	     printf("\t---------------------------------------------------------------\n");
			   printf("\t\t\t\t%s won the toss\n",tmnm1);
			   printf("\t---------------------------------------------------------------\n");
			   printf("\t===============================================================\n");
			   printf("would you like to bat first or ball?\nEnter 1 for bat and 2 for ball\n");
			  
			  scanf("%d",&subchoice1);
			  switch(subchoice1)
			  {
			  	case 1:
			  		 printf("%s will bat first!!\n",tmnm1);
			  		 break;
			  	case 2:
						  printf("%s will ball first!!\n",tmnm1);
						  break;
					}
		    }
		break;
		case 't' :
	
			{
			printf("\t===============================================================\n");
	  printf("\t---------------------------------------------------------------\n");	
			printf("\t\t\t\t%s won the toss\n",tmnm2);
			
			printf("\t---------------------------------------------------------------\n");
			printf("\t===============================================================\n");
		 printf("would you like to bat first or ball?\nEnter 1 for bat and 2 for ball\n");
			 switch(subchoice2)
			 
			  {
			  	case 1:
			  		 printf("%s will bat first!!\n",tmnm2);
			  		 break;
			  	case 2:
						  printf("%s will ball first!!\n",tmnm2);
						  break;
					}
			}
			break;
}
	
	inning();
	
struct battingscore1
{
	char plyrname1[30];
	int runs1;
	int balls1;
};
	
 {
 struct battingscore1 p[50];
	printf("Enter the number of batsmen:\n");
	scanf("%d",&n);
	printf("Enter the batsmen name,runs and ball played by them:\n");
	
	for(i=0;i<n;i++)
	{
	
	scanf("%s %d %d",&p[i].plyrname1,&p[i].runs1,&p[i].balls1);
	
    }
    
 fwrite(tmnm1,sizeof(struct battingscore1),n,ptr);    
 printf("\tPLAYER NAME\t\t\tRUNS\t\t\tBALLS\n\n");
 printf("\t===============================================================\n");
 
 
		for(i=0;i<n;i++)
	    {
	 		printf("\t%s\t\t\t\t%d\t\t\t%d\n",p[i].plyrname1,p[i].runs1,p[i].balls1);
	 		 totalruns1=totalruns1+p[i].runs1;
	 		 totalballs1+=p[i].balls1;
		}
		   
     printf("\n---------------------------------------------\n");
     printf("Total Runs Scored by Team: %d\n",totalruns1);
     printf("\n---------------------------------------------\n");
     printf("Total balls played by Team: %d\n",totalballs1);
    
     j=0; 	
     maxp1=0;
	 while(p[j].runs1>maxp1)
	{
		maxp1=p[j].runs1;	
	    printf("\n---------------------------------------------\n");
	    printf("Highest runs %d",maxp1);
	    j++;
    }
 float avg1=totalruns1/n;
    printf("\n----------------------------------------------\n");
    printf("The average score of the team is = %.2f\n",avg1);   
    printf("\n----------------------------------------------\n");
}

struct bowlingscore1
{
	char bowlername1[30];
	int wickets1;
	int overs1;
};
	
{
struct bowlingscore1 b[50];
	printf("Enter the number of bowlers:\n");
	scanf("%d",&n);
	printf("Enter the bowlers name,wickets taken and overs bowled by him:\n");
	for(i=0;i<n;i++)
	{
	
	scanf("%s %d %d",&b[i].bowlername1,&b[i].wickets1,&b[i].overs1);
	
    }
     fwrite(tmnm1,sizeof(struct bowlingscore1),n,ptr); 
 
 printf("\tPLAYER NAME\t\t\tWICKETS\t\t\tOVERS\n\n");
 printf("\t===============================================================\n");
 
		for(i=0;i<n;i++)
	    {
	 		printf("\t%s\t\t\t\t%d\t\t\t%d\n",b[i].bowlername1,b[i].wickets1,b[i].overs1);
	 		totalwickets1+=b[i].wickets1;
	 		totalovers1+=b[i].overs1;
		}
		
     printf("\n---------------------------------------------\n");
     printf("Total wickets taken by Team: %d\n",totalwickets1);
     printf("\n---------------------------------------------\n");
     printf("Total overs played by Team: %d\n",totalovers1);
     
     j=0;
     max1=0;
     while(b[j].wickets1>max1)
	{
		max1=b[j].wickets1;	
		++j;
	}
	
	
	printf("\n---------------------------------------------\n");
	printf("highest wicket taker has taken %d wickets..\n",max1);
    printf("\n---------------------------------------------\n");

}
int target;
target=totalruns1+1;
printf("\t===============================================================\n");
printf("\t\t\t\t TARGET is %d in 20 OVERS\n",target);
printf("\t===============================================================\n");

inning();

struct battingscore2
{
	char plyrname2[30];
	int runs2;
	int balls2;
};	

{
struct battingscore2 p[50];
	printf("Enter the number of batsmen:\n");
	scanf("%d",&n);
	printf("Enter the batsmen name,runs and ball played by them:\n");
	for(i=0;i<n;i++)
	{
	
	scanf("%s %d %d",&p[i].plyrname2,&p[i].runs2,&p[i].balls2);
	
    }
    
 fwrite(tmnm2,sizeof(struct battingscore2),n,ptr);    
 printf("\tPLAYER NAME\t\t\tRUNS\t\t\tBALLS\n\n");
 printf("\t===============================================================\n");
		for(i=0;i<n;i++)
	    {
	 		printf("\t%s\t\t\t\t%d\t\t\t%d\n",p[i].plyrname2,p[i].runs2,p[i].balls2);
	 		 totalruns2=totalruns2+p[i].runs2;
	 		 totalballs2+=p[i].balls2;
		}   
     printf("\n---------------------------------------------\n");
     printf("Total Runs Scored by Team: %d\n",totalruns2);
    printf("\n---------------------------------------------\n");
     printf("Total balls played by Team: %d\n",totalballs2);
    
     j=0; 	
     maxp2=0;
	 while(p[j].runs2>maxp2)
	{
		maxp2=p[j].runs2;	
	    printf("\n---------------------------------------------\n");
	    printf("Highest runs %d",maxp2);
	    j++;
    }
 float avg2=totalruns2/n;
    printf("\n----------------------------------------------\n");
    printf("The average score of the team is = %.2f\n",avg2);   
    printf("\n----------------------------------------------\n");
}


struct bowlingscore2
{
	char bowlername2[30];
	int wickets2;
	int overs2;
};
	
{
struct bowlingscore2 b[50];
	printf("Enter the number of bowlers:\n");
	scanf("%d",&n);
	printf("Enter the bowlers name,wickets taken and overs bowled by him:\n");
	
	
	for(i=0;i<n;i++)
	{
	
	scanf("%s %d %d",&b[i].bowlername2,&b[i].wickets2,&b[i].overs2);
	
    }
    fwrite(tmnm2,sizeof(struct bowlingscore2),n,ptr); 
 
 printf("\tPLAYER NAME\t\t\tWICKETS\t\t\tOVERS\n\n");
 printf("\t===============================================================\n");
 
		for(i=0;i<n;i++)
	    {
	 	  	printf("\t%s\t\t\t\t%d\t\t\t%d\n",b[i].bowlername2,b[i].wickets2,b[i].overs2);
	 		  totalwickets2+=b[i].wickets2;
	 		  totalovers2+=b[i].overs2;
		}
		
     printf("\n---------------------------------------------\n");
     printf("Total wickets taken by Team: %d\n",totalwickets2);
     printf("\n---------------------------------------------\n");
     printf("Total overs played by Team: %d\n",totalovers2);
     
     j=0;
     max2=0;
     while(b[j].wickets2>max2)
	{
		max2=b[j].wickets2;	
		++j;
	}
	
   	printf("\n---------------------------------------------\n");
	   printf("highest wicket taker has taken %d wickets..\n",max2);
    printf("\n---------------------------------------------\n");

    fclose(ptr);
}
{

if(totalruns2<target)
{
	printf("\t===============================================================\n");
	printf("\t\t\t%s WON THE MATCH\n",tmnm1);
	printf("\t===============================================================\n");
}
else if(totalruns2>target)
{
	printf("\t===============================================================\n");
	printf("\t\t\t%s WON THE MATCH\n",tmnm2);
	printf("\t===============================================================\n");
}
 else if (totalruns1==totalruns2)
{
	printf("\t===============================================================\n");
	printf("\t\t\tTHIS MATCH IS TIED\n");
	printf("\t===============================================================\n");
}
}
}
void dat()
{
	
	int date;
	char month[30];
	int year;
	printf("\tEnter DATE MONTH YEAR\n");
	scanf("%d %s %d",&date,&month,&year);
	printf("\t===============================================================\n");
	printf("\t---------------------------------------------------------------\n");
	printf("\tDate : %d\t\t Month : %s\t\t Year : %d\t\t \n",date,month,year);
	printf("\t---------------------------------------------------------------\n");
	printf("\t===============================================================\n");
}

void ven()
{
	char venue[50]; 
	printf("ENTER VENUE\n");	
	scanf("%s",&venue);

	printf("\t---------------------------------------------------------------\n");
	printf("\t\t\t\tVENUE\n ");
	printf("\t\t\t\t%s\n",venue);
	printf("\t---------------------------------------------------------------\n");
	
}

void inning()
{
	int a;
	x:
		
	printf("Enter the inning 1 for first and 2 for second inning\n ");
	scanf("%d",&a);
	if(a==1 || a==2)
	printf("\n");
	
	else
	{
		printf("Invalid Number entered\n");
	    goto x;
	    
	}
	    
	switch(a)
	{
	case 1:
    {

		printf("\t\t\t\t   FIRST INNING\n");
	    printf("\t\t\t\t===================\n");
		break;
     
    }
	case 2:
	{
	
		printf("\t\t\t\t   SECOND INNING\n");
		printf("\t\t\t\t===================\n");
		break;
    
	}

}

}
