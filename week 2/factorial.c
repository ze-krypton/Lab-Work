#include <stdio.h>
int main()
{
    int n;
    unsigned long long fact = 1;

    printf("enter a number :");
    scanf(" %d", &n);

    if (n < 0)
    {
        printf("invalid !");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
            printf("Factorial of %d = %llu ", n, fact);
    }
        printf("\n");
}