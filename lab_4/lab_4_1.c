#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this isn't my code

typedef struct {
    char* student_name;
    int student_roll_number;
    float student_cgpi;
} Student;

typedef struct LinkedListNode {
    Student student_data;
    struct LinkedListNode* next_node;
} LinkedListNode;

Student createStudent(const char* name, int roll_number, float cgpi) {
    Student new_student;
    new_student.student_name = (char*)malloc(strlen(name) + 1);
    if (new_student.student_name == NULL) {
        printf("Memory allocation failed for student name!\n");
        exit(1);
    }
    strcpy(new_student.student_name, name);
    new_student.student_roll_number = roll_number;
    new_student.student_cgpi = cgpi;
    return new_student;
}

LinkedListNode* createNode(Student student) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->student_data = student;
    newNode->next_node = NULL;
    return newNode;
}

void displayStudent(Student student) {
    printf("Name: %s, Roll: %d, CGPI: %.2f", student.student_name, student.student_roll_number, student.student_cgpi);
}

void insertAtBeginning(LinkedListNode** head_reference, Student student) {
    LinkedListNode* new_node = createNode(student);
    new_node->next_node = *head_reference;
    *head_reference = new_node;
    printf("Inserted student at the beginning: ");
    printf("\n");
    displayStudent(student);
}

void insertAtEnd(LinkedListNode** head_reference, Student student) {
    LinkedListNode* new_node = createNode(student);
    
    if (*head_reference == NULL) {
        *head_reference = new_node;
        printf("Inserted student at the end (list was empty): ");
        displayStudent(student);
        printf("\n");
        return;
    }
    
    LinkedListNode* current_node = *head_reference;
    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }
    current_node->next_node = new_node;
    printf("Inserted student at the end: ");
    displayStudent(student);
    printf("\n");
}

void insertAtPosition(LinkedListNode** head_reference, Student student, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    if (position == 0) {
        insertAtBeginning(head_reference, student);
        return;
    }
    
    LinkedListNode* new_node = createNode(student);
    LinkedListNode* current_node = *head_reference;
    
    for (int i = 0; current_node != NULL && i < position - 1; i++) {
        current_node = current_node->next_node;
    }
    
    if (current_node == NULL) {
        printf("Position out of bounds!\n");
        free(new_node);
        return;
    }
    
    new_node->next_node = current_node->next_node;
    current_node->next_node = new_node;
    printf("Inserted student at position %d: ", position);
    displayStudent(student);
    printf("\n");
}

void deleteFromBeginning(LinkedListNode** head_reference) {
    if (*head_reference == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    LinkedListNode* node_to_delete = *head_reference;
    *head_reference = (*head_reference)->next_node;
    printf("Deleted student from the beginning: ");
    displayStudent(node_to_delete->student_data);
    printf("\n");
    free(node_to_delete->student_data.student_name);
    free(node_to_delete);
}

void deleteFromEnd(LinkedListNode** head_reference) {
    if (*head_reference == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
    
    if ((*head_reference)->next_node == NULL) {
        printf("Deleted student from the end: ");
        displayStudent((*head_reference)->student_data);
        printf("\n");
        free((*head_reference)->student_data.student_name);
        free(*head_reference);
        *head_reference = NULL;
        return;
    }
    
    LinkedListNode* current_node = *head_reference;
    LinkedListNode* previous_node = NULL;
    
    while (current_node->next_node != NULL) {
        previous_node = current_node;
        current_node = current_node->next_node;
    }
    
    previous_node->next_node = NULL;
    printf("Deleted student from the end: ");
    displayStudent(current_node->student_data);
    printf("\n");
    free(current_node->student_data.student_name);
    free(current_node);
}

void displayList(LinkedListNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Student List:\n");
    LinkedListNode* current_node = head;
    int count = 1;
    while (current_node != NULL) {
        printf("%d. ", count++);
        displayStudent(current_node->student_data);
        printf("\n");
        current_node = current_node->next_node;
    }
}

void freeList(LinkedListNode** head_reference) {
    LinkedListNode* current_node = *head_reference;
    LinkedListNode* next_node;
    
    while (current_node != NULL) {
        next_node = current_node->next_node;
        free(current_node->student_data.student_name);
        free(current_node);
        current_node = next_node;
    }
    
    *head_reference = NULL;
    printf("List freed successfully\n");
}

Student inputStudentDetails() {
    char name_buffer[100];
    int roll_number;
    float cgpi;
    
    printf("Enter student name: ");
    scanf(" %99[^\n]", name_buffer);
    printf("Enter roll number: ");
    scanf("%d", &roll_number);
    printf("Enter CGPI: ");
    scanf("%f", &cgpi);
    
    return createStudent(name_buffer, roll_number, cgpi);
}

int main() {
    LinkedListNode* student_list_head = NULL;
    int user_choice, position_to_insert, roll_number_to_delete;
    
    printf("1. Insert student at beginning\n");
    printf("2. Insert student at end\n");
    printf("3. Insert student at position\n");
    printf("4. Delete student from beginning\n");
    printf("5. Delete student from end\n");
    printf("6. Display student list\n");
    printf("7. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);
        
        switch (user_choice) {
            case 1: {
                Student new_student = inputStudentDetails();
                insertAtBeginning(&student_list_head, new_student);
                break;
            }
                
            case 2: {
                Student new_student = inputStudentDetails();
                insertAtEnd(&student_list_head, new_student);
                break;
            }
                
            case 3: {
                Student new_student = inputStudentDetails();
                printf("Enter position: ");
                scanf("%d", &position_to_insert);
                insertAtPosition(&student_list_head, new_student, position_to_insert);
                break;
            }
                
            case 4:
                deleteFromBeginning(&student_list_head);
                break;
                
            case 5:
                deleteFromEnd(&student_list_head);
                break;
                
            case 6:
                displayList(student_list_head);
                break;
                
            case 7:
                freeList(&student_list_head);
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
