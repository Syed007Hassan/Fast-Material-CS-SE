#include<stdio.h>
#include<math.h>
int main(){
	float ang,area[6];  
	int i,j; float x[6]; 
	float a[6][3]={      {137.4,80.9,0.78},
	                     {155.2,92.62,0.89},
	                     {149.3,97.93,1.35},
						 {160.0,100.25,9.00},
						 {155.6,68.95,1.25},
						 {149.7,120.0,1.75}, };			 
																
    for(i=0;i<6;i++){
	for(j=0;j<1;j++){
		x[i]=(a[i][j] * a[i][j+1] )/2  ;
	}
	}
	printf("\tThe Areas are:\n");
	for(i=0;i<6;i++){
		for(j=2;j<3;j++){
			
	  ang = sin(a[i][j]);
      area[i] = x[i] * ang;
      printf("\t%.2f\n\n",area[i]);
	}
}

float max;
for(i=0;i<6;i++){
	
	if(area[i] > area[i+1]){
		max=area[i];
	}
}

printf("\tThe maximum area is %.2f units square.",max);


return 0;

}


