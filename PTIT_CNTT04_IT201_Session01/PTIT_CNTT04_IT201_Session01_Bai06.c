#include <stdio.h>

int main() {
    int arr[] = {1,4,9,6,4,7,2,4,9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    int n;
    printf("Nhap so ban muon dem: ");
    scanf("%d", &n);
    for (int i = 0; i < length; i++) {
        if (arr[i] == n) {
            count++;
        }
    }
    printf("So %d xuat hien %d lan",n , count);
    //Độ phức tạp của thuật toán là O(n) do chỉ có 1 vòng lặp lồng nhau
    //để đếm số lần xuất hiện của 1 phần tử do người dùng nhập vào
    return 0;
}