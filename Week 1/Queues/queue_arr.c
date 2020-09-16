#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int size;
    int front;
    int rear;
};

typedef struct Queue Queue;


int isFull(Queue *queue);
int isEmpty(Queue *queue);

void enqueue(Queue *queue, int elem);
int dequeue(Queue *queue);

void displayQueue(Queue *queue);


int main() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));

    printf("Enter size of queue : ");
    scanf("%d", &queue->size);

    queue->arr = (int*) malloc(queue->size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;

    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nQueue using Array\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display queue");
        printf("\n4. Exit\n");
        
        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    enqueue(queue, elem);
                    break;
            case 2:
                    dequeue(queue);
                    break;
            case 3:
                    displayQueue(queue);
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


int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void enqueue(Queue *queue, int elem) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->arr[++queue->rear] = elem;   
        queue->front++;
    } else {
        queue->arr[++queue->rear] = elem; 
    }
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    return queue->arr[queue->front++];
}

void displayQueue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue underflow!\n");
        return;
    }

    int i;
    for (i=0; i<queue->rear; i++)
        printf("%d ", queue->arr[i]);
    printf("\n");
}