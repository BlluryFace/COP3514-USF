#include <stdio.h> // a header containing information about C's standard I/O library
# define RATE 21.5 // define a variable so that the other person reading will be able to understand
int main() {
    double hours;
    printf("Enter hours:");
    scanf("%lf", &hours); // l stand for long. l is needed because by default placeholder is for int
                          // & symbol is the address operator
                          // Usually required when using scanf
    printf("pay is $%.2f", hours * RATE);
    // printf displays a string literal.
    // Include /n to make a new line
    // %f indicate where double or float variable should be in a string
    // %d indicate where int variable should be in a string
    // The number of variable placeholder (%d or %f) must be equal to number
    // of variable stated after the printf function
    // To limit the number of decimal place after a digit using %.(the number of digits)f
    return 0;
};
// You can compile the program using gcc payByHour.c
// Run the program using ./a
// If you want to change the program file name do gcc -o payment payByHour.c
// The -o option let you choose the name of the file