#include<stdio.h>
#include<malloc.h>

typedef struct SparseMatrix {
    int m;
    int n;
    int non_zero;
    struct Triplet {
        int row;
        int col;
        int val;
    }*triplets;
}sparse;

void createTriplet(sparse *matrix) {
    int r, c, i, j, nz = 0; 
    printf("rows  : ");
    scanf("%d", &r);
    printf("columns : ");
    scanf("%d", &c);
    int mat[r][c];
    matrix->m = r;
    matrix->n = c;
    matrix->triplets = (struct Triplet *)malloc (matrix->m * (sizeof(struct Triplet)));
    printf("elements (row-wise) :- \n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
            if(mat[i][j] != 0) {
                matrix->triplets[nz].row = i;
                matrix->triplets[nz].col = j;
                matrix->triplets[nz].val = mat[i][j];
                nz++;
            }
        }
    }
    matrix->non_zero = nz;
}

void displaySparse(sparse matrix) {
    int i, j;
    int sparseMat[matrix.m][matrix.n];
    for(i = 0; i < matrix.m; i++) {
        for(j = 0; j < matrix.n; j++) {
            sparseMat[i][j] = 0;
        }
    }
    for(i = 0; i < matrix.non_zero; i++) {
        int a = matrix.triplets[i].row;
        int b = matrix.triplets[i].col;
        int v = matrix.triplets[i].val;
        sparseMat[a][b] = v;
    }
    for(i = 0; i < matrix.m; i++) {
        for(j = 0; j < matrix.n; j++) {
            printf("%d ", sparseMat[i][j]);
        }
        printf("\n");
    }
}

void displayTriplet(sparse matrix) {
    printf("%d\t%d\t%d\n", matrix.m, matrix.n, matrix.non_zero);
    for(int i = 0; i < matrix.non_zero; i++) {
        printf("%d\t%d\t%d\n", matrix.triplets[i].row, matrix.triplets[i].col, matrix.triplets[i].val);
    }
}

int main() {
    sparse matrix;
    createTriplet(&matrix);
    //printf("Sparse Matrix :\n");
    //displaySparse(matrix);
    printf("Triplet :\n");
    displayTriplet(matrix);
}