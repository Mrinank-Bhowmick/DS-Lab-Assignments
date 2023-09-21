#include<stdio.h>
#include<malloc.h>

typedef struct Node {
    int row;
    int col;
    int val;
    struct Node *next;
}node;

void createTriplet(node **head) {
    node *ptr, *temp;
    int i, j, m, n, val, nz = 0;
    printf("Enter the number of rows : ");
    scanf("%d", &m);
    printf("Enter the number of columns : ");
    scanf("%d", &n);
    int mat[m][n];
    printf("Enter the elements of marix(row-wise) :- \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            val = mat[i][j];
            if(val != 0) {
                ptr = (node *)malloc(sizeof(node));
                ptr->row = i;
                ptr->col = j;
                ptr->val = val;
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
                nz++;
            }
        }
    }
    ptr = (node *)malloc(sizeof(node));
    ptr->row = m;
    ptr->col = n;
    ptr->val = nz;
    ptr->next = *head;
    *head = ptr;
}

void displayTriplet(node *head) {
    node *ptr = head;
    printf("Row\tColumn\tValue\n");
    while(ptr != NULL) {
        printf("%d\t%d\t%d\n", ptr->row, ptr->col, ptr->val);
        ptr = ptr->next;
    }
}

void displaySparse(node *head) {
    node *ptr = head->next;
    int i, j, m = head->row, n = head->col;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(ptr != NULL && ptr->row == i && ptr->col == j) {
                printf("%d ", ptr->val);
                ptr = ptr->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    node *matrix = NULL;
    createTriplet(&matrix);
    printf("Sparse matrix : \n");
    displaySparse(matrix);
    printf("Triplet form : \n");
    displayTriplet(matrix);
}