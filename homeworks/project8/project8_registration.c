#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 100
#define NETID_LEN 40

struct student {
    char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
    double gpa;
    int attempts;
    struct student *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts);
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts);
struct student * pop_student(struct student *registration);
void list_students(struct student *registration);
void list_gpa_min(struct student *registration, double gpa);
void list_cop2510_min(struct student *registration, int cop2510_grade);
struct student * clear_queue(struct student *registration);


///////////////////
// main function //
///////////////////

int main() {
    char code;
    char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
    double gpa;
    int attempts;

    struct student *registration = NULL;

    help();
    printf("\n");

    for (;;) {
        // read operation code
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n') /* skips to end of line */
            ;

        // run operation
        switch (code) {
            case 'h':
                help();
                break;
            case 'a':
                read(name, netid, &cop2510_grade, &gpa, &attempts);
                registration = add_student(registration, name, netid, cop2510_grade, gpa, attempts);
                break;
            case 'p':
                registration = pop_student(registration);
                break;
            case 'l':
                list_students(registration);
                break;
            case 'g':
                read(NULL, NULL, NULL, &gpa, NULL);
                list_gpa_min(registration, gpa);
                break;
            case 'c':
                read(NULL, NULL, &cop2510_grade, NULL, NULL);
                list_cop2510_min(registration, cop2510_grade);
                break;
            case 'q':
                registration = clear_queue(registration);
                return 0;
            default:
                printf("Illegal operation code!\n");
        }
        printf("\n");
    }
}

//////////////////////////
// function definitions //
//////////////////////////
void reverseLinkedList(struct student **list){
    struct student *prev = NULL;
    struct student *curr = *list;
    struct student *next = NULL;

    // Traverse the list and reverse the links
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *list = prev;
}
void help() {
    printf("List of operation codes:\n");
    printf("\t'h' for help;\n");
    printf("\t'a' for adding a student to the queue;\n");
    printf("\t'p' for removing a student from the queue;\n");
    printf("\t'l' for listing all students in the queue;\n");
    printf("\t'g' for searching students with a minimum GPA;\n");
    printf("\t'c' for searching students with a minimum grade in COP2510;\n");
    printf("\t'q' to quit.\n");
}

void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts) {
    if(name != NULL) {
        printf("Enter the name of the student: ");
        scanf("%[^\n]", name);
    }
    if(netid != NULL) {
        printf("Enter the NetID of the student: ");
        scanf("%s", netid);
    }
    if(cop2510_grade != NULL) {
        printf("Enter the COP2510 letter grade: ");
        scanf(" %c", cop2510_grade);
    }
    if(gpa != NULL) {
        printf("Enter the GPA: ");
        scanf("%lf", gpa);
    }
    if(attempts != NULL) {
        printf("Enter the number of previous attempts: ");
        scanf("%d", attempts);
    }
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

struct student * add_student(struct student *registration, char *name, char *netid,
                             char cop2510_grade, double gpa, int attempts) {

    // add code
    struct student *newStudent = malloc(sizeof(struct student));

    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    strcpy(newStudent->name, name);
    strcpy(newStudent->netid, netid);
    newStudent->cop2510_grade =  cop2510_grade;
    newStudent->gpa = gpa;
    newStudent->attempts = attempts;
    newStudent->next = registration;
    registration = newStudent;

    return registration;
}

struct student * pop_student(struct student *registration) {
    // add code
    if (registration == NULL) {
        return registration;
    }
    reverseLinkedList(&registration);
    // output format
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", registration->name, registration->netid, registration->cop2510_grade, registration->gpa, registration->attempts);
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    struct student *curr = registration->next;
    struct student *prev = registration;
    free(prev);
    registration = curr;

    reverseLinkedList(&registration);

    return registration;
}

void list_students(struct student *registration) {
    // add code
    if (registration == NULL) {
        return;
    }
    reverseLinkedList(&registration);
    struct student *curr = registration;
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    while (curr != NULL ) {
        // output format
        printf("|----------------------|----------------------|---------|-----|----------|\n");
        printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", curr->name, curr->netid, curr->cop2510_grade, curr->gpa, curr->attempts);
        curr = curr->next;
    }
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    reverseLinkedList(&registration);
}
void list_gpa_min(struct student *registration, double gpa) {
    if (registration == NULL) {
        return;
    }
    reverseLinkedList(&registration);
    struct student *curr = registration;
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    while (curr != NULL) {
        // output format
        if (curr->gpa >= gpa){
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", curr->name, curr->netid, curr->cop2510_grade,
                   curr->gpa, curr->attempts);
        }
        curr = curr->next;
    }
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    reverseLinkedList(&registration);
}

void list_cop2510_min(struct student *registration, int cop2510_grade) {
    if (registration == NULL) {
        return;
    }
    reverseLinkedList(&registration);
    struct student *curr = registration;
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    while (curr != NULL) {
        // output format
        if (curr->cop2510_grade <= cop2510_grade){
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", curr->name, curr->netid, curr->cop2510_grade,
                   curr->gpa, curr->attempts);
        }
        curr = curr->next;
    }
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    reverseLinkedList(&registration);
}

struct student * clear_queue(struct student *registration) {
    while (registration != NULL) {
        struct student *curr = registration->next;
        struct student *prev = registration;
        free(prev);
        registration = curr;
    }
    return registration;
}