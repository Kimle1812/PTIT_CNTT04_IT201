#include<stdio.h>
#include <stdlib.h>
void ascendingSort(int arr[], int length);
void descendingSort(int arr[], int length);
void sort(int arr[], int n);
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
    printf("Mang truoc khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    sort(arr, n);
    printf("\nMang sau khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
void sort(int arr[], int n){
    int even[100];
    int odd[100];
    int even_index = 0, odd_index = 0;
    for(int i = n - 1 ; i >= 0; i--){
        if (arr[i] % 2 == 0) {
            even[even_index] = arr[i];
            even_index++;
        }else {
            odd[odd_index] = arr[i];
            odd_index++;
        }
    }
    ascendingSort(even, even_index);
    descendingSort(odd, odd_index);
    int idx = 0;
    for (int i = 0; i < even_index; i++) {
        arr[idx] = even[i];
        idx++;
    }
    for (int i = 0; i < odd_index; i++) {
        arr[idx] = odd[i];
        idx++;
    }
}
void ascendingSort(int arr[], int length) {
    for (int i = 0; i < length -1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void descendingSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}