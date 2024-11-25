#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for the linked list node
// This is structure for a book information
struct Node {
    int isbn;
    char name[50];
    struct Node* next;
};

// Helper function to create a new node
struct Node *createNode(int isbn, char *title) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->isbn = isbn;
    strcpy(newNode->name, title);
    newNode->next = NULL;
    
    return newNode;
}

struct Node *insertInOrder(struct Node *front, int isbn, char *title){
    struct Node *newNode = createNode(isbn, title);
    if (front == NULL || strcmp(newNode->name,front->name) > 0){
        newNode->next = front;
        front = newNode;
    } else {
        struct Node *curr  = front;
        while (curr->next != NULL && (strcmp(newNode->name, curr->next->name) < 0)){
            curr = curr->next;
        }
    }
}


int main() {
    struct Node* head = NULL;

    // Insert node into the linked list (reverse alphabetical order)

    // Print the entire list 

    // Search and delete a node 

    return 0;
}