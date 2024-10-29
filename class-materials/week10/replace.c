#include <stdio.h>
#define MAX_LEN 1000
void replace(char *message, char *new) {
    for (; message < message[MAX_LEN-1]; message++){
        char *nextLetter = message + 1;
        printf("%c", message);
        if (*message == '\\') {
            if (*nextLetter == 'n') {

            }
        }
        *new = *message;
        new++;
    }
}
int main() {
    FILE *readFile;
    FILE *newFile;
    char content[MAX_LEN+1];
    char new_content[MAX_LEN];

    readFile = fopen("text.txt", "r");
    if (readFile == NULL) {
        printf("Error opening file.");
        return 1;
    }
    while ((fgets(content, MAX_LEN, readFile)) != NULL) {
        printf("%s", content);
        replace(content, new_content);
        fputs(new_content, newFile);
    }
    fclose(readFile);
    fclose(newFile);
    return 0;
}