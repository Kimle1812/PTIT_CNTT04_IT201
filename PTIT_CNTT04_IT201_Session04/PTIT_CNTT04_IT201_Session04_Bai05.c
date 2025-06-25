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
    for (int i = 0; i < n;i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr [j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
             }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int number, index;
    printf("Nhap so can tim: ");
    scanf("%d", &number);
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end)/2;
        if (arr[mid] == number) {
            printf("Phan tu co trong mang\n");
            return 1;
        }else if ( number > arr[mid]) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    printf("phan tu khong co trong mang\n");
    free(arr);
    return 0;
}

