#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Project{
    int id;
    char title[100];                // Tên tên dự án
    char owner[100];            // Tên người quản lý dự án
    int priority;                     // Độ ưu tiên dự án
} Project;


typedef struct SingleNode {
    Project project;
    struct SingleNode* next;
} SingleNode;

typedef struct DoubleNode {
    Project project;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;



SingleNode* createSingleNode(Project project) {
    SingleNode* newNode = (SingleNode*)malloc(sizeof(SingleNode));
    newNode->project = project;
    newNode->next = NULL;
    return newNode;
}

DoubleNode* createDoubleNode(Project project) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->project = project;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

SingleNode* insertSingleNodeAtEnd(SingleNode *head, Project project) {
    SingleNode *newNode = createSingleNode(project);
    if (head == NULL) return newNode;

    SingleNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

DoubleNode* insertDoubleNodeAtEnd(DoubleNode *head, Project project) {
    DoubleNode *newNode = createDoubleNode(project);
    if (head == NULL) return newNode;

    DoubleNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

SingleNode* findSingleNodeById(SingleNode* head, int id) {
    while (head != NULL) {
        if (head->project.id == id)
            return head;
        head = head->next;
    }
    return NULL;
}
void printSingleList(SingleNode *head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    SingleNode *current = head;
    while (current) {
        printf("Id: %d\n", current->project.id);
        printf("Title: %s\n", current->project.title);
        printf("Owner: %s\n", current->project.owner);
        printf("Priority: %d\n", current->project.priority);
        current = current->next;
    }
}
void printDoubleList(DoubleNode *head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    DoubleNode *current = head;
    while (current) {
        printf("Id: %d\n", current->project.id);
        printf("Title: %s\n", current->project.title);
        printf("Owner: %s\n", current->project.owner);
        printf("Priority: %d\n", current->project.priority);
        current = current->next;
    }
}
//Hàm xóa dự án
SingleNode* deleteSingleNodeById(SingleNode *head, int id) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return NULL;
    }

    SingleNode *current = head;
    SingleNode *prev = NULL;

    while (current != NULL && current->project.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay id\n");
        return head;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return head;
}

//Hàm cập nhập thông tin dự án
void updateSingleNodeById(SingleNode *head, int id) {
    SingleNode *current = head;
    while (current && current->project.id != id) {
        current = current->next;
    }
    if (!current) {
        printf("Khong tim thay id\n");
        return;
    }
    printf("Id: %d\n", current->project.id);
    printf("Ten du an cu: %s\n", current->project.title);
    printf("Ten nguoi quan li cu: %s\n", current->project.owner);
    printf("Do uu tien cu: %d\n", current->project.priority);
    printf("=========================\n");
    fflush(stdin);
    printf("Ten du an moi: ");
    scanf("%s", current->project.title);
    printf("Ten nguoi quan li moi: ");
    scanf("%s", current->project.owner);
    printf("Ten do uu tien moi: ");
    scanf("%d", &current->project.priority);
    printf("=========================\n");
    printf("Thong tin du san sau khi cap nhap la:\n");
    printf("Id: %d\n", current->project.id);
    printf("Title: %s\n", current->project.title);
    printf("Owner: %s\n", current->project.owner);
    printf("Priority: %d\n", current->project.priority);
}
//HÀm sắp xếp dự án theo độ ưu tiên
SingleNode* sortByPriority(SingleNode *head) {
    if (head == NULL || head->next == NULL) return head;
    for (SingleNode *i = head; i != NULL; i = i->next) {
        for (SingleNode *j = i->next; j != NULL; j = j->next) {
            if (i->project.priority > j->project.priority) {
                Project temp = i->project;
                i->project = j->project;
                j->project = temp;
            }
        }
    }
    return head;
}

//Hàm tìm kiếm khóa học theo tên
void searchProjectByTitle(SingleNode *head, char findStr[]) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int flag = 0;
    SingleNode *current = head;
    while (current != NULL) {
        if (strstr(current->project.title, findStr) != NULL) {
            flag = 1;
            printf("Id: %d\n", current->project.id);
            printf("Title: %s\n", current->project.title);
            printf("Owner: %s\n", current->project.owner);
            printf("Priority: %d\n", current->project.priority);

        }
        current = current->next;
    }
    flag == 0 ? printf("Khong tim thay khoa hoc co ten %s\n", findStr) : 0;
}
int main() {
    int choice;
    SingleNode *SingleHead = NULL;
    DoubleNode *DoubleHead = NULL;
    do {
        printf("==========MENU==========\n");
        printf("1. Them moi du an\n");
        printf("2. Hien thi danh sach du an\n");
        printf("3. Xoa du an\n");
        printf("4. Cap nhap thong du an\n");
        printf("5. Danh dau du an da hoan thanh\n");
        printf("6. Sap xep du an theo do uu tien\n");
        printf("7. Tim kiem du an theo ten\n");
        printf("8. Thoat chuong trinh\n");
        printf("=========================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Project newProject;
                printf("Nhap id du an: ");
                scanf("%d", &newProject.id);
                fflush(stdin);
                printf("Nhap ten du an: ");
                scanf("%s", newProject.title);
                printf("Nhap ten nguoi quan ly du an: ");
                scanf("%s", newProject.owner);
                printf("Nhap do uu tien: ");
                scanf("%d", &newProject.priority);
                SingleHead = insertSingleNodeAtEnd(SingleHead, newProject);
                break;
            case 2:
                printSingleList(SingleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap id du an muon xoa: ");
                scanf("%d", &deleteId);
                SingleHead = deleteSingleNodeById(SingleHead, deleteId);
                printf("Danh sach du an sau khi xoa: \n");
                printSingleList(SingleHead);
                break;
            case 4:
                int updateId;
                printf("Nhap id muon cap nhap thong tin:");
                scanf("%d", &updateId);
                updateSingleNodeById(SingleHead, updateId);
                break;
            case 5:
                printf("Danh dau du an da hoan thanh\n");
                int finishId;
                printf("Nhap id du an da hoan thanh: ");
                scanf("%d", &finishId);

                SingleNode *finishNode = findSingleNodeById(SingleHead, finishId);
                if (finishNode == NULL) {
                    printf("Khong tim thay khoa hoc co id %d\n", finishId);
                    break;
                }
                Project finishProject = finishNode->project;
                DoubleHead = insertDoubleNodeAtEnd(DoubleHead, finishProject);
                SingleHead = deleteSingleNodeById(SingleHead, finishId);
                printf("Danh sach du an da hoan thanh la: \n");
                printDoubleList(DoubleHead);
                break;
            case 6:
                SingleHead = sortByPriority(SingleHead);
                printf("Danh sach sau khi sap xep la: \n");
                printSingleList(SingleHead);
                break;
            case 7:
                char findStr[20];
                fflush(stdin);
                printf("Nhap ten khoa hoc cua ban muon tim: ");
                scanf("%s", &findStr);
                searchProjectByTitle(SingleHead, findStr);
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
