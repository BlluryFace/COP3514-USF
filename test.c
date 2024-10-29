#include <stdio.h>
int f(char *s, char *t)
{

    char *p1, *p2;

    for(p1 = s, p2 = t; *p1 != '\0' && *p2 != '\0'; p1++, p2++){

        if (*p1 == *p2) break;

    }
    return p1 -s;

}

int main() {
    int a[] = {1,2,3,4};
    int *p = 0;
    char str[4] = "word";
    if (p == &a[0]){};
    if (*p == *a){};
    if (*p == a[0]){};
    if (p == a[0]){};
    if (*p == a){};
    if (&p == a){};
    if (p == &a[0]){};
    printf("%d", f("accd", "dacd"));
}