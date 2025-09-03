//implementing the stack using Linked List and Array

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Array-based stack implementation
typedef struct {
    int arr[MAX_SIZE];
    int top;
} ArrayStack;

void initializeArrayStack(ArrayStack *stack) {
    stack->top = -1;
}

bool isFullArray(ArrayStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmptyArray(ArrayStack *stack) {
    return stack->top == -1;
}

void pushArray(ArrayStack *stack, int value) {
    if (isFullArray(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->top++;
        stack->arr[stack->top] = value;
    }
}

int popArray(ArrayStack *stack) {
    if (isEmptyArray(stack)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

int peekArray(ArrayStack *stack) {
    if (isEmptyArray(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

void printArrayStack(ArrayStack *stack) {
    if (isEmptyArray(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements (from top to bottom): ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// Linked list-based stack implementation
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *topLL = NULL;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmptyLL() {
    return topLL == NULL;
}

void pushLL(int data) {
    Node *newNode = createNode(data);
    if (newNode == NULL) {
        printf("Stack overflow\n");
    } else {
        newNode->next = topLL;
        topLL = newNode;
    }
}

int popLL() {
    if (isEmptyLL()) {
        printf("Stack underflow\n");
        return -1;
    } else {
        Node *temp = topLL;
        int data = temp->data;
        topLL = topLL->next;
        free(temp);
        return data;
    }
}

int peekLL() {
    if (isEmptyLL()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return topLL->data;
    }
}

void printLLStack() {
    if (isEmptyLL()) {
        printf("Stack is empty\n");
    } else {
        Node *current = topLL;
        printf("Stack elements (from top to bottom): ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int op, value;
    bool exitProgram = false;

    printf("Choose stack implementation:\n");
    printf("1: Array-based\n");
    printf("2: Linked list-based\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    ArrayStack arrayStack;
    if (choice == 1) {
        initializeArrayStack(&arrayStack);
    }

    while (!exitProgram) {
        printf("\n1: Push\n");
        printf("2: Pop\n");
        printf("3: Peek\n");
        printf("4: Print stack\n");
        printf("0: Exit\n");
        printf("Enter the operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (choice == 1) {
                    pushArray(&arrayStack, value);
                } else {
                    pushLL(value);
                }
                break;
            case 2:
                if (choice == 1) {
                    value = popArray(&arrayStack);
                    if (value != -1) {
                        printf("Popped value: %d\n", value);
                    }
                } else {
                    value = popLL();
                    if (value != -1) {
                        printf("Popped value: %d\n", value);
                    }
                }
                break;
            case 3:
                if (choice == 1) {
                    value = peekArray(&arrayStack);
                    if (value != -1) {
                        printf("Top value: %d\n", value);
                    }
                } else {
                    value = peekLL();
                    if (value != -1) {
                        printf("Top value: %d\n", value);
                    }
                }
                break;
            case 4:
                if (choice == 1) {
                    printArrayStack(&arrayStack);
                } else {
                    printLLStack();
                }
                break;
            case 0:
                exitProgram = true;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
