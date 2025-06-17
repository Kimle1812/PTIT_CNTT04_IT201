#include <stdio.h>

int main() {
    int arr[] = {3,4,7,1,0,5,2,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (arr[i]>arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    //Độ phức tạp của thuật toán là  O(n^2) + O(n) do có hai vòng lặp for lồng nhau lặp n^2 lần để sắp xếp mảng
    //và 1 vòng lặp for lặp n lần hiển thị mảng
    return 0;
}