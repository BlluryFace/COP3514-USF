#include <stdio.h>
/// Divide a sorted array in half repeatedly until value is (or is not) found
/// \param arr: the sorted array
/// \param x: the value that needs to be found
/// \param high: index of the last element in the array
/// \return the index of the element that need to be found in the array.
/// \return -1 if not found
int binarySearch(int arr[], int x, int high) {
    int low = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (x == arr[mid]) {
            return mid;
        } else if (x < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        };
    }
    return -1;
};

int main() {
    int square[30] = {4, 9, 16, 25, 36, 49,
                      64, 81, 100, 121, 144,
                      169, 196, 225, 256, 289,
                      324, 361, 400, 441, 484,
                      529, 576, 625, 676, 729,
                      784, 841, 900, 961};
    int squareRoot[30] = {2,3,4,5,6,7,
                          8,9,10,11,12,
                          13,14,15,16,17,
                          18,19,20,21,22,
                          23,24,25,26,27,
                          28,29,30,31};
    int size;
    printf("Enter the size of the sequence: ");
    scanf("%d", &size);

    int sequence[size];
    int index = 0;

    printf("Enter numbers: ");
    // Get numbers from the input into the array
    do {
        scanf("%d", &sequence[index++]);
    } while (getchar() != '\n' || index < size);
    // Replace square number in the array with its square root.
    // If found a number that is higher than the size of the array -> Output: no
    // If no number in the array is higher than the size of the array -> Output: yes
    for (int i = 0; i < size; i++) {
        int existSquareNumIndex = binarySearch(square, sequence[i], 29); // Find the index of the square number in the array
        if (existSquareNumIndex != -1) {
            sequence[i] = squareRoot[existSquareNumIndex]; // Replace the square number
        };
        printf("%d\n", sequence[i]);
        if (sequence[i] >= size) {
            printf("Output: no\n");
            return -1;
        } else continue;
    }
    printf("Output: yes\n");
    return 0;
}