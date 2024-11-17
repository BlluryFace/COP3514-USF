#include <stdio.h>
int search(int *index, int n, int val) {
    for (; index < index + n; index++){
        if (*index == val) {
            printf("%d\n", *index);
            return 1;
        } else continue;
    }
    return 0;
}
int duplicates(int *a, int n){
    if (n == 1) {
        return 0;
    }
    int temp[n];
    int *tempPtr = temp;
    temp[0] = *a;
    for (int i = 0; i < n; i++) {
        printf("%d", temp[i]);
    }
    a++;
    for (; a < a + n; a++){
        if (search(temp, n, *a) == 1){
            printf("%d\n", *a);
            return 1;
        } else {
            tempPtr++;
            *tempPtr = *a;
            continue;
        }
    }
    return 0;

}

int duplicateNew(int *arr, int n) {
    int duplicate[n];
    int *q = duplicate;
    int *p = arr;
    for (; p < arr + n; p++) {
        if (*q != *p) {
            *q = *p;
            q++;
        }
    }
    p = arr;
    q = duplicate;
    for (; q < duplicate + n; p++){
        int count = 0;
        for (;p < arr + n; q++){
            if (*p = *q){
                count++;
            }
        }
        if (count > 1){
            return count;
        }
    }
    return 0;
}
int main()
{
    int i;
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d array elements: ", n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    int result = duplicateNew(a, n);
//    if(result)
//        printf("there are duplicates in the array\n");
//    else
//        printf("no duplicates\n");
    printf("%d", result);
    return 0;
}
