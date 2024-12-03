#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int main() {
// stack --> declare static array
// heap ---> dynamic memory
// static data: global variables
// data (code instruction)

// malloc ---> allocating mem with no clearance
// calloc ---> allocating mem with clearence
// reacloc --> reallocate size
// Ask user to enter a string
    printf("Enter a name: \n");
    char buffer[100];
    scanf("s%", buffer);
    // allocate the appropriate the amount of space to store the string
    char *name;
    name = malloc(sizeof(char) * (strlen(buffer) + 1)); //because the strlen
    // function does not include the Null character
    // variable name store the pointer points to the address of the memory
    if (name = NULL) {
        printf("fail");
        return 1;
    }
    strcpy(name, buffer);
    printf("Name: %s\n", name);

    free(name);

}