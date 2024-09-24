#include <stdio.h>
int compute(int low, int high){
    printf("%d: %d\n", low, high);
    if (low == high) return 0;

    else return 1 + compute(low+1, high);

}

#include <stdio.h>
#define WEEKLY 7
#define BIWEEKLY WEEKLY+WEEKLY
int days(void) {
    int days = 10*BIWEEKLY;
    printf("%d\n", days);
    return 0;
    int age = 3;
}

int main(){
    return compute(3,5), days();
};