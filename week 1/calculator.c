#include <stdio.h>

int main()
{
    int a, b, result;
    char op;
    printf("Enter a symbol (+,-,*,/): ");
    scanf(" %c", &op);

     printf("Enter 2 numbers: ");
    scanf(" %d  %d", &a,&b);


    switch (op)
    {
    case '+':
        result = a + b;
        printf("Sum of %d + %d = %d\n", a, b, result);
        break;
    case '-':
        result = a - b;
        printf("difference of %d - %d = %d\n", a, b, result);
        break;
    case '/':
        if (b != 0)
        {
            result = a / b;
            printf("Division of %d / %d = %d\n", a, b, result);
        }
        else
        {
            printf("Logical Error!\n");
        }

        break;
    case '*':
        result = a * b;
        printf("Sum of %d * %d = %d\n", a, b, result);
        break;
    default:
        printf("Enter a valid operation!\n");
    }
    return 0;
}
