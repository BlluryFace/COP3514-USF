#include <stdio.h>
void decompose(double x, int *int_part,
               double *frac_part)
{
    *int_part = (int) x;
    *frac_part = x - *int_part;
}

int main() {
    int i = 0;
    double d = 0.0;
    // The pointers now point to i and d (modifying value of i and d)
    decompose(3.14159, &i, &d);
    printf("%d, %lf", i, d);
    return 0
}