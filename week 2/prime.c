#include <stdio.h>

int main() {
    int n, i, count = 0;

    printf("Enter any Number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++; 
        }
    }

    if (count == 2) {
        printf("Prime Number\n");
    } else {
        printf("Not Prime Number\n");
    }

    return 0;
}
