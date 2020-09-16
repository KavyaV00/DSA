#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} *front = NULL, *rear = NULL;

typedef struct Node Node;


int isEmpty();

void insertFront(int elem);
void insertLast(int elem);

int deleteFront();
int deleteLast();

int getFront();
int getLast();


int main() {
    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nDeque using Linked List\n");
        printf("\n1. Insert front");
        printf("\n2. Insert last");
        printf("\n3. Delete front");
        printf("\n4. Delete last");
        printf("\n5. Get front");
        printf("\n6. Get last");
        printf("\n7. Exit\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    insertFront(elem);
                    break;
            case 2:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    insertLast(elem);
                    break;
            case 3:
                    deleteFront();
                    break;
            case 4:
                    deleteLast();
                    break;
            case 5:
                    printf("%d\n", getFront());
                    break;
            case 6:
                    printf("%d\n", getLast());
                    break;
            case 7:
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


int isEmpty() {
    if (front == NULL && rear == NULL)
        return 1;
    else 
        return 0;
}

void insertFront(int elem) {
    if (isEmpty()) {
        front = malloc(sizeof(Node));
        front->data = elem;
        front->next = NULL;
        front->prev = NULL;
        rear = front;
        return;
    }

    Node *t = malloc(sizeof(Node));
    t->data = elem;
    t->next = front;
    t->prev = NULL;

    front->prev = t;
    front = t;
}

void insertLast(int elem) {
    if (isEmpty()) {
        rear = malloc(sizeof(Node));
        rear->data = elem;
        rear->next = NULL;
        rear->prev = NULL;
        front = rear;
        return;
    }

    Node *t = malloc(sizeof(Node));
    t->data = elem;
    t->next = NULL;
    t->prev = rear;

    rear->next = t;
    rear = t;
}

int deleteFront() {
    if (isEmpty())
        return -1;
    
    Node *t = front;

    if (front == rear)
        front = rear = NULL;
    else {
        front = front->next;
        front->prev = NULL;
    }

    int elem = t->data;
    free(t);

    return elem;
}

int deleteLast() {
    if (isEmpty())
        return -1;
    
    Node *t = rear;

    if (front == rear)  
        front = rear = NULL;
    else {
        rear = rear->prev;
        rear->next = NULL;
    }

    int elem = t->data;
    free(t);

    return elem;
}

int getFront() {
    if (!isEmpty())
        return front->data;
    else 
        return -1;
}

int getLast() {
    if (!isEmpty())
        return rear->data;
    else 
        return -1;
}