#include <stdio.h>

int main() {
    int n, binary, rem, decimal = 0, base = 1;


    printf("Enter a binary number: ");
    scanf("%d", &n);

    binary = n;


    while (n > 0) {
        rem = n % 10;          
        decimal += rem * base; 
        n /= 10;               
        base *= 2;             
    }


    printf("Binary number: %d\n", binary);
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
