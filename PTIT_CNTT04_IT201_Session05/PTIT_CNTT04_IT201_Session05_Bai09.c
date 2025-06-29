#include<stdio.h>
int countPath(int row, int col, int i, int j);
int main() {
    int row, col;
    printf("Nhap so luong hang: ");
    scanf("%d", &col);
    printf("Nhap so luong cot: ");
    scanf("%d", &row);
    printf("Tong so cac duong di duoc chon la: %d", countPath(row - 1, col - 1, 0, 0));
    return 0;
}
int countPath(int row, int col, int i, int j) {
    if (i > row || j > col) {
        return 0;
    }
    if (i == row && j == col) {
        return 1;
    }
    return (countPath(row, col, i, j + 1) + countPath(row, col, i + 1,j ));
}