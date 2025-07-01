#include<stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n);
int linearSearch(int arr[], int n, int k);
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
    int k;
    printf("Nhap so can tim: ");
    scanf("%d", &k);
    linearSearch(arr, n, k);
    insertionSort(arr, n);
    printf("Mang sau khi sap xep la: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    binarySearch(arr, n, k);
    free(arr);
    return 0;
}
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

        }
        arr[j + 1] = key;
    }
}
int linearSearch(int arr[], int n, int k){
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            printf("Vi tri cua so can tim kiem tuyen tinh la: %d\n", i);
            return;
        }
    }
    printf("Khong tim thay phan tu trong mang\n");
}
int binarySearch(int arr[], int n, int k){
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            printf("Vi tri so can tim kiem nhi phan la: %d", mid);
            return;
        }else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Khong tim thay phan tu trong mang\n");
}
