#include <stdio.h>
int main() {
    int arr[4] = {5, 8, 2, 9};
    for (int i = 0; i < 4; i++) {
        printf("%p\n", &arr[i]);
    }
}