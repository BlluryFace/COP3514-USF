// Name: Huy Dinh Bui
// Description: Scrabble game
#include <stdio.h>
#include <stdbool.h>
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
char popConsonant[5] = {'t', 'n', 's', 'r', 'h'};

/// Run through all values of an array to find the matched word.
/// Array size must be 5
/// \param ch: the word that needs to be found
/// \param array: the array
/// \return true or false
bool inArray(const char ch, const char array[]) {
    int i = 0;
    for (; i <= 4; i++) {
        if (ch == array[i]) return true;
        else continue;
    }
    return false;
}
/// Find the score assigned to a letter
/// \param ch: the letter that needs to be evaluated
/// \return the score of that letter
int letterScore(char ch) {
    int score;
    if (inArray(ch, vowels) == true ) score = 1;
    else if (inArray(ch, popConsonant) == true) score = 2;
    else if (ch != ' ') score = 3;
    else score = 0;
    return score;
}

int main() {
    int mariScore = 0, jonhScore = 0;
    char ch;

    printf("Enter the first sequence: ");
    // Get the sentence from user's input and calculate their sentence score
    while ((ch = getchar()) != '\n') {
        mariScore += letterScore(ch);
    }

    printf("Enter the second sequence: ");
    // Get the sentence from user's input and calculate their sentence score
    while ((ch = getchar()) != '\n') {
        jonhScore += letterScore(ch);
    }
    // Pick who is the winner depends on sentence score
    if (mariScore > jonhScore) printf("Marjorie wins!\n");
    else if (mariScore < jonhScore) printf("John wins!\n");
    else printf("Play again!\n");
    return 0;
}
