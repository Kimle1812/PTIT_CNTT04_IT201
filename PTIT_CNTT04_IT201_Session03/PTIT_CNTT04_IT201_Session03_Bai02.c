#include<stdio.h>
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
    if (n >1000) {
        printf("So luong phan tu phai be hon 1000");
    }
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf(" Max = %d ", max);
    free(arr);
    return 0;
}

