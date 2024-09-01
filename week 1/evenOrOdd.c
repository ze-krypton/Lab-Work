#include <stdio.h>
int main()
{
    int e;
    printf("Enter a number:");
    scanf("%d", &e);

    if (e % 2 ==0)
    {
        printf("it is even\n");
    }
    else
    {
        printf("it is odd\n");
    }
    return 0;
}