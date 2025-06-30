#include<stdio.h>
#include<string.h>
int charSort(char str[]);
int main(){
    char str[1000];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int valid = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            valid = 1;
            break;
        }
    }
    if (!valid) {
        printf("Chuoi khong hop le!\n");
        return 1;
    }
    printf("Chuoi truoc khi sap xep la: %s \n", str);
    charSort(str);
    printf("Chuoi sau khi sap xep la: %s \n", str);
    return 0;
}
int charSort(char str[]){
    int length = strlen(str);
    for(int i = 0; i < length; i++){
        for (int j = i+ 1; j < length; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    return 0;
}