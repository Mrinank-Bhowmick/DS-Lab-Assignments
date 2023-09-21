#include <stdio.h>

struct SparseMatrix {
    int row;
    int col;
    int value;
};

void inputSparseMatrix(struct SparseMatrix matrix[], int *m, int *n, int *k) {
    scanf("%d %d %d", m, n, k);
    for (int i = 0; i < *k; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

void displaySparseMatrix(struct SparseMatrix matrix[], int k, int m, int n) {
    printf("%d %d %d\n", m, n, k);
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

void addSparseMatrices(struct SparseMatrix matrix1[], int k1, struct SparseMatrix matrix2[], int k2, struct SparseMatrix result[], int *k3) {
    int i = 0, j = 0, k = 0;

    while (i < k1 && j < k2) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k] = matrix1[i];
            i++;
        } else if (matrix1[i].row > matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) {
            result[k] = matrix2[j];
            j++;
        } else {
            result[k].row = matrix1[i].row;
            result[k].col = matrix1[i].col;
            result[k].value = matrix1[i].value + matrix2[j].value;
            i++;
            j++;
        }
        k++;
    }

    while (i < k1) {
        result[k] = matrix1[i];
        i++;
        k++;
    }

    while (j < k2) {
        result[k] = matrix2[j];
        j++;
        k++;
    }

    *k3 = k;
}

int main() {
    struct SparseMatrix matrix1[100], matrix2[100], result[100];
    int m1, n1, k1, m2, n2, k2, k3;

    printf("Enter sparse matrix-1\n");
    inputSparseMatrix(matrix1, &m1, &n1, &k1);

    printf("Enter sparse matrix-2\n");
    inputSparseMatrix(matrix2, &m2, &n2, &k2);

    if (m1 != m2 || n1 != n2) {
        printf("Matrix dimensions do not match. Addition is not possible.\n");
        return 1;
    }

    addSparseMatrices(matrix1, k1, matrix2, k2, result, &k3);

    printf("Resultant Matrix\n");
    displaySparseMatrix(result, k3, m1, n1);
}