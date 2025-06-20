#include<stdio.h>
#include <stdlib.h>
int findMax(int **arr, int col, int row);
int findMin(int **arr, int col, int row);
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
    findMax(arr, col, row);
    findMin(arr, col, row);
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
int findMax(int **arr, int col, int row) {
    int max = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("Max = %d\n", max);
    return 0;
}
int findMin(int **arr, int col, int row) {
    int min = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    printf("Min = %d\n", min);
}

