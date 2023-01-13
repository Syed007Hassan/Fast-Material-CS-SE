#include <stdio.h>
void main()
{   int p, c, m, t, mp;

    printf("Eligibility Criteria for an engineering:\n");
    printf("Marks in Mathematics >= 65\n");
    printf("Marks in Physics >= 55\n");
    printf("Marks in Chemestry >= 50\n");
    printf("Total in all three subject >= 180\n");
    printf("or Total in Maths and Physics >= 140\n");
    printf("-------------------------------------\n");

    printf("Input the marks obtained in Physics :");
    scanf("%d", &p);
    printf("Input the marks obtained in Chemistry :");
    scanf("%d", &c);
    printf("Input the marks obtained in Mathematics :");
    scanf("%d", &m);
    printf("Total marks of Mathematics, Physics and Chemistry : %d\n", m + p + c);
    printf("Total marks of Maths and  Physics : %d\n", m + p);
    
    eligibility(m,p,c);

    
    }
    
 int eligibility( int x, int y, int z)
 {
 	if (x>=65 || y>=55 || z>50){
	 if((x+y+z)>= 180 || (x+y)>= 140){
	            
        printf("The  candidate is eligible for admission.\n");
		}    	
 }
      else
         
		 printf("The candidate is not eligible.\n");
 
    
    
    return 0;
}
   
