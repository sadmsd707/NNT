#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the stack

int stack[MAX];
int top = -1; // -1 indicates an empty stack

// Check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Insert an element onto the stack
void push(int item) {
    if (isFull()) {
        printf("\n[Error] Stack Overflow! Cannot push %d.\n", item);
        return;
    }
    top++;
    stack[top] = item;
    printf("\n[Success] Pushed %d onto the stack. TOP is now at index %d.\n", item, top);
}

// Remove and return the top element
int pop() {
    if (isEmpty()) {
        printf("\n[Error] Stack Underflow! Stack is empty.\n");
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}

// Display contents and the position of TOP
void display() {
    if (isEmpty()) {
        printf("\nStack is empty. (TOP = -1)\n");
        return;
    }

    printf("\n--- Stack Status ---");
    printf("\nTOP Index   : %d", top);
    printf("\nTOP Value   : %d", stack[top]);
    printf("\nStack Elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        if (i == top) {
            printf("  | %4d | <-- TOP (Index %d)\n", stack[i], i);
        } else {
            printf("  | %4d |     (Index %d)\n", stack[i], i);
        }
    }
    printf("  +------+\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n=== STACK (ARRAY IMPLEMENTATION) ===");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY & TOP POSITION");
        printf("\n4. EXIT");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1) {
                    printf("\n[Success] Popped element: %d\n", val);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }

    return 0;
}
