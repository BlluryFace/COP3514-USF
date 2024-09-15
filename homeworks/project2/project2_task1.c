// name: Huy Bui
// Description: the program show the number of oscillating grades

#include <stdio.h>
#include <string.h>
int main() {
    int grades[100];
    int numGrades;
    int count = 0;
    int abnormal = 0;
    // Store user's input in numGrades
    printf("Enter the number of grades: ");
    scanf("%d", &numGrades);
    // Add new grades from input into each index of an array.
    // Loop until the last character is a new line character
    // or the count reached numGrades
    printf("Enter the grades: ");
    do {
        scanf("%d", &grades[count++]);
    } while (getchar() != "\n" && count < numGrades);
    // Counting abnormal grades by counting the number of new low and high grades
    // in the array from left to right
    for (int i = 1, hiGrade = grades[0], loGrade = grades[0]; i < count; i++) {
        if (grades[i] > hiGrade) {
            hiGrade = grades[i];
            abnormal++;
        } else if (grades[i] < loGrade) {
            loGrade = grades[i];
            abnormal++;
        } else continue;
    }
    // Print the number of oscillating grades
    printf("%d", abnormal);
    return 0;
}