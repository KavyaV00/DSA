#include <stdio.h>
#include <stdlib.h>

struct CQueue {
    int *arr;
    int size;
    int front;
    int rear;
};

typedef struct CQueue CQueue;


void enqueue(CQueue *cQ, int elem);
int dequeue(CQueue *cQ);

int getFront(CQueue *cQ);
int getRear(CQueue *cQ);

void displayCQueue(CQueue *cQ);


int main() {
    CQueue *cQ = malloc(sizeof(CQueue));

    printf("Enter size of circular queue : ");
    scanf("%d", &cQ->size);

    cQ->arr = malloc(cQ->size * sizeof(int));
    cQ->front = -1;
    cQ->rear = -1;

    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nCircular Queue using Array\n");
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
                    enqueue(cQ, elem);
                    break;
            case 2:
                    printf("%d\n", dequeue(cQ));
                    break;
            case 3:
                    printf("%d\n", getFront(cQ));
                    break;
            case 4:
                    printf("%d\n", getRear(cQ));
                    break;
            case 5:
                    displayCQueue(cQ);
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


void enqueue(CQueue *cQ, int elem) {
    if ((cQ->front == 0 && cQ->rear == cQ->size - 1) 
        || cQ->rear == ((cQ->front - 1) % (cQ->size - 1)))
            printf("Queue overflow!\n");

    else if (cQ->front == -1) {
        cQ->front = cQ->rear = 0;
        cQ->arr[cQ->rear] = elem;
    }

    else if (cQ->rear == cQ->size - 1 && cQ->front != 0) {
        cQ->rear = 0;
        cQ->arr[cQ->rear++] = elem;
    }

    else
        cQ->arr[++cQ->rear] = elem;
}

int dequeue(CQueue *cQ) {
    if (cQ->front == -1) {
        printf("Stack underflow!\n");
        return -1;
    }

    int elem = cQ->arr[cQ->front];

    if (cQ->front == cQ->rear)
        cQ->front = cQ->rear = -1;

    else if (cQ->front == cQ->size - 1)
        cQ->front = 0;

    else
        cQ->front++;
    
    return elem;
}

int getFront(CQueue *cQ) {
    if (cQ->front != -1)
        return cQ->arr[cQ->front];

    printf("Empty queue\n");
    return -1;
}

int getRear(CQueue *cQ) {
    if (cQ->rear != cQ->size - 1 && cQ->rear != -1)
        return cQ->arr[cQ->rear];

    printf("Empty queue\n");
    return -1;
}

void displayCQueue(CQueue *cQ) {
    if (cQ->front == -1) {
        printf("Empty queue\n");
        return;
    }
    
    int i;
    if (cQ->rear >= cQ->front) {
        for (i=cQ->front; i<=cQ->rear; i++)
            printf("%d ", cQ->arr[i]);
    }
    
    else {
        for (i=cQ->front; i<cQ->size-1; i++)
            printf("%d ", cQ->arr[i]);
        for (i=0; i<=cQ->rear; i++)
            printf("%d ", cQ->arr[i]);
    }
}