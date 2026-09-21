#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;

        printf("%d pushed into stack.\n", value);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}
void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");

        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf(" press 1 to push\n");
        printf(" press 2 to Pop\n");
        printf("press 3 to Peek\n");
        printf(" press 4 to Display\n");
        printf(" press 5 to Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
