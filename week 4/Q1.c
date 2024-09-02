#include <stdio.h>
int main()
{

    int n;

    printf("enter the length of the array : ");
    scanf("%d", &n);
    int arr[n];

    printf("enter the %d elements  : \n ", n);
//forgot to scan values 
    for (int i = 0; i < n; i++)
    {
        printf("Elemet %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    float average;
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
        printf("\n");
    }
    average = (float)sum / n;
    printf("Average : %f \nsum : %d\nMax: %d\nmin: %d \n", average, sum, max, min);
}