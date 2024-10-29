#include <stdio.h>
// Maximum lenght of the string
#define MAX_LEN 1000

int main() {
    char str[MAX_LEN+1];
    // open the file
    FILE * fp = fopen("text.txt", "r");
    // "r": open for reading (file need to exist)
    // "w": open file for writing (file need not exist)
    // "a" open file for appending (file need not exist)
    if (fp == NULL){
        printf("error opening file.\n");
        return 1;
    }
    // read the file
    while((fgets(str, MAX_LEN, fp)) != NULL)
        printf("%s", str);
    fclose(fp);
}
