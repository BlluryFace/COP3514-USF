// Name: Huy Bui
// Description: Board game for Marjorie and Jonh

#include <stdio.h>
/// Calculate the score of each person to see who win the round.
/// A turn of the game consists of either picking the first or the last number in the array
/// The winner is the player with the highest sum for the picked numbers
/// Both players are using the same strategy, picking the largest number available remaining in the array
/// \param board: array of numbers with the pointer pointing to the first variable
/// \param n: number of elements in the board
void roundResult(int *board, int n) {
    int *pointer1, *pointer2;
    int Marijorie = 0;
    int Jonh = 0;
    char player = 'M';
    pointer1 = board;
    pointer2 = board + n-1;
    // Comparing the value of the variable at the head and the tail to see which is higher
    // Player in the turn increment their score by the value
    // The turn then switched to the other person
    for (; pointer1 <= pointer2;) {
        if (player == 'M') {
            int headVal = *pointer1;
            int tailVal = *pointer2;
            if (headVal < tailVal) {
                Marijorie += tailVal;
                pointer2--;
            } else {
                Marijorie += headVal;
                pointer1++;
            }
            player = 'J';
        } else if (player == 'J') {
            int headVal = *pointer1;
            int tailVal = *pointer2;
            if (headVal < tailVal) {
                Jonh += tailVal;
                pointer2--;
            } else {
                Jonh += headVal;
                pointer1++;
            }
            player = 'M';
        }
    }
    if (Marijorie > Jonh) {
        printf("Marijorie\n");
    } else if(Marijorie < Jonh) {
        printf("Jonh\n");
    } else {
        printf("Draw\n");
    }
}
int main() {
    int T = 0;
    int N = 0;
    int *arrayPointer;
    scanf("%d", &T); // number of rounds in an array
    for (; T > 0; T--) {
        scanf("%d", &N); //number of elements in an array
        int board[N];
        // Pointer is pointing to an index in an array
        // scanf function will assign a number the pointer
        // Therefore, updating the value at that index
        for (arrayPointer = board; arrayPointer < board + N; arrayPointer++)
            scanf("%d", arrayPointer);
        roundResult(board, N);
    }
    return 0;
}