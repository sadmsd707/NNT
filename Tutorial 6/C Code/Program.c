#include <stdio.h> 
#include <stdlib.h> 
struct node { 
int data; 
struct node *next; 
}; 
struct node *top = NULL; 
void push(int x) { 
struct node *n = malloc(sizeof(struct node)); 
n->data = x; 
n->next = top; 
top = n; 
} 
void pop() { 
if (top == NULL) { 
printf("Stack is empty\n"); 
return; 
} 
struct node *t = top; 
printf("Popped: %d\n", t->data); 
top = top->next; 
free(t); 
} 
void display() { 
    struct node *p = top; 
    if (p == NULL) printf("Stack is empty\n"); 
    while (p != NULL) { 
        printf("%d\n", p->data); 
        p = p->next; 
    } 
} 
int main() { 
    int ch, x; 
    do { 
        printf("\n1.Push 2.Pop 3.Display 4.Exit: "); 
        scanf("%d", &ch); 
        if (ch == 1) { 
            printf("Enter number: "); 
            scanf("%d", &x); 
            push(x); 
        } 
        else if (ch == 2) pop(); 
        else if (ch == 3) display(); 
    } while (ch != 4); 
    return 0; 
}
