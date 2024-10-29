#include <stdio.h>

void readLines(char *str) {
    int ch;
    while((ch = getchar()) == ' ' || ch == '\t') {
    }
    if (ch != EOF){
        *str = ch;
        str++;
    }

    while ((ch = getchar()) != '\n' && ch != EOF){
        *str = ch;
        str++;
    }
    *str = '\0';
}

void split (char *input,  char *word1, char *word2){
    for (; *input == ' ' || *input == '\t'; input++){
    }
    for (; *input != ' ' && *input != '\t' && *input != '\0'; input++){
        *word1 = *input;
        word1++;
    }
    *word1 = '\0';
    for (; *input == ' ' || *input == '\t'; input++){
    }

    for (; *input != ' ' && *input != '\t' && *input != '\0'; input++){
        *word2 = *input;
        word2++;
    }
    *word2 = '\0';
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