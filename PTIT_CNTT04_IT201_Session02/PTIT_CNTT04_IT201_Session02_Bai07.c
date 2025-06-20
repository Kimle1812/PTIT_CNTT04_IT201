#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Phan tu khong the nho hon 1");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int sum;
    printf("Nhap tong hai so: ");
    scanf("%d", &sum);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                printf("Tong cua %d va %d la %d\n", arr[i], arr[j], sum);
            }
        }
    }
    free(arr);
    return 0;
}