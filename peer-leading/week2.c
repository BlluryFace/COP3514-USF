#include <stdio.h>

int main() {
    int i = 3;
    i++; // These two grab the value
    i--; // first and then increase/decrease

    ++i; // These two increase the value
    --i; // fist and then grab the value

    printf("%d\n", i);
    printf("%d\n", i++);
    printf("%d\n", i); // After i++ from last line i = 4

    // if-else function
    if (i<10) {
        printf("Hello\n");
    }
    else if (i > 10) {
        printf("bob\n");
    }
    else {
        printf("Goodbye\n");
    }

    switch(i) {
        case 1: printf("Hello 1\n");
            break;
        case 2: printf("bob 2\n");
            break;
        case 3700: printf("wow\n");
            break; // Must have a break statement so that
                   // case 1 or 2 won't fall through
        default: printf("Oops found nothing? \n");
            break;
    }
    // the for loop
    for (int i = 0; i < 5; i++) {
        printf("hi");
    }
    return 0;
}
