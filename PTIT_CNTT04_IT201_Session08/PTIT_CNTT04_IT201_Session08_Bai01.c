#include<stdio.h>
#include <stdlib.h>
int linearSearch(int arr[], int n, int k);
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
    //Độ phức tạp thời gian là O(n)
    free(arr);
    return 0;
}
int linearSearch(int arr[], int n, int k){
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            printf("Vi tri cua so can tim la: %d", i);
            return;
        }
    }
    printf("Khong tim thay phan tu trong mang\n");
}