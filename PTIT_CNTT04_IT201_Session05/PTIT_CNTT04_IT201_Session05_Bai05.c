#include<stdio.h>
#include <string.h>

int isPalindrome(char str[], int left, int right);
int main() {
    char str[1000];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int result = isPalindrome(str, 0, strlen(str) - 1);
    if (result == 1) {
        printf("Palindrome valid\n");
    } else if (result == 0){
        printf("Palindrome invalid\n");
    }
    return 0;
}
int isPalindrome(char str[],int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (str[left] != str[right]) {
        return 0;
    }
    return isPalindrome(str,left + 1, right - 1);
}