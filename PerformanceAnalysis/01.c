#include <stdio.h>

// 1: ค้นหาค่ามากที่สุดในอาร์เรย์
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 2: การจัดเรียงอาร์เรย์แบบ Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 3: ค้นหาเลขที่ซ้ำในอาร์เรย์
void findDuplicates(int arr[], int n) {
    printf("Duplicate elements: ");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    printf("\n");
}

// 4: การคำนวณ Fibonacci Sequence
// Recursive approach
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative approach
void fibonacciIterative(int n) {
    int a = 0, b = 1;
    printf("Fibonacci Sequence: %d %d ", a, b);
    for (int i = 2; i < n; i++) {
        int next = a + b;
        printf("%d ", next);
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    return 0;
}
