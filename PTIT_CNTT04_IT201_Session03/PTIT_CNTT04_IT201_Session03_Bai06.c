#include<stdio.h>
#include <stdlib.h>
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
    int m;
    printf("Nhap so luong phan tu muon them vao: ");
    scanf("%d", &m);
    if (m < 0) {
        printf("So luong phan tu khong duoc am");
        return 1;
    }
    if (m == 0) {
        printf("Mang sau khi them la: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        return 1;
    }
    int length = n + m;
    arr = (int*)realloc(arr, length * sizeof(int));
    for (int i = n; i < length; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang sau khi them la: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
