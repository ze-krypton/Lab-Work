#include <stdio.h>
int main()
{
    int i, j, r, c, n;

    printf("enter the size of rows and columns :");
    scanf("%d %d", &r, &c);
    int matrix[r][c], transpose[c][r];

    printf("enter the Elements :");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("[%d][%d]:", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Orignal Matrix : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf(" \n ");
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    printf("transpose Matrix :\n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}