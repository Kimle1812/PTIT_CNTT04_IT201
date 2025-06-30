#include<stdio.h>
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
int main() {
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
    printf("Mang truoc khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("\nMang sau khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
void mergeSort(int arr[], int left, int right) {
    if (left == right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void merge(int arr[], int left, int mid, int right) {
    //B1:Khoi tao 2 mang con ben phai va ben trai
    int leftLength = mid - left + 1;
    int rightLength = right - mid;
    int leftArray[leftLength], rightArray[rightLength];
    // Sao chep cac gia tri tu mang ban dau vao 2 mang con
    for (int i = 0; i < leftLength; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < rightLength; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }
    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int arrIndex = left;
    while ((leftArrIndex < leftLength) && (rightArrIndex < rightLength)) {
        if (leftArray[leftArrIndex] <= rightArray[rightArrIndex]) {
            arr[arrIndex] = leftArray[leftArrIndex];
            leftArrIndex++;
        }else {
            arr[arrIndex] = rightArray[rightArrIndex];
            rightArrIndex++;
        }
        arrIndex++;
    }
    while (leftArrIndex < leftLength) {
        arr[arrIndex] = leftArray[leftArrIndex];
        arrIndex++;
        leftArrIndex++;

    }
    while (rightArrIndex < rightLength) {
        arr[arrIndex] = rightArray[rightArrIndex];
        arrIndex++;
        rightArrIndex++;
    }
}