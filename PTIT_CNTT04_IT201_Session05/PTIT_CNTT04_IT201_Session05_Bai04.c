#include<stdio.h>
int calculation(int a, int b, int result);
int main() {
    int firstNum, secondNum;
    printf("Nhap so nguyen to thu nhat: ");
    scanf("%d", &firstNum);
    printf("Nhap so nguyen to thu hai: ");
    scanf("%d", &secondNum);
    if (firstNum < 0 || secondNum < 0) {
        printf("Gia tri phai lon hon 0\n");
        return 1;
    }
    if (firstNum > secondNum) {
        printf("So thu nhat phai nho hon so thu hai");
        return 1;
    }
    int result = calculation(firstNum,secondNum, 0);
    printf("Tong cac so tu %d den %d la: %d",firstNum, secondNum, result);
    return 0;
}
int calculation(int a, int b, int result) {
    if (a > b) {
        return result;
    }
    result += a;
    return calculation(a + 1,b, result);
}