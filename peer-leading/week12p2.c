#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int number;
    char name[25];
    struct Node *next;
};

struct Node *addToFront(struct Node *front, int *count, char name[]){
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed");
        return front;
    }

    newNode->number = *count;
    strcpy(newNode->name, name);
    newNode->next = front;

    *count++;

    return newNode;
}

int main(){
    struct Node *head = NULL;
    int count  = 0;
    addToFront(head, &count, "Doodlebob");
}