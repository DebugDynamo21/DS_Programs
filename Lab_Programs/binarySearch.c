#include <stdio.h>

void binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int pos = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target) {
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            pos = mid;
            break;
        }
    }

    if (pos == -1) {
        printf("%d is not found in the array!\n", target);
    } else {
        printf("%d is found at index %d\n", target, pos);
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements in array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter value to search for: ");
    scanf("%d", &target);

    binarySearch(arr, n, target);

    return 0;
}
