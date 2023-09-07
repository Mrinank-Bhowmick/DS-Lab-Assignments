#include <stdio.h>
#include <stdlib.h>

void findSecondMinMax(int *arr, int size) {
    int max = arr[0];
    int secondMax = arr[0];
    int min = arr[0];
    int secondMin = arr[0];
    int maxPos = 0;
    int secondMaxPos = 0;
    int minPos = 0;
    int secondMinPos = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            secondMax = max;
            secondMaxPos = maxPos;
            max = arr[i];
            maxPos = i;
        } else if (arr[i] > secondMax && arr[i] != max) {
            secondMax = arr[i];
            secondMaxPos = i;
        }

        if (arr[i] < min) {
            secondMin = min;
            secondMinPos = minPos;
            min = arr[i];
            minPos = i;
        } else if (arr[i] < secondMin && arr[i] != min) {
            secondMin = arr[i];
            secondMinPos = i;
        }
    }

    printf("Second Maximum: %d\nPosition: %d\n", secondMax, secondMaxPos);
    printf("Second Minimum: %d\nPosition: %d\n", secondMin, secondMinPos);
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

    findSecondMinMax(arr, size);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
