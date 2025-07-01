#include<stdio.h>
#include <stdlib.h>
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int n, int k);
int main(){
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong nhap khong hop le\n");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Arr [%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int search;
    printf("Nhap so can tim: ");
    scanf("%d", &search);
    bubbleSort(arr,n);
    binarySearch(arr, n, search);
    //Độ phức tạp thời gian là: O(n^2)
    free(arr);
    return 0;

}
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1;j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}
int binarySearch(int arr[], int n, int k){
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            printf("Vi tri so can tim la: %d", mid);
            return;
        }else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Khong tim thay phan tu trong mang\n");
}