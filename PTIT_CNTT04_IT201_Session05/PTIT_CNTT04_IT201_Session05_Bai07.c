#include<stdio.h>
int fibonacci(int n);
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
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);

    }
    return 0;
}
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

