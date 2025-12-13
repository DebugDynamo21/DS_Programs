#include <stdio.h>

void linearSearch(int arr[], int n, int target) {
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            pos = i;
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

    linearSearch(arr, n, target);

    return 0;
}
