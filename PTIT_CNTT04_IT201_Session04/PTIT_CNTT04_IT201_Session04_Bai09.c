#include<stdio.h>
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int left, int right, int number);
int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("So luong phan tu khong duoc am");
        return 1;
    }
    if (n == 0) {
        printf("So luong phan tu phai lon hơn 0");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr,n);
    int number;
    printf("Nhap so can tim: ");
    scanf("%d", &number);
    if (binarySearch(arr, 0, n - 1, number) != - 1) {
        printf("Phan tu co trong mang\n");
    }else {
        printf("Phan tu khong co trong mang\n");
    }
    free(arr);
    return 0;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0 ; i < n;i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int left, int right, int number) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == number) {
            return mid;
        } else if (arr[mid] > number) {
            return binarySearch(arr, left, mid - 1, number);
        } else {
            return binarySearch(arr, mid + 1, right, number);
        }
    }
    return -1;
}
