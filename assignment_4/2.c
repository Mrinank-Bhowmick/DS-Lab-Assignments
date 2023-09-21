#include<stdio.h>
#include<malloc.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} poly;

poly * createPoly(poly **head) {
    int i = 1;
    poly *ptr, *temp;
    do {
        ptr = (poly *)malloc(sizeof(poly));
        ptr->next = NULL;
        if(*head == NULL) {
            *head = ptr;
        } else {
            temp = *head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
        }
        printf("Enter the coefficient of %d term : ", i);
        scanf("%d", &ptr->coeff);
        if(ptr->coeff == -1) {
            free(ptr);
            temp->next = NULL;
            break;
        }
        printf("Enter the power of %d term : ", i);
        scanf("%d", &ptr->exp);
        i++;
    } while(1);
    return *head;
}

void display(poly *head) {
    poly *p1 = head;
    while(p1 != NULL) {
        printf("(%dx^%d)", p1->coeff, p1->exp);
        p1 = p1->next;
        if(p1 != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }
    }
}

poly *addPoly(poly **start1, poly **start2, poly **start3) {
    poly *ptr3 = NULL;
    poly *ptr1 = *start1;
    poly *ptr2 = *start2;
    poly *temp;
    while(ptr1 != NULL && ptr2 != NULL) {
        ptr3 = (poly *)malloc(sizeof(poly));
        ptr3->next = NULL;
        if(*start3 == NULL) {
            *start3 = ptr3;
        } else {
            temp = *start3;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr3;
        }
        if(ptr1->exp == ptr2->exp) {
            ptr3->coeff = ptr1->coeff + ptr2->coeff;
            ptr3->exp = ptr1->exp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if(ptr1->exp > ptr2->exp) {
            ptr3->coeff = ptr1->coeff;
            ptr3->exp = ptr1->exp;
            ptr1 = ptr1->next;
        } else if(ptr1->exp < ptr2->exp) {
            ptr3->coeff = ptr2->coeff;
            ptr3->exp = ptr2->exp;
            ptr2 = ptr2->next;
        }
    }
    if(ptr1 != NULL) {
        while(ptr1 != NULL) {
            ptr3 = (poly *)malloc(sizeof(poly));
            ptr3->next = NULL;
            if(*start3 == NULL) {
                *start3 = ptr3;
            } else {
                temp = *start3;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = ptr3;
            }
            ptr3->coeff = ptr1->coeff;
            ptr3->exp = ptr1->exp;
            ptr1 = ptr1->next;
        }
    }
    if(ptr2 != NULL) {
        while(ptr2 != NULL) {
            ptr3 = (poly *)malloc(sizeof(poly));
            ptr3->next = NULL;
            if(*start3 == NULL) {
                *start3 = ptr3;
            } else {
                temp = *start3;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = ptr3;
            }
            ptr3->coeff = ptr2->coeff;
            ptr3->exp = ptr2->exp;
            ptr2 = ptr2->next;
        }
    }
    return *start3;
}

int main() {
    poly *start1 = NULL;
    poly *start2 = NULL;
    poly *start3 = NULL;
    printf("Enter polynomial 1\n");
    start1 = createPoly(&start1);
    printf("Enter polynomial 2\n");
    start2 = createPoly(&start2);
    printf("Input: Poly1 : ");
    display(start1);
    printf("       Poly2 : ");
    display(start2);
    start3 = addPoly(&start1, &start2, &start3);
    printf("Output: Poly3 : ");
    display(start3);
}