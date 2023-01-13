#include <stdio.h>
int power(int base, int a);
int main() {
    int base, a, x;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number(positive integer): ");
    scanf("%d", &a);
    x=power(base, a);
    printf("the value of %d to the power %d is: %d", base, a, x);
    return 0;
}

int power(int base, int a) {
    if (a != 0)
        return (base*power(base, a - 1));
    else
        return 1;
}
