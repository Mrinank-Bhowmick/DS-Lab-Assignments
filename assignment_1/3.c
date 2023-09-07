#include <stdio.h>
#include <stdlib.h>

void rotateArray(int *arr, int size, int positions) {
    int *temp = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[(i + positions) % size];
    }

    free(temp);
}

int main() {
    int size;

    printf("Enter size of the Array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter elements for array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int positions;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    printf("Array before rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    rotateArray(arr, size, positions);

    printf("Array after rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
