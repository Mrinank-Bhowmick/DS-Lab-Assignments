#include <stdio.h>
#include <stdlib.h>

void findIntersection(int *arr1, int size1, int *arr2, int size2) {
    printf("Intersection of the arrays: ");

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }

    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter size of two Array: ");
    scanf("%d %d", &size1, &size2);

    int *arr1 = (int *)malloc(size1 * sizeof(int));
    int *arr2 = (int *)malloc(size2 * sizeof(int));

    printf("Enter elements for first Array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements for second Array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    findIntersection(arr1, size1, arr2, size2);

    free(arr1);
    free(arr2);

    return 0;
}
