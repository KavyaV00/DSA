#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

typedef struct Node Node;


void enqueue(int elem);
int dequeue();

void displayQueue(Node *p);


int main() {
    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nQueue using Linked List\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        
        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    enqueue(elem);
                    break;
            case 2:
                    dequeue();
                    break;
            case 3:
                    displayQueue(front);
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


void enqueue(int elem) {
    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;
    t->next = NULL;
    
    if (front == NULL && rear == NULL)
        front = rear = t;
    else {
        rear->next = t;
        rear = t;
    }
}

int dequeue() {
    Node *t = front;
    int elem = t->data;
    
    front = front->next;
    free(t);

    return elem;
}

void displayQueue(Node *p) {
    if (p == NULL) {
        printf("Empty queue\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}