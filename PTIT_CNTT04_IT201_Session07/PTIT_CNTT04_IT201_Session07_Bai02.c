#include<stdio.h>
int selectionSort(int arr[], int n);
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
    selectionSort(arr, n);
    printf("\nMang sau khi sap xep la: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
int selectionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    return 0;
}