#include<stdio.h>
#include<stdlib.h>
typedef struct Operation {
    char action[100];
    char value[100];
} Operation;
typedef struct Stack {
  Operation* operations;
  int top;
  int capacity;
};
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> top = -1;
    stack -> capacity = capacity;
    stack -> operations = (Operation*)malloc(capacity * sizeof(Operation));
    return stack;
}

int main() {
    int choice;
    Stack* undoStack = createStack(100);
    Stack* redoStack = createStack(100);
    do {
        printf("===TEXT EDITOR=====\n");
        printf("1. INSERT x\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. HIỂN THỊ\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("EXIT\n");
                break;
            default:
                printf("Invalid choice! Please choose again\n");

        }
    }while (choice != 5);
    return 0;
}