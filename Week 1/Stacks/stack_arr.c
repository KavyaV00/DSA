#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int size;
    int top;
};

typedef struct Stack Stack;


int isFull(Stack *stack);
int isEmpty(Stack *stack);

void push(Stack *stack, int elem);
int pop(Stack *stack);
int peek(Stack *stack);


int main() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));

    printf("Enter size of stack : ");
    scanf("%d", &stack->size);

    stack->top = -1;
    stack->arr = (int*) malloc(stack->size * sizeof(int));

    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nStack using Array\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek / Display");
        printf("\n4. Exit\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    push(stack, elem);
                    break;
            case 2:
                    pop(stack);
                    break;
            case 3:
                    printf("\n%d\n", peek(stack));
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


int isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int elem) {
    if (isFull(stack)) {
        printf("\nStack overflow! \n");
        return;
    }
    stack->arr[++stack->top] = elem;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nStack underflow! \n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\n Stack is empty! \n");
        return -1;
    }
    return stack->arr[stack->top];
}

