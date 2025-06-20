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
    if (n >1000) {
        printf("So luong phan tu phai be hon 1000");
    }
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Cac phan tu co trong mang: \n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d : %d \n",i +1,arr[i]);
    }
    free(arr);
    return 0;
}

