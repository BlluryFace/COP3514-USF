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
//    char ch = 'c';
#define N 10
//    int a[N] = {1,2,3,4,5,6,7,8,9};
//    int *p;
//    //for (p = a + N - 1; p >= a; p--)
//    //    printf("%d ", *p);
//    char s1[100] = "Program", s2[100] =  "Design";
//    int hr, min, sec;
//    split_time_traditional(2465, &hr, &min, &sec);
//    printf ("%d:%d:%d\n", hr, min, sec);
//    split_time_modulo(2465, &hr, &min, &sec);
//    printf ("%d:%d:%d\n", hr, min, sec);
//    char *str = "The world is yours";
//    replace(str, 'o', 'w');
//    printf("%s", str);
//    int n = 8;
//    int input[8] = {0,0,1,0,1,1,0,1};
//    int output[8] = {0};
//    char file[100] = "byebye.e";
//    char extension[3] = "";
//    get_extension(file, extension);
//    printf("%s", extension);
//    if (is_all_uppercase("HEWWO") == 1) printf("Yes\n");
//    if (is_all_uppercase("HEwWO") == 0) printf("No\n");
//    char str[1000] = "Go ahead, make my day.";
//    shift(str, 3);
//    printf("%s", str);
    char str1[1000] = "https://mylifesuck.com/resources/howtokillyourself.docx";
    url(str1);
    printf("%s", str1);
//    edgeThem(input, output, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d",output[i]);
//    }
//    printf("\n");
//    edgeMe(input, output, n);
//    for (int i = 0; i < n; i++) {
//        printf("%d",output[i]);
//    }
//    char null = ''
//    if (strcmp (s1, s2) > 0) {
//        strcat (s1, s2);
//    } else {
//        strcat (s2, s1);
//    }
//    printf("%s\n", s2);
//    printf("%d\n", strcmp("he", "hi"));
//    printf("%d\n", strcmp("hello", "Hi"));
//    printf("%d\n", strcmp("he", "hello"));
//    printf("%d\n", strcmp("8h", "hello"));
}