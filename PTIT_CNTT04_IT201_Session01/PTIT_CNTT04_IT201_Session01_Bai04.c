#include <stdio.h>

int main() {
    int n;
    int sum1 = 0 , sum2 =0;
    scanf("%d", &n);
    //Cách 1:Độ phức tạp là O(n) vì phải duyệt qua từng phần tử rồi mới cộng
    for (int i = 0; i <= n; i++) {
        sum1 += i;
    }
    printf("Sum1 = %d\n", sum1);
    //Cách 2: Độ phức tạp là O(1) vì hàm tính tổng đã cho ra kết quả chỉ cần hiển thị ra kết quả đó mà thôi
    sum2 = (n*(n+1))/2;
    printf("Sum2 = %d\n", sum2);
    return 0;
}