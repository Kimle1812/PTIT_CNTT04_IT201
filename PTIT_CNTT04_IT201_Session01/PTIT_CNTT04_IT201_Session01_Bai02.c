#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printDouble(n);
    return 0;
}
void printDouble(n) {
    int i = 1;
    while (i < n) {
        printf("%d\n", i);
        i *= 2;
    }
}
//Độ phức tạp thời gian của đoạn code trên là O(log n)
//vì sau mỗi lần lặp biến i tăng gấp đôi cho tới khi i >= n
