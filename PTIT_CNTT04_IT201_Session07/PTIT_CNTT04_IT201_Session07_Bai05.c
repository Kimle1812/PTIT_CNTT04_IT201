#include<stdio.h>
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
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
    quickSort(arr, 0, n -1);
    printf("\nMang sau khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
int partition(int arr[], int start, int end) {
    int pivotValue=arr[end];
    int i=start;
    for (int j=start; j<end; j++) {
        if (arr[j]<pivotValue) {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i]=arr[end];
    arr[end]=temp;
    return i;
}
void quickSort(int arr[], int start, int end) {
    if (start>=end) {
        return;
    }
    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}