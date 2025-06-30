#include<stdio.h>
int bubbleSort(int arr[], int n);
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
    bubbleSort(arr, n);
    printf("\nMang sau khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
int bubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}