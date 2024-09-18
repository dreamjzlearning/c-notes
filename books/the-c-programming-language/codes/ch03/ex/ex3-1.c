/*
    Write a version with only one test inside the loop.
    And measure the difference in run-time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000000

int binary_search_2tests(int x, int n, const int arr[]);
int binary_search_1test(int x, int n, const int arr[]);

int main() {
    // generate ascending array
    int* arr = (int*)malloc(ARR_SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = i;
    }

    // binary search
    int x = 0;

    time_t start, end;
    double runtime;

    // 2 tests
    start = time(NULL);
    int res = binary_search_2tests(x, ARR_SIZE, arr);
    end = time(NULL);
    runtime = (double)(end - start);

    if (res != -1) {
        printf("binary_search_2tests\nX: %d found in %d \n", x, res);
    }
    else {
        printf("binary_search_2tests\nX: %d not found\n", x);
    }
    printf("Run time: %f\n", runtime);

    // 1 test
    start = time(NULL);
    int res_1 = binary_search_1test(x, ARR_SIZE, arr);
    end = time(NULL);
    runtime = (double)(end - start);

    if (res != -1) {
        printf("binary_search_1test\nX: %d found in %d \n", x, res);
    }
    else {
        printf("binary_search_1test\nX: %d not found\n", x);
    }
    printf("Run time: %f\n", runtime);

    free(arr);

    return 0;
}

int binary_search_2tests(int x, int n, const int arr[]) {
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

int binary_search_1test(int x, int n, const int arr[]) {
    int left = 0;
    int right = n - 1;

    int mid = (left + right) >> 1;
    int mid_val = arr[mid];
    while (left <= right && x != mid_val) {
        if (x < mid_val) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (left + right) >> 1;
        mid_val = arr[mid];
    }

    if (x == mid_val) {
        return mid;
    }
    else {
        return -1;
    }
}