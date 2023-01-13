# include<stdio.h>
int main()

{
	float weight,height,bmi;
	
	printf("Enter height of the person in meters  ");
	scanf("%f", &height);
	
	printf("Enter weight of the person in kilogram  ");
	scanf("%f", &weight);

	bmi=(weight*703)/(height*height);
	printf("The BMI is: %f\n", bmi);
	
	if(bmi < 15)
	{
      printf("BMI SHOWS STARVATION");
	}
    else if(bmi < 18.5)
	 { 
	  printf("BMI SHOWS UNDERWEIGHT");
	 }
	 else if(bmi >= 18.5 && bmi < 25)
	 {
	  printf("BMI SHOWS IDEAL");	
	 }
	 else if(bmi >= 25 && bmi < 30)
	 {
	  printf("BMI SHOWS OVERWEIGHT");	
	 }
	 else if(bmi > 40)
	 {
	  printf("BMI SHOWS MORBIDLY OBESE");	
	 }


   return 0;
   
}
