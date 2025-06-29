#include<stdio.h>
int fibonacci(int n);
void printFibonacci(int n, int arr[]);
int main() {
    int n;
    printf("Nhap so luong can in day fiboniac: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("So luong phai lon hon 0\n");
        return 1;
    }
    int result[1000];
    for (int i = 0; i < n;i++) {
        result[i] = fibonacci(i);
    }
    printFibonacci(n, result);
    return 0;
}
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void printFibonacci(int n, int arr[]) {
    if (n == 0) {
        return;
    }
    printf("%d ", arr[n - 1]);
    printFibonacci(n - 1, arr);
}
