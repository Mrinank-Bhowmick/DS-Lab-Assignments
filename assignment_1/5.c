#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *arr, int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int size;

    printf("Enter size of an Array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    
    printf("Enter elements for Array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, size);

    printf("Element of the reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
