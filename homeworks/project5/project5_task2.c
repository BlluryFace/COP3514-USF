// Name: Huy Bui
// Description: calculate score through input from command line

#include <stdio.h>
int calculateScore(char *word) {
    int score = 0;
    // Calculate score using pointer arithmetic
    for (; *word != '\0'; word++){
        score += *word;
    }
    return score;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments\n");
        return 0;
    }
    int score1 = calculateScore(argv[1]);
    int score2 = calculateScore(argv[2]);
    if (score1 > score2) {
        printf("Play again!\n");
    } else if (score1 < score2) {
        printf("John wins!\n");
    } else {
        printf("Play again!\n");
    }
    return 0;
}