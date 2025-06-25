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
    int flag = 0;
    for (int i = 0; i < n / 2 ; i++) {
        if (arr[i] == arr[n - 1 - i]) {
            printf("Cap nguyen to: (%d, %d)\n", arr[i], arr[n - 1 - i]);
            flag = 1;
        }
    }
    flag == 0 ? printf("Khong co phan tu doi xung\n"): 0;
    free(arr);
    return 0;
}

