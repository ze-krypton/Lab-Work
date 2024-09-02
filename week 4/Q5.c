#include <stdio.h>
int main()
{
    int arr[20];
    int n, i, j, b, k , temp;

    printf("enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter the Elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // bubbble

    for (b = 0; b < n - 1; b++)
    {
        for (k = 0; k < n - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    printf(" Elements : \n");

    for (j = 0; j < n; j++)
    {
        printf("%d\t", arr[j]);
    }
    return 0;
}