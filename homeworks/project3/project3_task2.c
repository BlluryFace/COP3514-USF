#include <stdio.h>

///// Divide a sorted array in half repeatedly until value is (or is not) found
///// \param arr: the sorted array
///// \param x: the value that needs to be found
///// \param high: index of the last element in the array
///// \return the index of the element that need to be found in the array.
///// \return -1 if not found
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
        }
    }
    return -1;
}

/// Sort the array using selection sort
/// \param arr: array of integers
/// \param n: numbers of
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int low = i;
        int high = i + 1;
        for (; high < n; high++) {
            if (arr[high] < arr[low]) {
                low = high;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[low];
        arr[low] = arr[i];
        arr[i] = temp;
    }
}

/// Modify the input list
/// \param numbers: sequence of number that is going to be analyzed
/// \param size: the lenght of the sequence
/// \param result: the modified sequence that contain only the distinct numbers
/// \return the number of distinct number
int find_distinct(int numbers[], int size, int result[]) {
    int temp[size];  // Temporary array to store distinct numbers
    int distinct_count = 0;

    for (int i = 0; i < size; i++) {
        // If the number is not already in the temp array, add it
        selection_sort(temp,distinct_count);
        if (binarySearch(temp, numbers[i], distinct_count) == -1) {
            temp[distinct_count++] = numbers[i];
        }
    }

    // Copy distinct numbers from temp to result array
    for (int i = 0; i < size; i++) {
        result[i] = temp[i];
    }
    return distinct_count; // Return the number of distinct elements
}



int main() {
    int size;
    printf("Enter the size of sequence: ");
    scanf("%d", &size);

    int sequence[size];

    printf("Enter numbers: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &sequence[i]);
    }
    selection_sort(sequence, size);
    // Find distinct numbers and store them in result array
    int distinct_count = find_distinct(sequence, size, sequence);

    // Sort the distinct numbers in ascending order
    selection_sort(sequence, distinct_count);

    // Display the sorted distinct numbers
    printf("Output: ");
    for (int i = 0; i < distinct_count; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    return 0;
}