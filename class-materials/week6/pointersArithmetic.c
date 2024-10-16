#include <stdio.h>
int main() {
    int a[]={6, 19, 35, 74, 23, 16};
    int *p = &a[1];
    int *q = &a[5];
    printf("%d\n", *(p+3));
    printf("%d\n", *(q-3));
    printf("%d\n", q-p);
    printf("%d\n", *q-*p);
    printf("%d\n",p < q);
    printf("%d\n",p > q);
    return 0;
}