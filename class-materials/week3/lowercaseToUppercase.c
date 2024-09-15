#include <stdio.h>
#include <ctype.h> // Check character status and convert character lib
#include <string.h> // Manipulating string functions lib
int main() {
    char sen[100]; // Create an array of characters that contain a maximum
                   // of 100 characters aka. a string that contains 100 char max
    printf("Enter the string that you want to turn into uppercase\n");
    scanf("%[^\n]s", sen); // Take every word in input except the new line command
    for (int i = 0; i <= strlen(sen); i++)
        sen[i] = toupper(sen[i]); // Convert to uppercase function
    printf("%s", sen); // %s here is string type holder
    return 0;
}
