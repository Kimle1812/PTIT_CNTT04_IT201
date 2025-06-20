#include<stdio.h>
#include<stdlib.h>
int findNumber(int arr[], int n, int number);
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
    int number;
    printf("Nhap so muon tim: ");
    scanf("%d", &number);
    int  count = findNumber(arr, n,number);
    printf("So %d xuat hien %d lan", number , count);
    free(arr);
    return 0;
}
int findNumber(int arr[], int n, int number) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    return count;
}