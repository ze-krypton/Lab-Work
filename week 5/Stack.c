#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed into the stack.\n", element);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    } else {
        int poppedElement = stack[top];
        top--;
        printf("%d popped from the stack.\n", poppedElement);
        return poppedElement;
    }
}

void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
