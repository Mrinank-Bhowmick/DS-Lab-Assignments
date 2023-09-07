#include <stdio.h>
#include <stdlib.h>

// display a polynomial

typedef struct node {
    float coef;
    int exp;
    struct node *next;
} Node;

Node *createNode(int coef, int exp) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%.1fx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void insert(Node **head, int coef, int exp) {
    Node *newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    printf("Enter the number of terms in the polynomial: ");
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i + 1);
        float coef;
        int  exp;
        scanf("%f %d", &coef, &exp);
        insert(&head, coef, exp);
    }
    display(head);
    return 0;
}
