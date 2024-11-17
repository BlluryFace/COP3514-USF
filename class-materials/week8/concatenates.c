#include <stdio.h>
#include <string.h>
void concatenates(char *str1, char *str2, char result[]) {
    char temp[1000];
    char *tempPtr = temp;
    int len1 = 0, len2 = 0;
    for (; *str1 != '\0'; str1++, len1++, tempPtr++) {
        *tempPtr = *str1;
        //printf("%s", tempPtr);

    }
    for (; *str2 != '\0'; str2++, len2++, tempPtr++) {
        *tempPtr = *str2;
        //printf("%s", tempPtr);

    }
    tempPtr++; *tempPtr = '\0';
    strcpy(result, temp);

    //tempPtr = &temp[0];
//    char resultTemp[len1+len2+1];
//    result = resultTemp;
//    for (; *tempPtr != '\0'; tempPtr++, result++ ) {
//        *result = *tempPtr;
//    }
//    result++; *result++ = '\0';
}

int main() {
    char *str1 = "greed";
    char *str2 = " is good";
    char result[] = "";
    concatenates(str1, str2, result);
    printf("%s", result);
    return 0;
}