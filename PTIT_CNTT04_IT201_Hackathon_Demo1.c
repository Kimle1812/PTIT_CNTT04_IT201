#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    int id;
    char title[20];
    int credit;
} Course;

typedef struct SingleNode {
    Course course;
    struct SingleNode* next;
} SingleNode;

typedef struct DoubleNode {
    Course course;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

//Hàm khởi tạo  node trong danh sách liên kết đơn
SingleNode* createSingleNode(Course course) {
    SingleNode* newNode = (SingleNode*)malloc(sizeof(SingleNode));
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}

//Hàm thêm node(khóa học) vào cuối danh sách liên kết đơn
SingleNode *insertSingleNodeAtEnd(SingleNode *head, Course course) {
    //B1:Khoi tao node can them
    SingleNode *newNode = createSingleNode(course);
    //B2:Xu li danh sach trong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SingleNode *current = head;
    //B3:duyet den cuoi danh sach
    while (current->next != NULL) {
        current = current->next;
    }
    //B4:Cap nhap con tro cua node cuoi
    current->next = newNode;
    return head;
}

//Hàm hiển thị danh sách
void printSingleList(SingleNode *head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    SingleNode *current = head;
    while (current != NULL) {
        printf("Id: %d\n", current->course.id);
        printf("Title: %s\n", current->course.title);
        printf("Credit: %d\n", current->course.credit);
        current = current->next;
    }
}

//Hàm xóa khóa học theo id
SingleNode* deleteSingleNodeById(SingleNode *head, int id) {
    //B1:Kiểm tra danh sách
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    //B2:Duyệt đến node có id hoặc duyệt hết danh sách
    SingleNode *current = head;
    SingleNode *prev = NULL;
    while (current != NULL && current->course.id != id) {
        prev = current;
        current = current->next;
    }
    //B3:Nếu duyệt hết danh sách thì thông báo và kết thúc
    if (current == NULL) {
        printf("Can not find id\n");
        return head;
    }
    //B4:Nếu tìm thấy node có id thì cập nhập con trỏ next của node trước đó
    //Xử lý trường hợp nếu current là node đầu tiên
    if (current == head) {
        head = head->next;
        free(current);
        return head;
    }
    prev -> next = current->next;
    //B5:Giải phóng node cần xóa
    free(current);
    return head;
}

//Hàm cập nhập thông tin khóa học
void updateCourseById(SingleNode *head, int id) {
    //B1:Xử lý trường hợp danh sách trống
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    //B2:Duyệt đến node có id hoặc duyệt hết danh sách
    SingleNode *current = head;
    while (current != NULL && current->course.id != id) {
        current = current->next;
    }
    //B3:Nếu duyệt hết danh sách thì thông báo và kết thúc
    if (current == NULL) {
        printf("Khong tim thay course co id la %d\n", id);
        return;
    }
    //B4:Nếu tìm thấy node có id thì cập nhập các thuộc tính của course trong node
    printf("Id: %d\n", current->course.id);
    printf(" Old Title: %s\n", current->course.title);
    printf("Old Credit: %d\n", current->course.credit);
    fflush(stdin);
    printf("New Title: ");
    scanf("%s", current->course.title);
    printf("New Credit: ");
    scanf("%d", &current->course.credit);

}

//Hàm khởi tạo node mới danh sách liên kết đôi
DoubleNode* createDoubleNode(Course course) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->course = course;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//Hàm tìm khóa học trong danh sách đơn
SingleNode* findSingleNodeById(SingleNode* head, int id) {
    while (head != NULL) {
        if (head->course.id == id)
            return head;
        head = head->next;
    }
    return NULL;
}

//Hàm đánh dấu khóa học đã hoàn thành (xóa khóa học ở liên kết đơn và thêm khóa học vào cuối danh sách liên kết đôi)
DoubleNode *insertDoubleNodeAtEnd(DoubleNode *head, Course course) {
    //B1: Khởi tạo node mới
    DoubleNode *newNode = createDoubleNode(course);
    //B2:Xử lý trường hợp danh sách trống
    DoubleNode *current = head;
    if (current == NULL) {
        head = newNode;
        return head;
    }
    // B3: Duyệt đến node cuối cùng
    while (current->next != NULL) {
        current = current->next;
    }

    // B4: Gắn node mới vào cuối danh sách
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Hàm tìm kiếm khóa học theo tên
void searchCourseByTitle(SingleNode *head, char * findStr) {
    //B1:Xư lý trường hợp trống
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    //B2:Duyệt toàn bộ danh sách
    SingleNode *current = head;
    while (current != NULL) {
        //B3:Nếu có course nào có title chứa findStr thì in thông tin course đó
        if (strstr(current->course.title, findStr) == 0) {
            printf("Id: %d\n", current->course.id);
            printf("Title: %s\n", current->course.title);
            printf("Credit: %d\n", current->course.credit);

        }
        current = current->next;
    }
}
int main() {
    int choice;
    //Khoi tao 2 danh sach lien ket
    SingleNode *SingleHead = NULL;
    DoubleNode *DoubleHead = NULL;
    do {
        printf("==========MENU==========\n");
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhap thong tin khoa hoc\n");
        printf("5. Danh dau khoa hoc da hoan thanh\n");
        printf("6. Sap xep khao hoc theo so tin chi\n");
        printf("7. Tim kiem khoa hoc theo ten\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1://Them khoa hoc
                //B1:Khoi tao khoa hoc moi
                Course newCourse;
                printf("Nhap id khoa hoc: ");
                scanf("%d", &newCourse.id);
                fflush(stdin);
                printf("Nhap ten khoa hoc: ");
                scanf("%s", newCourse.title);
                printf("Nhap so tin chi: ");
                scanf("%d", &newCourse.credit);
                //B2:Goi ham them moi vao danh sach lien ket don
                SingleHead = insertSingleNodeAtEnd(SingleHead, newCourse);
                break;
            case 2://Hien thi danh sach khoa hoc
                printSingleList(SingleHead);
                break;
            case 3://Xoa khoa hoc
                int deleteId;
                printf("Nhap id khoa hoc cua ban muon xoa: ");
                scanf("%d", &deleteId);
                SingleHead = deleteSingleNodeById(SingleHead, deleteId);
                printf("Xoa thanh cong\n");
                break;
            case 4://Cap nhap thong tin khoa hoc
                int updateId;
                printf("Nhap id khoa hoc cua ban muon cap nhat: ");
                scanf("%d", &updateId);
                updateCourseById(SingleHead, updateId);
                printf("Cap nhat thanh cong\n");
                break;
            case 5://Danh dau khoa hoc da hoan thanh
                int finishId;
                printf("Nhap id khoa hoc cua ban muon danh dau: ");
                scanf("%d", &finishId);

                SingleNode *finishNode = findSingleNodeById(SingleHead, finishId);
                if (finishNode == NULL) {
                    printf("Khong tim thay khoa hoc co id %d\n", finishId);
                    break;
                }

                // Copy dữ liệu khóa học
                Course finishCourse = finishNode->course;

                // Thêm vào danh sách hoàn thành
                DoubleHead = insertDoubleNodeAtEnd(DoubleHead, finishCourse);

                // Xóa khỏi danh sách chưa hoàn thành
                SingleHead = deleteSingleNodeById(SingleHead, finishId);

                printf("Da danh dau khoa hoc da hoan thanh\n");
                break;
            case 6://Sap xep khao hoc theo so tin chi
                break;
            case 7://Tim kiem khoa hoc theo ten
                char findStr[20];
                printf("Nhap ten khoa hoc cua ban muon tim: ");
                gets(findStr);
                searchCourseByTitle(SingleHead, findStr);
                break;
            case 8:
                printf("Cam on ban da su dung chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai!\n");
                break;
        }
    }while (choice != 8);
    return 0;
}