// Name: Huy Bui
// Description: calculate score through input from command line

#include <stdio.h>
/// Totaling the ASCII value of each character in the array
/// \param word: array of characters that user want to calculate the score from
/// \return the score of the array
int calculateScore(char *word) {
    int score = 0;
    for (; *word != '\0'; word++){
        score += *word;
    }
    return score;
}

int main(int argc, char *argv[]) {
    // Check if argument is valid
    if (argc != 3) {
        printf("invalid number of arguments");
        return 0;
    }
    // Calculate the score of the first and second argument
    int score1 = calculateScore(argv[1]);
    int score2 = calculateScore(argv[2]);

    // Print out who wins, who lose
    if (score1 > score2) {
        printf("Marjorie wins!\n");
    } else if (score1 < score2) {
        printf("John wins!\n");
    } else if (score1 == score2) {
        printf("Play again!\n");
    }
    return 0;
}