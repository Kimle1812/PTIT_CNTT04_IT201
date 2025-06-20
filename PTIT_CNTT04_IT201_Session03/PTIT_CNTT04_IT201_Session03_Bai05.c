#include<stdio.h>
#include <stdlib.h>
int mainDiagonal(int **arr, int col, int row);
int principalDiagonal(int **arr, int col, int row);
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
    if (col != row) {
        printf("Khong co duong cheo chinh va duong cheo phu");
        return 1;
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
    mainDiagonal(arr, col, row);
    principalDiagonal(arr, col, row);
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
int mainDiagonal(int **arr, int col, int row) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ( i == j) {
                sum += arr[i][j];
            }
        }
    }
    printf("Tong duong cheo chinh = %d \n", sum);
}
int principalDiagonal(int **arr, int col, int row) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ( i + j == row - 1) {
                sum += arr[i][j];
            }
        }
    }
    printf("Tong duong cheo phu = %d\n", sum);
}