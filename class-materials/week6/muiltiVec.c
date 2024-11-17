#include <stdio.h>

void multiVec(int v1[], int v2[], int v3[], int n){
    for (int *ptr1 = &v1[0], *ptr2 = &v2[0], i = 0;
         *ptr1 < &v1[n], *ptr2 < &v2[n], i < n;
    *ptr1++, *ptr2++, i++){
        v3[i] = *ptr1 * *ptr2;
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