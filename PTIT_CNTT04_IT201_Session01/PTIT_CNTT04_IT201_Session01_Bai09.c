#include<stdio.h>

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        printf("%d", matrix[i][i]);
    }
    //Độ phức tạp là O(n^2) + O(n) vì có 2 vòng lặp lồng nhau in ra ma trận và 1 vòng lặp in đường chéo chính
    return 0;
}
