#include <stdio.h>

void multiVec(int v1[], int v2[], int v3[], int n){
    for (int *p = &v1[0], *q = &v2[0], i = 0;
    *p < &v1[n], *q < &v2[n], i < n;
    *p++, *q++, i++){
        int v1Val = *p;
        int v2Val = *q;
        v3[i] = v1Val * v2Val;
    }
}

int main(void)
{
    int i, size;
    printf("Please enter the length of the vectors:\n");
    scanf("%d", &size);
    int a[size], b[size], c[size];
    printf("Enter the first vector: ");
    for(i=0;i<size;i++)
        scanf("%d", &a[i]);
    printf("Enter the second vector: ");
    for(i=0;i<size;i++)
        scanf("%d", &b[i]);
    multiVec(a, b, c, size);
    for(i=0;i<size;i++)
        printf("%d\t", c[i]);
    return 0;
}