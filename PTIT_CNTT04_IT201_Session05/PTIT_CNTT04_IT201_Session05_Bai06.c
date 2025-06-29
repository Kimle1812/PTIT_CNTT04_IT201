#include<stdio.h>
int sumNum(int n, int sum, int arr[]);
int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("So luong phai lon hon 0\n");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i< n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int sum = sumNum(n - 1, 0,arr);
    printf("Tong cua cac so trong mang: %d", sum);
    free(arr);
    return 0;
}
int sumNum(int n, int sum, int arr[]) {
    if (n == -1) {
        return sum;
    }
    sum += arr[n];
    return sumNum(n - 1, sum, arr);
}

