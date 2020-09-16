#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

typedef struct Node Node;


void push(int elem);
int pop();
void peek(Node *p);


int main() {
    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nStack using Linked List\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek / Display");
        printf("\n4. Exit\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    push(elem);
                    break;
            case 2:
                    pop();
                    break;
            case 3:
                    peek(top);
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    break;
        }

        printf("\nDo you wish to continue? (1/0) : ");
        scanf("%d", &ch);
    }

    return 0;
}


void push(int elem) {
    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;
    if (top == NULL)
        t->next = NULL;
    else
        t->next = top;
    top = t;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow \n");
        return -1;
    }

    Node *t = top;
    int elem = t->data;
    top = top->next;
    free(t);
    
    return elem;
}

void peek(Node *p) {
    if (p == NULL) {
        printf("Empty stack\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}