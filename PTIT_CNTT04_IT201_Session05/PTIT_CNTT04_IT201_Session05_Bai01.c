#include<stdio.h>
int count(int n);
int main() {
    int n;
    printf("Nhap so luong phan tu can dem: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("So luong phai lon hon 1\n");
        return 1;
    }
    count(n);
    return 0;
}
int count(int n) {

    if (n == 1) {
        printf("%d ", n);
        return;
    }
    count(n -1);
    printf("%d ", n);
}

