#include <stdio.h>
int main() {  
    char a,b;
    int c;
    
    printf("Enter two characters and a number:  ");
    scanf("%c %c %d",&a,&b,&c);  
    
    printf("ASCII value of first character %c = %d\n", a, a);
    printf("ASCII value of second character %c = %d\n", b, b);
    printf("ASCII value of number %d = %d", c, c);
    
    
    return 0;
}
