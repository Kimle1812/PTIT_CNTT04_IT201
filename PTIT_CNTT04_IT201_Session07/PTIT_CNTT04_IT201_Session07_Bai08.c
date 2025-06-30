#include <stdio.h>

void bubbleSort(int row, int col, int arr[][col], int k);

int main() {
    int col, row;

    printf("Nhap so luong hang cua mang: ");
    scanf("%d", &row);
    printf("Nhap so luong cot cua mang: ");
    scanf("%d", &col);

    if (row <= 0 || row > 1000 || col <= 0 || col > 1000) {
        printf("So luong nhap khong hop le\n");
        return 1;
    }

    int arr[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Mang truoc khi sap xep la:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int k;
    printf("Nhap so cot can sap xep: ");
    scanf("%d", &k);

    if (k <= 0 || k > col) {
        printf("So cot nhap khong hop le\n");
        return 1;
    }

    bubbleSort(row, col, arr, k - 1);

    printf("\nMang sau khi sap xep theo cot %d la:\n", k);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void bubbleSort(int row, int col, int arr[][col], int k) {
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            if (arr[j][k] > arr[j + 1][k]) {
                int temp = arr[j][k];
                arr[j][k] = arr[j + 1][k];
                arr[j + 1][k] = temp;
            }
        }
    }
}
