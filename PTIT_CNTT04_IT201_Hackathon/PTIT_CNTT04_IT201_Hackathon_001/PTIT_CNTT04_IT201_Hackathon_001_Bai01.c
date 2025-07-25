#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[20];
    int priority;
    char deadline[20];
}Task;
typedef struct SingleNode {
    Task* task;
    struct SingleNode *next;
} SingleNode;

typedef struct DoubleNode {
    Task* task;
    struct DoubleNode *prev;
    struct DoubleNode *next;
} DoubleNode;

int autoId = 1;
SingleNode* createSingleNode(Task* task) {
    SingleNode* newNode = (SingleNode*)malloc(sizeof(SingleNode));
    newNode -> task = task;
    newNode -> next = NULL;
    return newNode;
}
DoubleNode* createDoubleNode(Task* task) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode -> task = task;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

SingleNode* insertSingleNodeAtEnd(SingleNode* head, Task* task) {
    SingleNode* newNode = createSingleNode(task);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SingleNode* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
    return head;
}
DoubleNode* insertDoubleNodeAtEnd(DoubleNode* head, Task* task) {
    DoubleNode* newNode = createDoubleNode(task);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    DoubleNode* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
    newNode -> prev = current;
    return head;
}

void printSingleNode(SingleNode* head) {
    SingleNode* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current -> task -> id);
        printf("Title: %s\n", current -> task -> title);
        printf("Priority: %d\n", current -> task -> priority);
        printf("Deadline: %s\n", current -> task -> deadline);
        printf("=========================\n");
        current = current -> next;
    }
}

void printDoubleNode(DoubleNode* head) {
    DoubleNode* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current -> task -> id);
        printf("Title: %s\n", current -> task -> title);
        printf("Priority: %d\n", current -> task -> priority);
        printf("Deadline: %s\n", current -> task -> deadline);
        printf("=========================\n");
        current = current -> next;
    }
}

//Hàm xóa nhiệm vụ
SingleNode* deleteSingleNodeById(SingleNode* head, int id) {
    if (head == NULL) {
        printf("Khong co nhiem vu\n");
        return head;
    }
    SingleNode* current = head;
    SingleNode* prev = NULL;
    while (current != NULL && current -> task -> id != id) {
        prev = current;
        current = current -> next;
    }
    if (current == NULL) {
        printf("Khong tim thay id\n");
        return head;
    }
    if (current == head) {
        head = head -> next;
        free(current);
        return head;
    }
    prev -> next = current -> next;
    free(current);
    return head;
}

//Hàm cập nhập nhiệm vụ
void updateSingleNodeById(SingleNode* head, int id) {
    SingleNode* current = head;
    while (current != NULL && current -> task -> id != id) {
        current = current -> next;
    }
    if (current == NULL) {
        printf("Khong tim thay id\n");
        return;
    }
    printf("=========================\n");
    printf("ID: %d\n", current -> task -> id);
    printf("Title: %s\n", current -> task -> title);
    printf("Priority: %d\n", current -> task -> priority);
    printf("Deadline: %s\n", current -> task -> deadline);
    printf("=========================\n");
    fflush(stdin);
    printf("New Title: ");
    scanf("%s", current -> task -> title);
    printf("New Priority: ");
    scanf("%d", &current -> task -> priority);
    printf("New Dealine: ");
    scanf("%s", current -> task -> deadline);
}

//Hàm tìm id đã xóa
SingleNode* findSingleNodeById(SingleNode* head, int id) {
    while (head != NULL) {
        if (head->task->id == id)
            return head;
        head = head->next;
    }
    return NULL;
}
//Sắp xếp nhiệm vụ theo độ ưu tiên tăng dần
SingleNode* sortByPriority(SingleNode *head) {
    if (head == NULL || head->next == NULL) return head;
    for (SingleNode *i = head; i != NULL; i = i->next) {
        for (SingleNode *j = head; j->next != NULL; j = j->next) {
            if (j->task->priority > j->next->task->priority) {
                Task* temp = j->task;
                j->task = j->next->task;
                j->next->task = temp;
            }
        }
    }
}
//Hàm tìm kiếm nhiệm vụ theo tên
SingleNode* findSingleNodeByName(SingleNode *head, char findStr[]) {
    while (head && strcasecmp(head->task->title, findStr) != 0) {
        head = head->next;
    }
    return head;
}
int main() {
    int choice;
    SingleNode *SingleHead = NULL;
    DoubleNode *DoubleHead = NULL;
    do {
        printf("==========MENU==========\n");
        printf("1. Them nhiem vu\n");
        printf("2. Hien thi danh sach nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhap thong tin nhiem vu\n");
        printf("5. Danh dau nhiem vu da hoan thanh\n");
        printf("6. Sap xep nhiem vu \n");
        printf("7. Tim kiem nhiem vu\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                Task* newTask = (Task*)malloc(sizeof(Task));
                newTask->id = autoId++;
                printf("Nhap ten nhiem vu: ");
                scanf("%s", newTask->title);
                printf("Nhap do uu tien nhiem vu: ");
                scanf("%d", &newTask->priority);
                printf("Nhap ngay can hoan thanh: ");
                scanf("%s", newTask->deadline);
                SingleHead = insertSingleNodeAtEnd(SingleHead, newTask);
                break;
            case 2:
                printSingleNode(SingleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap id nhiem vu can xoa: ");
                scanf("%d", &deleteId);
                SingleHead = deleteSingleNodeById(SingleHead, deleteId);
                break;
            case 4:
                int updateId;
                printf("Nhap id nhiem vu can cap nhap: ");
                scanf("%d", &updateId);
                updateSingleNodeById(SingleHead, updateId);
                break;
            case 5:
                int finishId;
                printf("Nhap id nhiem vu da hoan thanh: ");
                scanf("%d", &finishId);
                SingleNode *finishNode = findSingleNodeById(SingleHead, finishId);
                if (finishNode == NULL) {
                    printf("Khong tim thay khoa hoc co id %d\n", finishId);
                    break;
                }
                Task* finishTask = finishNode->task;
                DoubleHead = insertDoubleNodeAtEnd(DoubleHead, finishTask);
                SingleHead = deleteSingleNodeById(SingleHead, finishId);
                printf("Danh sach du an da hoan thanh la: \n");
                printDoubleNode(DoubleHead);
                break;
            case 6:
                sortByPriority(SingleHead);
                break;
            case 7:
                char findStr[20];
                printf("Nhap ten nhiem vu can tim: ");
                fgets(findStr, sizeof(findStr), stdin);
                findStr[strcspn(findStr, "\n")] = 0;
                SingleNode *found = findSingleNodeByName(SingleHead, findStr);
                if (!found) {
                    printf("Khong tim thay ten\n");
                }else {
                    printf("ID: %d\n", found->task->id);
                    printf("Title: %s\n", found->task->title);
                    printf("Priority: %d\n", found->task->priority);
                    printf("Deadline: %s\n", found->task->deadline);
                    printf("=========================\n");
                }
                break;
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