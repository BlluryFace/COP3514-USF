// Name: Huy Bui
// Description: turns sentences into token that can be processed by machine learning algorithm

#include <stdio.h>
#include <string.h>
#define  MAX_LINES 220
#define MAX_WORDS 1800
#define MAX_LETTERS 20
/// Seperated an one-line text into different lines by period
/// \param oneLine the text
/// \param sentences the seperated text
/// \param line amount of line in the text
void extractLines(char *oneLine, char sentences[MAX_LINES][MAX_WORDS], int *line) {
    char *sentence = strtok(oneLine, ".");
    while (sentence != NULL) {
        while (*sentence == ' ') sentence++;
        char *end = sentence + strlen(sentence) - 1;
        while (end > sentence && (*end == ' ' || *end == '\n')) end--;
        *(end + 1) = '\0';

        if (strlen(sentence) > 0) {
            strcpy(sentences[*line], sentence);
            (*line)++;
        }

        sentence = strtok(NULL, ".");
    }
}
/// Extract the words from the sentences, retain their position in the sentences
/// \param sentences the sentences that will be used to turn into words
/// \param words extracted words, keeping their location the same
/// \param wordsPerLine number of words for each line
/// \param line number of sentence line
void extractWords(char sentences[][MAX_WORDS], char words[][MAX_WORDS][MAX_LETTERS], int wordsPerLine[], int line) {
    for (int l = 0; l < line; l++) {
        char *word = strtok(sentences[l], " ");
        int wordIndex = 0;
        while (word != NULL) {
            strcpy(words[l][wordIndex++], word);
            word = strtok(NULL, " ");
        }
        wordsPerLine[l] = wordIndex; // Store the count of words for the current sentence
    }
}
/// Check if a word in the sentence is unique or not by checking it against every element in the uniqueWords array
/// \param uniqueWords the array of unique words collected from the the sentence
/// \param count number of word in the sentence
/// \param word number of unique words
/// \return 0 if not unique; 1 if unique
int isUnique(char uniqueWords[][MAX_LETTERS], int count, char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(uniqueWords[i], word) == 0) {
            return 0;
        }
    }
    return 1;
}
/// Extracting unique words from the 3D array of words
/// \param words the 3D array of words
/// \param line the number of lines in the word array
/// \param numWords number of word each line represented in an array
/// \param uniqueWords where the unique words will be stored
/// \param uniqueCount the number of unique words
void extractUniqueWords(char words[][MAX_WORDS][MAX_LETTERS], int line, int numWords[], char uniqueWords[][MAX_LETTERS], int *uniqueCount) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < numWords[i]; j++) {
            char tempWord[MAX_LETTERS];
            strcpy(tempWord, words[i][j]);

            if (isUnique(uniqueWords, *uniqueCount, tempWord)) {
                strcpy(uniqueWords[*uniqueCount], tempWord);
                (*uniqueCount)++;
            }
        }
    }
}
/// Sort the unique words by alphabetical manners
/// \param uniqueWords array of words that are unique in the sentence
/// \param uniqueCount number of unique words
void sortWords(char uniqueWords[][MAX_LETTERS], int uniqueCount) {
    for (int i = 0; i < uniqueCount - 1; i++) {
        for (int j = i + 1; j < uniqueCount; j++) {
            if (strcmp(uniqueWords[i], uniqueWords[j]) > 0) {
                char temp[45];
                strcpy(temp, uniqueWords[i]);
                strcpy(uniqueWords[i], uniqueWords[j]);
                strcpy(uniqueWords[j], temp);
            }
        }
    }
}
/// Structure of the word/number
typedef struct {
    char word[MAX_LETTERS];
    int index;
} WordIndex;

/// Assigning number to unique words
/// \param uniqueWordsIndexed the struct that store the words and its index
/// \param uniqueWords the array of sorted uniqueWords
/// \param uniqueCount the number of unique words
void assignIndices(WordIndex uniqueWordsIndexed[], char uniqueWords[][MAX_LETTERS], int uniqueCount) {
    for (int i = 0; i < uniqueCount; i++) {
        strcpy(uniqueWordsIndexed[i].word,uniqueWords[i]);
        uniqueWordsIndexed[i].index = i + 1;  // Assigning an integer value (index) for each word
    }
}

/// Store the variables into the output file
/// \param file
/// \param words
/// \param lineCount
/// \param numWords
/// \param uniqueWordsIndexed
/// \param uniqueCount
void storeWordIndexes(FILE *file,char words[][MAX_WORDS][MAX_LETTERS], int lineCount, int numWords[], WordIndex uniqueWordsIndexed[], int uniqueCount) {
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < numWords[i]; j++) {
            char *word = words[i][j];

            for (int k = 0; k < uniqueCount; k++) {
                if (strcmp(word, uniqueWordsIndexed[k].word) == 0) {
                    fprintf(file,"%d ", uniqueWordsIndexed[k].index);
                    break;
                }
            }
        }
        fprintf(file, "\n");
    }
}

int main(int argc, char *argv[]){
    FILE *inFile;
    inFile = fopen(argv[1], "r");
    if (inFile == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[1000];
    char oneLine[10000] = "";
// Read each line and append it to sentences
    while (fgets(buffer, sizeof(buffer), inFile) != NULL) {
        // Remove newline character if present
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';  // Replace newline with null terminator
        }        strcat(oneLine, buffer);  // Append the current line to sentences
        strcat(oneLine, " ");
    }
    fclose(inFile);

    char sentences[MAX_LINES][MAX_WORDS];
    int line = 0;
    extractLines(oneLine, sentences, &line);

    char words[MAX_LINES][MAX_WORDS][MAX_LETTERS];
    int numWords[MAX_LINES] = {0};
    extractWords(sentences, words, numWords, line);

    char uniqueWords[730][MAX_LETTERS];
    int uniqueCount = 0;
    extractUniqueWords(words, line, numWords, uniqueWords, &uniqueCount);
    sortWords(uniqueWords, uniqueCount);

    WordIndex uniqueWordsIndexed[uniqueCount];
    assignIndices(uniqueWordsIndexed, uniqueWords , uniqueCount);

    FILE *outFile;
    outFile = fopen(argv[2], "w");
    fprintf( outFile, "%d\n", uniqueCount);
    for (int i = 0; i < uniqueCount; i++){
        fprintf( outFile, "%s\n", uniqueWords[i]);
    }
    storeWordIndexes(outFile, words, line, numWords, uniqueWordsIndexed, uniqueCount);

    return 0;
}