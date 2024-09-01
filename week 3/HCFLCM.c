#include <stdio.h>

int main() {
    int num1, num2, hcf, lcm, temp1, temp2, remainder;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    temp1 = num1;
    temp2 = num2;

    while (temp2 != 0) {
        remainder = temp1 % temp2;
        temp1 = temp2;
        temp2 = remainder;
    }

    hcf = temp1;
    lcm = (num1 * num2) / hcf;

    printf("HCF of %d and %d is: %d\n", num1, num2, hcf);
    printf("LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}
