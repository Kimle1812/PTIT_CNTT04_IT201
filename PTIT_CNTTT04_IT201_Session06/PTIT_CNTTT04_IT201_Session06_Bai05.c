#include<stdio.h>
int maxNum(int n, int arr[]);
int minNum(int n, int arr[]);
int main() {
    int n;
    printf("Nhap so luong cac phan tu: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("So luong phai lon hon 0\n");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int max = maxNum(n - 1, arr);
    printf("So lon nhat mang la: %d\n", max);
    int min = minNum(n - 1, arr);
    printf("So nho nhat mang la: %d\n", min);
    free(arr);
    return 0;
}
int maxNum(int n, int arr[]) {
    if (n == 0) return arr[0];
    int maxPrev = maxNum(n - 1, arr);
    return (arr[n] > maxPrev) ? arr[n] : maxPrev;
}
int minNum(int n, int arr[]) {
    if (n == 0) {
        return arr[0];
    }
    int minPrev = minNum( n - 1, arr);
    if (arr[n] < minPrev) {
        return arr[n];
    } else {
        return minPrev;
    }
}

