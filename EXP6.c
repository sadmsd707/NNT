#include <stdio.h>
#include <stdlib.h>

// Node definition for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Pointer pointing to the top node of the stack
struct Node* top = NULL;

// Function to push (insert) an element onto the stack
void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation failed (Heap Overflow)
    if (newNode == NULL) {
        printf("\n[Error] Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("\n[Success] %d inserted into the stack.\n", item);
}

// Function to pop (delete) an element from the stack
void pop() {
    if (top == NULL) {
        printf("\n[Error] Stack Underflow! Stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;
    int poppedVal = temp->data;
    top = top->next;
    free(temp); // Free allocated node memory
    
    printf("\n[Success] Deleted element: %d\n", poppedVal);
}

// Function to display the stack contents
void display() {
    if (top == NULL) {
        printf("\nStack is empty. (TOP = NULL)\n");
        return;
    }
    
    struct Node* temp = top;
    printf("\n--- Current Stack (TOP to BOTTOM) ---\n");
    while (temp != NULL) {
        if (temp == top) {
            printf(" | %4d | <-- TOP\n", temp->data);
        } else {
            printf(" | %4d |\n", temp->data);
        }
        temp = temp->next;
    }
    printf(" +------+\n");
}

int main() {
    int choice, val;
    
    while (1) {
        printf("\n--- Experiment 06: Stack Using Linked List ---");
        printf("\n1. INSERT (Push)");
        printf("\n2. DELETE (Pop)");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                // Free remaining heap nodes before exiting
                while (top != NULL) {
                    struct Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please enter a choice from 1 to 4.\n");
        }
    }
    
    return 0;
}
