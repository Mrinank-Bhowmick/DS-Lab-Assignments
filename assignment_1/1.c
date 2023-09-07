#include <stdio.h>
#include <stdlib.h>

void findMinMax(int *arr, int size) {
    int max = arr[0];
    int min = arr[0];
    int maxPos = 0;
    int minPos = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxPos = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            minPos = i;
        }
    }

    printf("Maximum: %d\nPosition: %d\n", max, maxPos);
    printf("Minimum: %d\nPosition: %d\n", min, minPos);
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

    findMinMax(arr, size);

    free(arr);

    return 0;
}
