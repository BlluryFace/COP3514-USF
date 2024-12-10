// Name: Huy Bui
// Description: A program that check if a customers attend more
// than a specific amount of classes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# define MAX_LETTERS 100
#define MAX_ENTRY 200
struct customer {
    char email[MAX_LETTERS];
    int numLessons;
    char name[MAX_LETTERS];
};
/// Compare between the value before and after
/// \param p1: pointer to the current element
/// \param p2: pointer to the next element
/// \return compare result
int comp(const void* p1, const void* p2){
    return ((struct customer*)p2)->numLessons - ((struct customer*)p1)->numLessons;
}


/// Read the input file and extract its content to put into a struct
/// \param inFile: pointer to the file's content
/// \param format: Extraction format
/// \param customers: the struct format for storing the values
/// \return number of entries in the sturct
int insert(FILE *inFile, char format[], struct customer customers[]){
    int numCustomers = 0;
    char email[MAX_LETTERS] = "";
    int numLessons = 0;
    char name[MAX_LETTERS] = "";
    while (fscanf(inFile, format, email, &numLessons, name) == 3) {
        strcpy(customers[numCustomers].email, email);
        customers[numCustomers].numLessons = numLessons;
        strcpy(customers[numCustomers].name, name);
        numCustomers++;
    }
    qsort(customers, numCustomers, sizeof(struct customer), comp);
    return numCustomers;
}

/// Search for customers who exceed a certain number of lessons
/// \param customers: the entries of data that will be searched
/// \param n: number of entries in the struct
/// \param numLessons: cap of number of lessons
/// \param result: the enties of customers that exceed the number of lessons
/// \return the number of entries in the struct
int search(struct customer customers[], int n, int numLessons, struct customer result[]){
    int numResult = 0;
    for (int i = 0; i < n; i++){
        if (customers[i].numLessons > numLessons){
            strcpy(result[numResult].email, customers[i].email);
            result[numResult].numLessons = customers[i].numLessons;
            strcpy(result[numResult].name, customers[i].name);
            numResult++;
        }
    }
    return numResult;
}

int main() {
    FILE *inFile = fopen("customers.csv", "r");
    if (inFile == NULL) {
        printf("Error opening inFile");
    }
    struct customer customers[MAX_ENTRY];
    int numCustomers = insert(inFile, "%[^,],%d,%[^\n]\n", customers);
    fclose(inFile);

    int numLessons = 0;
    printf("Enter the numbers of lessons: ");
    scanf("%d", &numLessons);

    struct customer result[MAX_ENTRY];
    int numResult = search(customers, numCustomers, numLessons, result);

    FILE *outFile = fopen("result.csv", "w");
    for (int i = 0; i < numResult; i++){
        fprintf(outFile, "%s,%d,%s\n", result[i].email, result[i].numLessons, result[i].name);
    }
    fclose(outFile);
}