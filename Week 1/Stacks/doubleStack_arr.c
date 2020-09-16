#include <stdio.h>
#include <stdlib.h>

struct DStack {
    int *arr;
    int size;
    int top1;
    int top2;
};

typedef struct DStack DStack;


void push1(DStack *dStack, int elem);
void push2(DStack *dStack, int elem);

int pop1(DStack *dStack);
int pop2(DStack *dStack);

int peek1(DStack *dStack);
int peek2(DStack *dStack);


int main() {
    DStack *dStack = malloc(sizeof(DStack));

    printf("Enter size of stack : ");
    scanf("%d", &dStack->size);

    dStack->arr = malloc(dStack->size * sizeof(int));
    dStack->top1 = -1;
    dStack->top2 = dStack->size;

    int ch = 1, op;
    int elem;

    while (ch) {
        printf("\nDouble Stack Array\n");
        printf("\n1. Push to stack 1");
        printf("\n2. Push to stack 2");
        printf("\n3. Pop from stack 1");
        printf("\n4. Pop from stack 2");
        printf("\n5. Peek / Display stack 1");
        printf("\n6. Peek / Display stack 2");
        printf("\n7. Exit\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    push1(dStack, elem);
                    break;
            case 2:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    push2(dStack, elem);
                    break;
            case 3:
                    printf("%d\n", pop1(dStack));
                    break;
            case 4:
                    printf("%d\n", pop2(dStack));
                    break;
            case 5:
                    printf("\n%d\n", peek1(dStack));
                    break;
            case 6:
                    printf("\n%d\n", peek2(dStack));
                    break;
            case 7:
                    exit(0);
            default:
                    break;
            }
            
        printf("\nDo you wish to continue? (1/0) : ");
        scanf("%d", &ch);
    }

    return 0;
}


void push1(DStack *dStack, int elem) {
    if (dStack->top2 - dStack->top1 > 0 && dStack->top1 < dStack->size - 1)
        dStack->arr[++dStack->top1] = elem;
    else 
        printf("Stack overflow!\n");
}

void push2(DStack *dStack, int elem) {
    if (dStack->top2 - dStack->top1 > 0 && dStack->top2 > 0)
        dStack->arr[--dStack->top2] = elem;
    else 
        printf("Stack overflow!\n");
}

int pop1(DStack *dStack) {
    if (dStack->top1 == -1) { 
        printf("Stack underflow!\n");
        return -1;
    }
    return dStack->arr[dStack->top1--];
}

int pop2(DStack *dStack) {
    if (dStack->top2 == dStack->size) { 
        printf("Stack underflow!\n");
        return -1;
    }
    return dStack->arr[dStack->top2++];
}


int peek1(DStack *dStack) {
    if (dStack->top1 == -1) { 
        printf("Empty stack 1\n");
        return -1;
    }
    return dStack->arr[dStack->top1];
}

int peek2(DStack *dStack) {
    if (dStack->top2 == dStack->size) { 
        printf("Empty stack 2\n");
        return -1;
    }
    return dStack->arr[dStack->top2];
}