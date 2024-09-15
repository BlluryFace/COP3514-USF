#include <stdio.h>


int main() {
    int i = 32;
    for (i; i <= 126; i++){
        char ch; // Turn integer into character according to the ASCII table
        printf("%d: %c\n",i , ch = i);
    };
    return 0;
}