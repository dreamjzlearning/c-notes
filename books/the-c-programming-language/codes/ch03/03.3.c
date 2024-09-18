/*
    Binary search
 */

#include <stdio.h>

int binary_search(int x, int n, const int arr[]);

int main() {
    int arr[] = { 1, 4, 5, 6,8,10 };

    // get number of elements in array
    int n = sizeof(arr) / sizeof(arr[0]);
    // binary search
    int x = 5;
    int res = binary_search(x, n, arr);

    if (res != -1) {
        printf("X: %d found in %d \n", x, res);
    }
    else {
        printf("X: %d not found", x);
    }

    return 0;
}

int binary_search(int x, int n, const int arr[]) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) >> 1;
        int mid_val = arr[mid];
        if (x == mid_val) {
            return mid;
        }
        else if (x > mid_val) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}
