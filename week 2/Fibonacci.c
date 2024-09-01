#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long t1 = 0, t2 = 1, nextterm;

    printf("Enter the number terms to be printed: \n");
    scanf(" %d", &n);

    printf("Fibonacci Series : %llu , %llu", t1, t2);
    for (i = 1; i < n - 1; i++)
    {
        nextterm=t1+t2;
        printf(", %llu",nextterm);

        t1=t2;
        t2=nextterm;
    }
    printf("\n");
}