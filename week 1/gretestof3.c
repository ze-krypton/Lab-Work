#include <stdio.h>
int main()
{
    int a, b, c;
    printf("enter 3 numbers;");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b)
    {
        printf("a is bigger\n");
    }
    else if (b > c)
    {
        printf("b is bigger\n");
    }
    else
    {
        printf("c is bigger\n");
    }

    return 0;
}