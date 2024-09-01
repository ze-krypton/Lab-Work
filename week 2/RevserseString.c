#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, j;

    // Input the string from the user
    printf("Enter a string: ");
    gets(str);

    // Find the length of the string
    int len = strlen(str);

    // Reverse the string
    for(i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Output the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
