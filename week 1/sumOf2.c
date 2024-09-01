#include <stdio.h>
int main()
{
    int a, c, sum;
    printf("Enter 2 numbers :");
    scanf(" %d %d", &a, &c);

    sum = a + c;
    printf("Sum of %d + %d = %d\n", a, c, sum);
    return 0;
}