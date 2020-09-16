#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

typedef struct Node Node;


int countNodes(Node *p);

void insertAtBeg(int elem);
void insertAtMid(Node *p, int elem, int pos);
void insertAtEnd(Node *p, int elem);

int deleteAtBeg();
int deleteAtMid(Node *p, int pos);
int deleteAtEnd(Node *p);

void displayList(Node *p);

 
int main() {
    int ch = 1, op;
    int elem, pos;

    while (ch) {
        printf("\nSingly Linked List\n");
        printf("\n1. Insert at start");
        printf("\n2. Insert at mid");
        printf("\n3. Insert at end");
        printf("\n4. Delete at start");
        printf("\n5. Delete at mid");
        printf("\n6. Delete at end");
        printf("\n7. Display list");
        printf("\n8. Exit\n");

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
                    insertAtEnd(first, elem);
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
                    printf("%d\n", deleteAtEnd(first));
                    break;
            case 7:
                    displayList(first);
                    break;
            case 8:
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

void insertAtBeg(int elem) {
    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;

    if (first == NULL) {
        t->next = NULL;
        first = t;
    } else {
        t->next = first;
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
        insertAtEnd(first, elem);
        return;
    }

    int i=0;
    while (i < pos-1) {
        p = p->next;
        i++;
    }

    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;
    
    t->next = p->next;
    p->next = t;
}

void insertAtEnd(Node *p, int elem) {
    if (first == NULL) {
        insertAtBeg(elem);
        return;
    }

    while (p->next != NULL) 
        p = p->next;

    Node *t = (Node*) malloc(sizeof(Node));
    t->data = elem;

    t->next = NULL;
    p->next = t;
}

int deleteAtBeg() {
    if (first == NULL) 
        return -1;

    int elem;

    if (first->next == NULL) {
        elem = first->data;
        free(first);
        first = NULL;
        return elem;
    }
    
    Node *t = first;
    first = first->next;

    elem = t->data;
    free(t);

    return elem;
}

int deleteAtMid(Node *p, int pos) {
    int i = 0;
    if (p == NULL)
        return -1;

    if (pos < 0 || pos > countNodes(p)) {
        printf("Please enter a valid position \n");
        return -1;
    } 
    else if (pos == 0 || p->next == NULL)
        return deleteAtBeg();    
    else if (pos == countNodes(p))
        return deleteAtEnd(p);

    if (first->next == NULL)
        return deleteAtBeg();

    int elem;

    while (i < pos - 1) {
        p = p->next;
        i++;
    }
    
    Node *t = p->next;

    p->next = p->next->next;

    elem = t->data;
    free(t);

    return elem;
}

int deleteAtEnd(Node *p) {
    int elem;

    if (p == NULL) {
        return -1;
    }

    if (p->next == NULL) {
        elem = p->data;
        free(p);
        first = NULL;
        return elem;
    }
    
    while (p->next->next != NULL)
        p = p->next;

    Node *t = p->next;
    p->next = NULL;
    elem = t->data;
    free(t);

    return elem;
}