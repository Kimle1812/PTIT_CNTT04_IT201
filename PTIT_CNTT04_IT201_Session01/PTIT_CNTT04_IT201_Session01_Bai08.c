#include <stdio.h>

int main() {
    int arr[] = {1,2,3,1,2,6,1,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxCount = 0;
    int maxNumber;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxNumber = arr[i];
        }
    }
    printf("So xuat hien nhieu nhat la %d voi %d lan xuat hien ", maxNumber, maxCount);
    // Độ phức tạp của thuật toán là O(n^2) do có 2 vòng lặp lồng nhau
    return 0;
}