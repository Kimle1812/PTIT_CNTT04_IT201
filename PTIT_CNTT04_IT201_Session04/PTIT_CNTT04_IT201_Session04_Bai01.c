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
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int number;
    int flag = 0;
    printf("Nhap so can tim: ");
    scanf("%d", &number);
    for (int i = 0; i < n ; i++) {
        if (arr[i] == number) {
            printf("Chi so cua so can tim dau tien trong mang la : %d ", i);
            flag = 1;
            return 1;
        }
    }
    flag == 0 ? printf("Khong tim thay so can tim") : 0;
    free(arr);
    return 0;
}

