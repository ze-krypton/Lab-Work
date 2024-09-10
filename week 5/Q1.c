#include <stdio.h>
int main()
{
    int n, i, j, b, k, temp;
    int m;

    // first array
    printf("enter the size of first array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("enter the no. of elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // second array
    printf("enter the size of second array:\n");
    scanf("%d", &m);

    int brr[m];

    printf("enter the no. of elements :\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &brr[i]);
    }

    // bubble for 1st
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
    //print1st
      for (j = 0; j < n; j++)
    {
        printf("%d\t", arr[j]);
    }
    printf("\n");

    // bubble for 2nd
    for (b = 0; b < m - 1; b++)
    {

        for (k = 0; k < m - 1; k++)
        {

            if (brr[k] > brr[k + 1])
            {
                temp = brr[k];
                brr[k] = brr[k + 1];
                brr[k + 1] = temp;
            }
        }
    }

//print 2nd
    for (j = 0; j < m; j++)
    {
        printf("%d\t", brr[j]);
    }

//merge
  int merged[n + m];
    int x = 0, y = 0, z = 0;

    while (x < n && y < m) {
        if (arr[x] < brr[y]) {
            merged[z++] = arr[x++];
        } else {
            merged[z++] = brr[y++];
        }
    }


    while (x < n) {
        merged[z++] = arr[x++];
    }


    while (y < m) {
        merged[z++] = brr[y++];
    }

    // Printing merged array
    printf("\nMerged array:\n");
    for (i = 0; i < n + m; i++) {
        printf("%d\t", merged[i]);
    }
    printf("\n");

    return 0;
}
    