#include<stdio.h>
#include <stdlib.h>
int sort(int arr[], int n);
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
int sort(int arr[], int n){
    int negative[100];
    int zero[100];
    int positive[100];
    int neg_index = 0, zero_index = 0, pos_index = 0;
    for(int i = n - 1 ; i >= 0; i--){
        if (arr[i] < 0) {
            negative[neg_index] = arr[i];
            neg_index++;
        }else if (arr[i] == 0) {
            zero[zero_index] = arr[i];
            zero_index++;
        }else {
            positive[pos_index] = arr[i];
            pos_index++;
        }
    }
    int idx = 0;
    for (int i = 0; i < neg_index; i++) {
        arr[idx] = negative[i];
        idx++;
    }
    for (int i = 0; i < zero_index; i++) {
        arr[idx] = zero[i];
        idx++;
    }
    for (int i = 0; i < pos_index; i++) {
        arr[idx] = positive[i];
        idx++;
    }
    return 0;
}