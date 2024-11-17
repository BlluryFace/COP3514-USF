#include <stdio.h>

void read_line(char *str, int n) {
    int ch = 0, i = 0;
    while ((ch = getchar()) == ' ' || ch == '\t');
    *str = ch;
    str++;
    while((ch = getchar()) != '\n') {
        if (i < n) {
            *str = ch;
            str++;
        }
    }
    *str = '\0';
}

int main() {
    int n = 10;
    char str[n];
    read_line(str, n);
    printf("%s", str);
}