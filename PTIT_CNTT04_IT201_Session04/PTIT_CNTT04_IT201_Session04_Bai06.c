#include<stdio.h>

struct Student {
    int id;
    char name[100];
    int age;
};

int main() {
    int n;
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("So luong sinh vien khong duoc am");
        return 1;
    }
    if (n == 0) {
        printf("So luong sinh vien phai lon hơn 0");
        return 1;
    }
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Thong tin sinh vien thu %d \n", i + 1);
        students[i].id = i + 1;
        printf("Ten sinh vien: ");
        getchar();
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Tuoi sinh vien:");
        scanf("%d", &students[i].age);
    }
    int search;
    printf("Nhap ID sinh vien can tim kiem: ");
    scanf("%d", &search);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].id == search) {
            printf("{ id: %d, name: %s, age: %d }\n", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sinh vien khong ton tai\n");
    }
    return 0;
}

