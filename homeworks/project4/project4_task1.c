#include <stdio.h>
void roundResult(int *board, int n) {
    int *pointer1, *pointer2;
    int Marijorie = 0;
    int Jonh = 0;
    char player = 'Marijorie';
    *pointer1 = *board;
    *pointer2 = *board + n-1;
    for (; *pointer1 != pointer2;) {
        if (player == 'Marijorie') {
            {
                int headVal = *pointer1;
                int tailVal = *pointer2;
                if (headVal < tailVal) {
                    Marijorie += tailVal;
                    pointer2--;
                } else {
                    Marijorie += headVal;
                    pointer1++;
                }
            }
            player = 'Jonh';
        } else {
                int headVal = *pointer1;
                int tailVal = *pointer2;
                if (headVal < tailVal) {
                    Jonh += tailVal;
                    pointer2--;
                } else {
                    Jonh += headVal;
                    pointer1++;
                }
            player = 'Marijorie';
        }
    }
    if (Marijorie > Jonh) {
        printf("Marijorie");
    } else {
        printf("Jonh");
    }
}
int main() {
    int T = 0;
    int N = 0;
    int *arrayPointer;
    scanf("%d", &T);
    scanf("%d", &N);
    int board[N];
    int temp = 0;
    //TODO: Implement this array with the function
    for (arrayPointer = board; arrayPointer < board + N; arrayPointer++)
        scanf("%d", arrayPointer);
    return 0;
}