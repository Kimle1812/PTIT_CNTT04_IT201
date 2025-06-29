#include<stdio.h>
int binary(int n);
int main() {
    int n;
    printf("Nhap so nguyen can tinh nhi phan: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("So nhap vao phai là so nguyen duong\n");
        return 1;
    }
    binary(n);
    return 0;
}
int binary(int n) {
    if (n == 0) {
        return;
    }
    binary(n / 2);
    printf("%d ", n % 2);
}

