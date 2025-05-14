#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;  // Found at index mid
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in array\n", target);

    return 0;
}
