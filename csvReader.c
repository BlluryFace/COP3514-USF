#include <stdio.h>
#include <string.h>
int f(char *s, char *t)
{

    char *p1, *p2;

    for(p1 = s, p2 = t; *p1 != '\0' && *p2 != '\0'; p1++, p2++){

        if (*p1 == *p2) break;

    }
    return p1 -s;

}

void split_time_traditional(int total, int *hr, int *min, int *sec){
    *hr = total / 3600;
    *min = (total - *hr * 3600) / 60;
    *sec = (total - *hr *3600 - *min * 60);
}

void split_time_modulo(int total, int *hr, int *min, int *sec){
    *hr = total / 3600;
    *min = total % 3600 / 60;
    *sec = total % 3600 % 60;
}
void replace(char *str, char x, char y) {
    for (; *str != 0; str++){
        if (*str == x) {
            *str = y;
        } else continue;
    }
}

void edgeThem( int *a1, int *a2, int n) {
    int *p, *q=a2;
    *q++=0;
    for (p = a1+1;p<a1+n; p++,q++)
        if(*p==*(p-1))
            *q=0;
        else
            *q=1;
}

void edgeMe( int *a1, int *a2, int n){
    *a2 = 0;
    a2++; a1++;
    for (;a1 < a1 + n; a1++,a2++){
        if (*(a1-1)!=*a1){
            *a2 = 1;
        } else *a2 = 0;
    }
}

void get_extension(char *file, char *extension) {
    for (;*file != '\0'; file++) {
        if (*file == '.') {
            break;
        } else continue;
    }
    if (*(file + 1) == '\0') {
        *extension = 'N';
    }
    file++;
    for (; *file != 0; file++, extension++){
        *extension = *file;
    }
}
int is_all_uppercase(char str[]){
    int flag = 1;
    for (char *p = str; *p != '\0'; p++){
        if (*p > 'a' && *p < 'z'){
            flag = 0; break;
        } else continue;
    }
    return flag;
}
void shift(char *message, int shift ){
    for (; *message != '\0'; message++){
        if (*message >= 'a' && *message <= 'z') {
            *message = (*message - 'a' + shift) % 26 + 'a';
        }
        if (*message >= 'A' && *message <= 'Z') {
            *message = (*message - 'A' + shift) % 26 + 'A';
        }
    }
}
void url(char *url) {
    for (;*url != '\0'; url++){};
    for (;*url != '/'; url--){};
    *url = '\0';
}


int main() {
//    FILE *pFile = fopen("test.txt", "r");
//    char course_id[100];
//    int student;
//    char status[100];
//    while(!feof(pFile) && !ferror(pFile)){
//        fscanf(pFile, "%s%d%s", course_id, &student, status);
//        printf("%s\t%d\t%s\n", course_id,student,status);
//    }
//    fclose(pFile);

    printf("Items per line: ");
    int num;
    scanf("%d", &num);
    FILE *inFile = fopen("test.txt", "r");
    FILE *outFile = fopen("result.txt", "w");
    char buffer[100];
    while(!feof(inFile) && !ferror(inFile)) {
        for (int i = 0; i < num - 1; i++) {
            if (fscanf(inFile, "%[^,],", buffer) == 1) {
                fprintf(outFile,"%s\t", buffer);
            }
        }
        if (fscanf(inFile, "%[^\n]\n", buffer) == 1) {
            fprintf(outFile,"%s\n", buffer);
        }
    }
    fclose(inFile);
    fclose(outFile);
    return 0;
}