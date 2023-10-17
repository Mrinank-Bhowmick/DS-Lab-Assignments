#include <stdio.h>

void addSparseMatrices(int rows, int cols, int tripletA[][3], int tripletB[][3], int result[][3]) {
    int i = 1, j = 1, k = 1;

    while (i <= tripletA[0][2] && j <= tripletB[0][2]) {
        int row1 = tripletA[i][0];
        int col1 = tripletA[i][1];
        int val1 = tripletA[i][2];

        int row2 = tripletB[j][0];
        int col2 = tripletB[j][1];
        int val2 = tripletB[j][2];

        if (row1 < row2 || (row1 == row2 && col1 < col2)) {
            result[k][0] = row1;
            result[k][1] = col1;
            result[k][2] = val1;
            i++;
        }
        else if (row1 == row2 && col1 == col2) {
            result[k][0] = row1;
            result[k][1] = col1;
            result[k][2] = val1 + val2;
            i++;
            j++;
        }
        else {
            result[k][0] = row2;
            result[k][1] = col2;
            result[k][2] = val2;
            j++;
        }
        k++;
    }

    while (i <= tripletA[0][2]) {
        result[k][0] = tripletA[i][0];
        result[k][1] = tripletA[i][1];
        result[k][2] = tripletA[i][2];
        i++;
        k++;
    }

    while (j <= tripletB[0][2]) {
        result[k][0] = tripletB[j][0];
        result[k][1] = tripletB[j][1];
        result[k][2] = tripletB[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
}

int main() {
    int i, j, rows, cols, count1 = 0, count2 = 0;
    printf("Enter the number of rows and columns : ");
    scanf("%d %d", &rows, &cols);
    int matrixA[rows][cols], matrixB[rows][cols];
    printf("Enter sparse matrix A : \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
            if (matrixA[i][j] != 0) {
                count1++;
            }
        }
    }

    int tripletA[count1 + 1][3];
    tripletA[0][0] = rows;
    tripletA[0][1] = cols;
    tripletA[0][2] = count1;
    int r = 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrixA[i][j] != 0) {
                tripletA[r][0] = i;
                tripletA[r][1] = j;
                tripletA[r][2] = matrixA[i][j];
                r++;
            }
        }
    }

    printf("Enter sparse matrix B : \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
            if (matrixB[i][j] != 0) {
                count2++;
            }
        }
    }

    int tripletB[count2 + 1][3];
    tripletB[0][0] = rows;
    tripletB[0][1] = cols;
    tripletB[0][2] = count2;
    r = 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrixB[i][j] != 0) {
                tripletB[r][0] = i;
                tripletB[r][1] = j;
                tripletB[r][2] = matrixB[i][j];
                r++;
            }
        }
    }

    // Addition
    int result[count1 + count2][3];
    result[0][0] = rows;
    result[0][1] = cols;

    addSparseMatrices(rows, cols, tripletA, tripletB, result);

    printf("Resultant Triplet : \n");
    for (i = 0; i < result[0][2] + 1; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
