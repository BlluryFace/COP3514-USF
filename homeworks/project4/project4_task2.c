// Name: Huy Bui
// Description: Count how many times the number in that position was seen before and after that position

#include <stdio.h>
/// Count how many times the number in that position was seen before and after that position.
/// \param arr: array of integers with the pointer pointing to the first element
/// \param n: number of element in the array
void before_after(int *arr, int n) {
    int *pointer = arr, *index = arr; //set the pointer and index at the first element of the array
    int before = 0, after = 0;
    for (; index < arr + n; index++) {
        // Count the number of element that was seen before the index
        for (; pointer < index; pointer++) {
            if (*pointer == *index) {
                before += 1;
            } else continue;
        }
        pointer = index + 1; // make the pointer go pass the index
        // Count the number of element that was seen after the index
        for (; pointer < arr + n; pointer++) {
            if (*pointer == *index) {
                after += 1;
            } else continue;
        }
        printf("%d %d\n", before, after);
        // Reset the pointer and the counter
        pointer = arr;
        before = after = 0;
    }
}
int main() {
    int n = 0;
    int *arrPointer;
    scanf("%d", &n); // number of elements in an array
    int arr[n];
    // Pointer is pointing to an index in an array
    // scanf function will assign a number the pointer
    // Therefore, updating the value at that index
    for (arrPointer = arr; arrPointer < arr + n; arrPointer++)
        scanf("%d", arrPointer);
    before_after(arr, n);
    return 0;
}