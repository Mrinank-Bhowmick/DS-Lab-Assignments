#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
}Node;

void display(Node* head){
    Node* curr=head;
    while(curr != NULL){
        printf("%dX^%d ",curr->coeff,curr->exp);
        if(curr->next != NULL){
            printf("+");
        }
        curr = curr->next;
    }
}

Node* createnode(int coeff,int exp){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coeff=coeff;
    temp->exp=exp;
    temp->next=NULL;
    return temp;
}

void createpoly(Node** head){
    Node* temp = NULL;
    int term;
    int coeff;
    int exp;
    printf("Enter the number of terms in a polynomial: ");
    scanf("%d",&term);

    for(int i = 0; i<term; i++){
        printf("Enter coeff: ");
        scanf("%d", &coeff);
        printf("Enter exp: ");
        scanf("%d", &exp);
        
        Node* newnode = createnode(coeff,exp);

        if(*head == NULL){
            *head = newnode;
            temp = *head;
        } 
        else{
            temp->next=newnode;
            temp= temp->next;
        }
    }
}

int main(){
    Node* head = NULL;
    while(1==1){
        int choice;
        printf("Enter 1 for display and 2 for creation: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (head == NULL) {
                printf("Polynomial is empty.\n");
            } else {
                display(head);
            }
        } else if (choice == 2) {
            createpoly(&head);
        }      

        }
    
}


