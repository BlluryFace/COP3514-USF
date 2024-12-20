// Name: Huy Bui
// Description: Store and print details about students in a COP 2540 course

#ifndef STUDENT_H
#define STUDENT_H
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
#endif //STUDENT_H

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


