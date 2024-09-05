#include <stdio.h>
# define RATE 21.5 // define a variable so that the other person reading will be abe to understand
int main() {
    double hours;
    printf("Enter hours:");
    scanf("%lf", &hours); // l stand for long
    printf("pay is $%.2f", hours * RATE);
    return 0;
};