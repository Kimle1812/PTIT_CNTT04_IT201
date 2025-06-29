#include<stdio.h>
int transferTower(int n, char start, char between, char end);
int main() {
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    transferTower(n, 'A', 'B', 'C');
    return 0;
}
int transferTower(int n, char start, char between, char end) {
    if (n == 1) {
        printf("Di chuyen dia 1 tu cot %c sang cot %c\n", start, end);
        return;
    }

    transferTower(n - 1, start, end, between);
    printf("Di chuyen dia %d tu cot %c sang cot %c\n", n, start, end);
    transferTower(n - 1, between, start, end);
}