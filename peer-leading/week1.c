// library goes on top
#include <stdio.h> // the standard input-output library
#define NUMBER 5 // A variable that doesn't change and can be referenced throughout the program
                 /* We use #define instead of const because it modify the source code
                 of an identifier instead of creating a new variable, saving memory in the process */
int main() { // int main() identify that the function return an integer
    int bob;
    printf("Enter a number:\n");
    scanf("%d", &bob);
    // %c: character
    // %f: float numbers
    printf("The number was: %d", bob);
    printf("The macro number was: %d", NUMBER);
    return 0; // must return 0 so the program can terminate
}

// To compile the program: gcc -Wall fileName.c
// The -Wall show you all the error
// To execute the program: ./a.out