#include <stdio.h>
void findTwoLargest(int arr[], int n, int *largest, int *secondLargest){
    *largest = arr[0];
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] > arr[i]){
            int temp = *largest;
            *secondLargest = temp;
            *largest = arr[i+1];
        }
    }
}

int main() {
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    int a = 0;
    int b = 0;
    findTwoLargest(nums, 10 ,&a, &b);
    printf("%d %d\n", a, b);
}