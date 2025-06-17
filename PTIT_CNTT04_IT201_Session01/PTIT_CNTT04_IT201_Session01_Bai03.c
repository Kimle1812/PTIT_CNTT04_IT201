#include <stdio.h>

#include <stdio.h>

int *mallocArray(n){
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }
    return arr;
}

int main(){
    int n;
    scanf("%d", &n);
    int *a = mallocArray(n);
    for (int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
    free(a);
    return 0;
}
//Độ phức tạp của đoạn code trên là O(n) vì sử dụng vòng lặp for duyệt qua từng phần tử của mảng