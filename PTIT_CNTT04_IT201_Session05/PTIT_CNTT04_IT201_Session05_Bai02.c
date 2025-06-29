#include<stdio.h>
int count(int n, int sum);
int main() {
    int n;
    printf("Nhap so luong phan tu can dem: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("So luong phai lon hon 0\n");
        return 1;
    }
    int sumNumber = count(n, 0);
    printf("Tong cua cac so la: %d", sumNumber);
    return 0;
}
int count(int n, int sum) {
    if (n == 0) {
        return sum;
    }
    sum += n;
    return count(n - 1, sum);
}

