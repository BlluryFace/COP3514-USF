#ifndef LIBRARY_H

// global things
// Define a structure for the linked list node
// This is structure for a book information

struct Node {
    int isbn;
    char name[50];
    struct Node* next;
};
// function prototypes
struct Node *createNode(int isbn, char *title);
struct Node *insertInOrder(struct Node *front, int isbn, char *title);


#endif