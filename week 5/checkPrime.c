#include <stdio.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int lower, upper;

    printf("Enter two numbers (intervals): ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are:\n", lower, upper);

    for (int num = lower; num <= upper; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");

    return 0;
}
