#include<stdio.h>
#include<stdlib.h>
int main() {
//    int n = 0;
//    int *a = malloc( sizeof(int) * n);
//    if (a == NULL){
//        printf("Fail to allocate memory");
//        return 1;
//    }
//    a[0] = 1;
//    a[1] = 2;
//    a[2] = 3;
//    printf("%d", a[2]);
//    return 0;
    char *words[100];
    for (int i = 0; i < 10; i++){
        words[i] = malloc(21 * sizeof(char));
    }
}