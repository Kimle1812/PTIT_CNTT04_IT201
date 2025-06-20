#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Phan tu khong the vuot qua 100 va it hon 1");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int number,index;
    printf("Nhap vi tri muon them: ");
    scanf("%d", &index);
    if (index < 0 || index >= n) {
        printf("Vi tri khong hop le");
        return 1;
    }
    printf("Nhap gia tri muon them: ");
    scanf("%d", &number);
    arr = (int*)realloc(arr, (n + 1) * sizeof(int));
    for (int i = n ;i > index ; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = number;
    printf("Mang da sua la: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}