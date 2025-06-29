#include<stdio.h>
int product(int n, int result);
int main() {
    int n;
    printf("Nhap gia tri phan tu can tinh giai thua: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Gia tri phai lon hon 1\n");
        return 1;
    }
    int result = product(n, 1);
    printf("Giai thua cua so ban nhap la: %d", result);
    return 0;
}
int product(int n, int result) {
    if (n == 1) {
        return result;
    }
    result *= n;
    return product(n -1, result);
}