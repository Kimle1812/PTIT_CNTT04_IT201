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
    int maxRight=arr[n-1];
    printf("Cac phan tu lon hon cac phan tu dung sau no la:");
    printf("%d", maxRight);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            printf("%d", arr[i]);
            maxRight = arr[i];
        }
    }

    free(arr);
    return 0;
}