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
    int maxCount = 0;
    int maxNumber = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxNumber = arr[i];
        }
    }
    printf("So %d xuat hien %d lan", maxNumber, maxCount);
    free(arr);
    return 0;
}