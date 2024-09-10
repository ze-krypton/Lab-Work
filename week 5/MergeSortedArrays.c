#include <stdio.h>

int main()
{
    int n, i, j, b, k, temp, m;

    // Input for first array
    printf("Enter the size of the first array:\n");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input for second array
    printf("Enter the size of the second array:\n");
    scanf("%d", &m);
    int brr[m];

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &brr[i]);
    }

    // Bubble sort for the first array
    for (b = 0; b < n - 1; b++) {
        for (k = 0; k < n - 1; k++) {
            if (arr[k] > arr[k + 1]) {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    // Bubble sort for the second array
    for (b = 0; b < m - 1; b++) {
        for (k = 0; k < m - 1; k++) {
            if (brr[k] > brr[k + 1]) {
                temp = brr[k];
                brr[k] = brr[k + 1];
                brr[k + 1] = temp;
            }
        }
    }

    // Printing sorted first array
    printf("Sorted first array:\n");
    for (j = 0; j < n; j++) {
        printf("%d\t", arr[j]);
    }
    printf("\n");

    // Printing sorted second array
    printf("Sorted second array:\n");
    for (j = 0; j < m; j++) {
        printf("%d\t", brr[j]);
    }
    printf("\n");

    // Merging the two sorted arrays
    int merged[n + m];
    int x = 0, y = 0, z = 0;

    while (x < n && y < m) {
        if (arr[x] < brr[y]) {
            merged[z++] = arr[x++];
        } else {
            merged[z++] = brr[y++];
        }
    }

    // If there are remaining elements in arr
    while (x < n) {
        merged[z++] = arr[x++];
    }

    // If there are remaining elements in brr
    while (y < m) {
        merged[z++] = brr[y++];
    }

    // Printing merged array
    printf("Merged array:\n");
    for (i = 0; i < n + m; i++) {
        printf("%d\t", merged[i]);
    }
    printf("\n");

    return 0;
}
