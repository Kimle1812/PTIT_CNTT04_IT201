#include<stdio.h>
int findMax(int arr[], int n);
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
    int max = findMax(arr, n);
    printf("So lon nhat: %d", max);
    free(arr);
    return 0;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}