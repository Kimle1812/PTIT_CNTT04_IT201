#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Hello\n");
    }
    return 0;
}
//Độ phức tạp thời gian của đoạn code trên là O(n) vì vòng lặp for chạy n lần