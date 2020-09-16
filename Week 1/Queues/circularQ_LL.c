#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

typedef struct Node Node;


void enqueue(int elem);
int dequeue();

int getFront();
int getRear();

void displayQueue(Node *p);


int main() {
    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nCircular Queue using Linked List\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Get front");
        printf("\n4. Get rear");
        printf("\n5. Display queue");
        printf("\n6. Exit\n");
        
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
                    printf("%d\n", getFront());
                    break;
            case 4:
                    printf("%d\n", getRear());
                    break;
            case 5:
                    displayQueue(front);
                    break;
            case 6:
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

    if (front == NULL || rear == NULL) {
        t->next = t;
        front = rear = t;
    }
    else {
        t->next = front;
        rear->next = t;
        rear = t;
    }
}

int dequeue() {
    Node *t = front;
    int elem = t->data;
    
    front = front->next;
    rear->next = front;

    free(t);

    return elem;
}

void displayQueue(Node *p) {
    if (p != NULL) {
        do {
            printf("%d ", p->data);
            p = p->next;
        } while (p != front);
    }
    else 
        printf("Empty queue");
    printf("\n");
}

int getFront() {
    if (front == NULL) {
        printf("Queue underflow!\n");
        return -1;
    }
    return front->data;
}

int getRear() {
    if (rear == NULL) {
        printf("Queue underflow!\n");
        return -1;
    }
    return rear->data;
}