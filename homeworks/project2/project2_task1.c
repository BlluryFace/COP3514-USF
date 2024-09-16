// Name: Huy Bui
// Description: the program show the number of oscillating grades
#include <stdio.h>

/// Counting the number of new low and high grades in the array from left to right
/// \param grades: array of grades
/// \param numGrades: number of grades in the array
/// \return
int oscGrade(int const grades[], int numGrades) {
    int i = 1;
    int abnormal = 0;
    int hiGrade = grades[0], loGrade = grades[0];
    for (; i < numGrades; i++) {
        if (grades[i] > hiGrade) {
            hiGrade = grades[i];
            abnormal++;
        } else if (grades[i] < loGrade) {
            loGrade = grades[i];
            abnormal++;
        } else continue;
    }
    return abnormal;
}

int main() {
    int grades[10000];
    int numGrades;
    int index = 0;

    // Store user's input in numGrades
    printf("Enter the number of grades: ");
    scanf("%d", &numGrades);

    printf("Enter the grades: ");
    // Added grades into the array until the last character is a new line character or the count reached numGrades
    do {
        scanf("%d", &grades[index++]);
    } while (getchar() != '\n' || index < numGrades);

    int abnormalities = oscGrade(grades, numGrades);
    // Print the number of oscillating grades
    printf("%d\n", abnormalities);
    return 0;
}