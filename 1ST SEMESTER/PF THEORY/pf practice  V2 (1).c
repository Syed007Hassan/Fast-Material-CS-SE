#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ans {
	char qq1[300];
};

struct ans a1[10]={ {"All except Seminar,'Semi' indicates half"},{"Except SAARC, all other are agency of UNO."},{"Skip First word forward and next word 2 backward"},
                    {"Skip First word 2 backward and second word forward"},{"5 You need to study the axis and direction carefully in order to solve it."},{"First diff of four and then diff of three btw nos"},
					{"Firstly the person is facing the south direction. From there, when he turns 135 degree anticlockwise then the direction is North East.Now again it is said that the person turns 180 degree clockwise so the direction will be southwest."},
                    {"8 Simple divide it."},{"9 Option 3 is the odd one because rest on the otions are in order in two pairs."},{"increment the skipping of alphabet from both patterns of A-Z & Z-A."}  };

void correctAnswer(char *option1,char *option2,char *option3,char *option4,char *option5,char *option6,char *option7,char *option8,char *option9,char *option10)
{
	int i;
	printf("\n\n\t\t\t\t\t*******************\n\t\t\t\t\t  Correct Answers\n\t\t\t\t\t*******************");
	printf("\n\nQ1. Pick the odd one out:");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option1+i));
		
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[0].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ2. Pick the odd one out:");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option2+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[1].qq1);

	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ3. If 'LCMHN' represents 'MANGO', then how will 'BOUTS' be represented:");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option3+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[2].qq1);
		
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ4. If 'RTTHHX' encodes for purify, then code for blanch will be: ");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option4+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[3].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ5. Ahsan,Akber,Arsalan,Salma and Bashir are standing facing north to the play ground such as \n Akber is at 40 m to the right of Salma\n Ahsan is in the 60 m to the south of Akber\n Arsalan is at distance of 25m to the west of Salma\n Bashir is at a distance of 90 m in the north of Ahsan.\n Which one is inthe north-east of the person who is to the left of Akbar?\n ");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option5+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[4].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ6. What are the next two numbers of this series:\n 1, 5, 2, 6, 3, 7, 4,___,____. ");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option6+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[5].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ7. If a boy facing towards south rotates his body 135 degress anti-clockwise, and then rotates 225 degress clockwise direction, which direction is he facing now?");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option7+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[6].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ8. Which fraction is larger. (perform without using calculator)");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
      printf("%c", *(option8+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[7].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ9. Choose the odd one out");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option9+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[8].qq1);
	printf("\n\n\t\t\t\t\t********************");
	
	printf("\n\nQ10. A Z B Y D W G T\nWhich letter comes next?");
	printf("\nAnswer: ");
	for(i=0;i<10;i++)
	{
		printf("%c", *(option10+i));
	}
	printf("\nSolution is:\n");
	printf("%s\n",a1[9].qq1);
	printf("\n\n\t\t\t\t\t********************");
}

int main()
{
	system("COLOR F0");
	
	FILE *fptr;
	FILE *cptr;
	
	char *ptr;
	int opt;
	
	char ch[100], name[30];
	int age, sum;
	 
	int option, i, ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10,ans11,ans12,ans13,ans14,ans15;
	
	char q1[4][20],q2[4][20],q3[4][20],q4[4][20],q5[4][20],q6[4][20],q7[4][20],q8[4][20],q9[4][20],q10[4][20];
	
	char option1[10] = "Seminar", option2[10] = "SAARC", option3[10] = "CMVST", option4[10] = "EMGCKD", option5[10] = "Bashir";
	char option6[10] = "(8, 5)", option7[10] = "West", option8[10] = "2/14", option9[10] = "JIST", option10[10] = "KP";
	
	strcpy(q1[0],"1. Seminar");
	strcpy(q1[1],"2. Semicircle");
	strcpy(q1[2],"3. Semicolon");
	strcpy(q1[3],"4. Semifinals");
	strcpy(q2[0],"1. SAARC");
	strcpy(q2[1],"2. WHO");
	strcpy(q2[2],"3. IMF");
	strcpy(q2[3],"4. UNICEF");
	strcpy(q3[0],"1. BMWSS");
	strcpy(q3[1],"2. CMVST");
	strcpy(q3[2],"3. DNVTS");
	strcpy(q3[3],"4. TSVNM");
	strcpy(q4[0],"1. DKDSHG");
	strcpy(q4[1],"2. AOCGTY");
	strcpy(q4[2],"3. DKCMEG");
	strcpy(q4[3],"4. EMGCKD");
	strcpy(q5[0],"1. Ahsan");
	strcpy(q5[1],"2. Salma");
	strcpy(q5[2],"3. Arslan");
	strcpy(q5[3],"4. Bashir");
	strcpy(q6[0],"1. (8, 5)");
	strcpy(q6[1],"2. (4, 8)");
	strcpy(q6[2],"3. (2, 3)");
	strcpy(q6[3],"4. (7, 9)");
	strcpy(q7[0],"1. South");
	strcpy(q7[1],"2. West");
	strcpy(q7[2],"3. East");
	strcpy(q7[3],"4. North");
	strcpy(q8[0],"1. 3/7");
	strcpy(q8[1],"2. 2/14");
	strcpy(q8[2],"3. 5/14");
	strcpy(q8[3],"4. 13/28");
	strcpy(q9[0],"1. LKCB");
	strcpy(q9[1],"2. IHJK");
	strcpy(q9[2],"3. HGLO");
	strcpy(q9[3],"4. JIST");
	strcpy(q10[0],"1. LM");
	strcpy(q10[1],"2. ST");
	strcpy(q10[2],"3. KP");
	strcpy(q10[3],"4. OP");
	
	
    printf("\n\t\t\t\t\t********************************\n\t\t\t\t\t\t~~QUIZ PROGRAM~~\n\t\t\t\t\t******************************** ");
	printf("\n\n\t**This program consist of 10 Questions that will test your brain and your capability of solving problems**");
	printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\n\t\t\t\t\t\t    =========\n\t\t\t\t\t\t    ~~Rules~~\n\t\t\t\t\t\t    =========\n");
	printf("\t1. If you truely want to know your IQ then you have to play if fair without taking help from anyone.");
	printf("\n\t2. You cannot take help from google.");
	printf("\n\t3. In MCQ's, Answer only by entering the correct option number.");
	printf("\n\t5. Every correct question will reward you point according to our marking scheme and you will get zero points on giving wrong answer.");
	printf("\n\t6. In the end the program will calculate your score and tell you where you stand in terms of IQ.");
	printf("\n\n\n\tPress any key to continue");
	getch();
	system("cls");
	
	printf("\n\n\n\t\t\t\t\t********************************\n\t\t\t\t\t\t ~~Let's Begin~~\n\t\t\t\t\t********************************");

	
	struct data
	{
		char name[20];
		int age;
	};
	
	struct data d;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t================================\n\t\t\t\t\tEnter your name: ");
	gets(d.name);
	printf("\t\t\t\t\t================================");
	printf("\n\n\n\t\t\t\t\t================================\n\t\t\t\t\tEnter your age: ");
	scanf("%d", &d.age);
	printf("\t\t\t\t\t================================");
	getch();
	
do
{
	system("cls");
	
	system("COLOR F5");
	printf("\n\n\n\n\n\n\t\t\t\t\t***************************\n  \t\t\t\t\t\t  ~~MENU~~");
	printf("\n\t\t\t\t\t***************************");  
    printf("\n \t\t\t\t\t1. Display Questions");    
    printf("\n \t\t\t\t\t2. Display Result");  
    printf("\n \t\t\t\t\t3. Save your Result");
    printf("\n \t\t\t\t\t4. View Scoreboard");
	printf("\n \t\t\t\t\t5. Exit"); 
    printf ("\n\t\t\t\t\t***************************");

	printf("\n\n\n \t\t\t\t\tEnter your option: "); 
	scanf("%d", &option); 

	
	system("COLOR F0");
	switch(option)
	{
		case 1:
		system("cls");
		
		printf("\n\nGood Luck ");
		puts(d.name);
		printf("***************************");

		
		printf("\nQ1. Pick the odd one out:");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q1[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans1);
		if(ans1==1)
		{
			sum=sum+1;
			printf("\nCorrect Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		system("cls");
		
		printf("Q2. Pick the odd one out:");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q2[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans2);
		if(ans2==1)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q3. If 'LCMHN' represents 'MANGO', then how will 'BOUTS' be represented:");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q3[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans3);
		if(ans3==2)
		{
			sum=sum+1;
			printf("Correct Answer\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		
			system("cls");
		
		printf("Q4. If 'RTTHHX' encodes for purify, then code for blanch will be: ");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q4[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans4);
		if(ans4==3)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q5. Ahsan,Akber,Arsalan,Salma and Bashir are standing facing north to the play ground such as \n Akber is at 40 m to the right of Salma\n Ahsan is in the 60 m to the south of Akber\n Arsalan is at distance of 25m to the west of Salma\n Bashir is at a distance of 90 m in the north of Ahsan.\n Which one is inthe north-east of the person who is to the left of Akbar?\n ");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q5[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans5);
		if(ans5==4)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q6. What are the next two numbers of this series:\n 1, 5, 2, 6, 3, 7, 4,___,____. ");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q6[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans6);
		if(ans6==1)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q7. If a boy facing towards south rotates his body 135 degress anti-clockwise, and then rotates 225 degress clockwise direction, which direction is he facing now?");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q7[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans7);
		if(ans7==2)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q8. Which fraction is larger. (perform with using calculator)");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q8[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans8);
		if(ans8==2)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q9. Choose the odd one out");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q9[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans9);
		if(ans9==3)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		
		printf("Q10. A Z B Y D W G T\nWhich letter comes next?");
		for(i=0;i<=3;i++)
		{
			printf("\n %s", q10[i]);
		}
		printf("\n\nEnter your option: ");
		scanf("%d", &ans10);
		if(ans10==3)
		{
			sum=sum+1;
			printf("Correct Answer!!!\n*****************");
		}
		else 
		{
			printf("Wrong Answer!!!\n***************");
		}
		
		printf("\n\nPress any key to continue.");
		
		getch();
		
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t===============================================================\n\n\t\t\t\tPress 1 if you want to see the correct answers else press 2:  ");
		scanf("%d", &opt);
		printf("\n\t\t\t\t===============================================================");
		getch();
		
		system("cls");
		if(opt==1)
		{
			correctAnswer(option1,option2,option3,option4,option5,option6,option7,option8,option9,option10);
			getch();
		}
		break;
		
		case 2:
		system("cls");
		system("COLOR F4");
		printf("\n\n\n\n\t  Name: %s\t\t   Age: %d\t\t Score: %d\n", d.name, d.age, sum);
		printf("\n\t*********************************************************************\n\n");
		
		printf("\n\n\n*********************************************************************************\n");
		printf("\t\t     ~~IQ Chart~~\n");
		printf("*********************************************************************************\n\n");
		printf("\t IQ score \t\t Correspondence\n\n");
		printf("\t 145-160 \t\t Very gifted or highly advanced\n");
		printf("\t 130-144 \t\t Gifted or very advanced\n");
		printf("\t 120-129 \t\t Superior\n");
		printf("\t 110-119 \t\t High average\n");
		printf("\t  90-109 \t\t Average\n");
		printf("\t   80-89 \t\t Low average\n");
		printf("\t   70-79 \t\t Borderline impaired or delayed\n");
		printf("\t   55-69 \t\t Mildly impaired or delayed\n");
		printf("\t   40-54 \t\t Moderately impaired or delayed\n");
		
		if(d.age >= 10 && d.age <= 15)
		{
			if(sum ==10)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 145-160.\n\t\t==========================");
				ptr= "      145-160";
			}
			else if(sum==8 || sum==9)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 130-144.\n\t\t==========================");
				ptr= "      130-144";
			
			}
			else if(sum==7 || sum==6 || sum==5)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 120-129.\n\t\t==========================");
				ptr= "      120-129";
				
			}
			else if(sum==4)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 110-119.\n\t\t==========================");
				ptr= "      110-119";
			
			}
			else if(sum==3 || sum == 2 || sum==1)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 90-109.\n\t\t==========================");
				ptr= "      90-109";
				
			}
			
		}
		
		
		if(d.age >= 16 && d.age <= 20)
		{
			if(sum ==10)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 145-160.\n\t\t==========================");
				ptr= "      145-160";
			}
			else if(sum==9)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 130-144.\n\t\t==========================");
				ptr= "      130-144";
			}
			else if(sum==7 || sum==8)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 120-129.\n\t\t==========================");
				ptr= "      120-129";
			}
			else if(sum==6 || sum==5)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 110-119.\n\t\t==========================");
				ptr= "      110-119";
			}
			else if(sum==4 || sum==3)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 90-109.\n\t\t==========================");
				ptr= "      90-109";
			}
			else if(sum==2 || sum==1)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 80-89.\n\t\t==========================");
				ptr= "      80-89";
			}
		}
		
		if(d.age >= 21 && d.age <= 30)
		{
			if(sum ==10)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 145-160.\n\t\t==========================");
				ptr= "      145-160";
			}
			else if(sum==9)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 130-144.\n\t\t==========================");
				ptr= "      130-144";
			}
			else if(sum==8)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 120-129.\n\t\t==========================");
				ptr= "      120-129";
			}
			else if(sum==7 || sum==6)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 110-119.\n\t\t==========================");
				ptr= "      110-119";
			}
			else if(sum==5)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 90-109.\n\t\t==========================");
				ptr= "      90-109";
			}
			else if(sum==4)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 80-89.\n\t\t==========================");
				ptr= "      80-89";
			}
			else if(sum==3)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 70-79.\n\t\t==========================");
				ptr= "      70-79";
			}
			else if(sum==2)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 55-60.\n\t\t==========================");
				ptr= "      55-60";
			}
			else if(sum==1)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 40-54.\n\t\t==========================");
				ptr= "      40-54";
			}
		}
		
		if(d.age >= 31 && d.age <= 50)
		{
			if(sum ==10)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 130-144.\n\t\t==========================");
				ptr= "      130-144";
			}
			else if(sum==9)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 120-129.\n\t\t==========================");
				ptr= "      120-129";
			}
			else if(sum==8)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 110-119.\n\t\t==========================");
				ptr= "      110-119";
			}
			else if(sum==7)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 90-109.\n\t\t==========================");
				ptr= "      90-109";
			}
			else if(sum==6)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 80-89.\n\t\t==========================");
				ptr= "      80-89";
			}
			else if(sum==5)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 70-79.\n\t\t==========================");
				ptr= "      70-79";
			}
			else if(sum==4)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 55-60.\n\t\t==========================");
				ptr= "      50-60";
			}
			else if(sum==3 || sum==2 || sum==1)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 40-54.\n\t\t==========================");
				ptr= "      40-54";
			}

		}
		
		if(d.age >= 51 && d.age <= 100)
		{
			if(sum ==10)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 130-144.\n\t\t==========================");
				ptr= "      130-144";
				
			}
			else if(sum==9 || sum==8)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 120-129.\n\t\t==========================");
				ptr= "      120-129";
			}
			else if(sum==7)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 110-119.\n\t\t==========================");
				ptr= "      110-119";
			}
			else if(sum==6)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 90-109.\n\t\t==========================");
				ptr= "      90-109";
			}
			else if(sum==5)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 80-89.\n\t\t==========================");
				ptr= "      80-89";
			}
			else if(sum==4)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 70-79.\n\t\t==========================");
				ptr= "      70-79";
			}
			else if(sum==3)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 55-60.\n\t\t==========================");
				ptr= "      55-60";
				
			}
			else if(sum==2 || sum==1)
			{
				printf("\n\n\t\t==========================\n\t\tYour IQ score is 40-54.\n\t\t==========================");
				ptr= "      40-54";
			}

		}
		getch();
		break;
		
		case 3:
			system("cls");
			system("COLOR F3");
			printf("\n");
			if ((fptr = fopen("scores.txt","a")) == NULL)
			{	
       			printf("Error! opening file");
       			exit(1);
   			}
   			fprintf(fptr,"\n\%s\t\t%d\t\t\t%d\t\t%s", d.name, d.age, sum, ptr);
			fclose(fptr);
			
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t**************************\n\t\t\t\t\t\t\t\t  YOUR RESULT IS SAVED!!\n\t\t\t\t\t\t\t\t**************************");
			getch();
			break;
			
		case 4:
			system("cls");
			system("COLOR FC");
			
			if((fptr=fopen("scores.txt","r"))==NULL)
			{
				printf("Error! opening file");
       			exit(1);
			}
			else {
				while(!feof(fptr)) {
				printf("\t\t\t\t%s",fgets(ch,100,fptr));
			}
			
			fclose(fptr);
			getch();
			break;	
		}
			
	}
  	

}
while(option !=5);
	
	return 0;				 
}
