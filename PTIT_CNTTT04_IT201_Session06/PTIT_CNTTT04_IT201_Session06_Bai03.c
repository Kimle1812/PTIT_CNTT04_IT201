#include<stdio.h>
int sumNum(int n);
int main() {
    int number;
    printf("Nhap so nguyen bat ky: ");
    scanf("%d", &number);
    if (number < 1) {
        printf("So nhap vao phai lon hon 0\n");
        return 1;
    }
    if (number - 0 != number) {
        printf("So nhap vao phai la so nguyen!");
        return 1;
    }
    int result = sumNum(number);
    printf("Tong cua cac so la: %d",result);
    return 0;
}
int sumNum(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumNum(n / 10);
}
