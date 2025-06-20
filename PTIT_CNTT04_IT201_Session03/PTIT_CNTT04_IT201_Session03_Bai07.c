#include<stdio.h>
#include <stdlib.h>
int sum(int **arr, int k, int row);
int main() {
    int col, row;
    printf("Nhap so luong cot trong mang: ");
    scanf("%d", &col);
    printf("Nhap so luong hang trong mang: ");
    scanf("%d", &row);
    if (col < 0 || row < 0) {
        printf("So luong cot va hang khong duoc am");
        return 1;
    }
    if (col == 0 || row == 0) {
        printf("So luong cot va hang phai lon hơn 0");
        return 1;
    }
    if (col >1000 || row >1000) {
        printf("So luong hang va cot phai be hon 1000");
    }
    int **arr = (int**)calloc(row, sizeof(int));
    for (int i = 0; i < row; i++) {
        arr[i] = (int*)calloc(col, sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int k;
    printf("Nhap so hang muon tinh tong: ");
    scanf("%d", &k);
    if (k < 0 || k >= row) {
        printf("So hang khong hop le");
        return 1;
    }
    sum(arr, k, col);
    free(arr);
    return 0;
}
int sum(int **arr, int k, int col) {
    int sum = 0;
    for (int i = 0; i < col; i++) {
        sum += arr[k - 1][i];
    }
    printf("Tong cac phan tu trong hang = %d \n", sum);
}