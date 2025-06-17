#include <stdio.h>

int main() {
    //Cách 1:Độ phức tạp thuật toán là O(n^2) do có 2 vòng lặp lồng nhau kiểm tra xem có thành phần lặp lại rong mảng không rồi in ra
    int arr[] = {1, 2, 3, 2, 5, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("YES");
                return;
            }
        }
    }
    //Cách 2: Độ phức tạp của thuật toán là O(n^2) + O(n) do có 2 vòng lặp lồng nhau sắp xếp mảng và thêm 1 vòng lặp in ra thông tin
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i+1]) {
            printf("YES");
            return;
        }
    }
    return 0;
}