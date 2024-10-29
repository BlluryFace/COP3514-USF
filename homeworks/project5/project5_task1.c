// Name: Huy Bui
// Description: Split the a two-word sentence into two words

#include <stdio.h>
/// Reading user's input through the terminal
/// \param str: the character array where the user want to store the input
void readLines(char *str) {
    int ch;
    while((ch = getchar()) == ' ' || ch == '\t') {
        // Skipping all white spaces in front of the input
    }
    // Store the first non-whitespace character
    *str = ch;
    str++;
    // Store the rest of the input into the array until reaching the new line character
    while ((ch = getchar()) != '\n'&& ch != EOF){
        *str = ch;
        str++;
    }
    *str = '\0'; // Adding the end of string character
}
///
/// \param input: the sentence that needs to be split
/// \param word1: the character array where user want to store the first word
/// \param word2: the character array where user want to store the second word
void split (char *input,  char *word1, char *word2){
    for (; *input != ' ' && *input != '\t' && *input != '\0'; input++){
        *word1 = *input;
        word1++;
    }
    *word1 = '\0'; // Adding the end of string character

    for (; *input == ' ' || *input == '\t'; input++){
        // Skipping all white spaces in between the words
    }

    for (; *input != ' ' && *input != '\t' && *input != '\0'; input++){
        *word2 = *input;
        word2++;
    }
    *word2 = '\0'; // Adding the end of string character
}

int main(){
    char input[1000];
    char word1[500], word2[500];

    printf("Enter input: ");
    readLines(input);

    split(input, word1, word2);

    printf("Word #1: %s\n", word1);
    printf("Word #2: %s\n", word2);
    return 0;
};