#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *first = NULL, *last = NULL;

typedef struct Node Node;


int countNodes(Node *p);

void insertAtBeg(int elem);
void insertAtMid(Node *p, int elem, int pos);
void insertAtEnd(int elem);

int deleteAtBeg();
int deleteAtMid(Node *p, int pos);
int deleteAtEnd();

void displayList(Node *p);
void revDisplayList(Node *p);

 
int main() {
    int ch = 1, op;
    int elem, pos;

    while (ch) {
        printf("\nDoubly Linked List\n");
        printf("\n1. Insert at start");
        printf("\n2. Insert at mid");
        printf("\n3. Insert at end");
        printf("\n4. Delete at start");
        printf("\n5. Delete at mid");
        printf("\n6. Delete at end");
        printf("\n7. Display from start");
        printf("\n8. Display from end (Reverse display)");
        printf("\n9. Exit\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    insertAtBeg(elem);
                    break;
            case 2:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    printf("\nEnter position : ");
                    scanf("%d", &pos);
                    insertAtMid(first, elem, pos);
                    break;
            case 3:
                    printf("\nEnter element : ");
                    scanf("%d", &elem);
                    insertAtEnd(elem);
                    break;
            case 4:
                    printf("%d\n", deleteAtBeg());
                    break;
            case 5:
                    printf("\nEnter position : ");
                    scanf("%d", &pos);
                    printf("%d\n", deleteAtMid(first, pos));
                    break;
            case 6:
                    printf("%d\n", deleteAtEnd());
                    break;
            case 7:
                    displayList(first);
                    break;
            case 8:
                    revDisplayList(last);
                    break;
            case 9:
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


int countNodes(Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void displayList(Node *p) {
    if (p == NULL) {
        printf("Empty list\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    };

    printf("\n");
}

void revDisplayList(Node *p) {
    if (p == NULL) {
        printf("Empty list\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    };

    printf("\n");
}

void insertAtBeg(int elem) {
    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;
    t->prev = NULL;

    if (first == NULL) {
        t->next = NULL;
        first = last = t;
    } else {
        t->next = first;
        first->prev = t;
        first = t;
    }
}

void insertAtMid(Node *p, int elem, int pos) {
    if (p == NULL) {
        insertAtBeg(elem);
        return;
    }

    if (pos < 0 || pos > countNodes(p)) {
        printf("Please enter a valid position \n");
        return;
    } else if (pos == 0) {
        insertAtBeg(elem);
        return;
    } else if (pos == countNodes(p)) {
        insertAtEnd(elem);
        return;
    }

    int i=0;
    while (i < pos-1) {
        p = p->next;
        i++;
    }

    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;

    t->prev = p; 
    t->next = p->next;
    (p->next)->prev = t;
    p->next = t;
}

void insertAtEnd(int elem) {
    if (first == NULL) {
        insertAtBeg(elem);
        return;
    }

    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;

    t->prev = last;
    t->next = NULL;
    last->next = t;
    last = t;
}

int deleteAtBeg() {
    if (first == NULL) 
        return -1;

    int elem;

    if (first == last) {
        elem = first->data;
        free(first);
        first = last = NULL;
        return elem;
    }
    
    Node *t = first;
    first = first->next;
    first->prev = NULL;

    elem = t->data;
    free(t);

    return elem;
}

int deleteAtMid(Node *p, int pos) {
    if (p == NULL)
        return -1;

    if (pos < 0 || pos > countNodes(p)) {
        printf("Please enter a valid position \n");
        return -1;
    } 
    else if (pos == 0)
        return deleteAtBeg();

    else if (pos == countNodes(p))
        return deleteAtEnd();

    if (first == last)
        return deleteAtBeg();

    int i = 0;
    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    
    Node *t = p->next;

    p->next->next->prev = p;
    p->next = p->next->next;

    int elem = t->data;
    free(t);

    return elem;
}

int deleteAtEnd() {
    if (first == NULL)
        return -1;

    int elem;

    if (first == last)
        return deleteAtBeg();
    
    Node *t = last;
    last = last->prev;
    last->next = NULL;

    elem = t->data;
    free(t);

    return elem;
}