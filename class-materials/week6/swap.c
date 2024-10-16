#include <stdio.h>
void swapWrong (int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapRight (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 3;
    int y = 4;
    swapWrong(x,y);
    printf("%d %d\n", x,y);
    swapRight(&x,&y);
    printf("%d %d\n",x,y);
    return 0;
}