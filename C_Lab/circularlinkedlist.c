#include <stdio.h>
#include <stdlib.h>

int count = 0;
int MAX_SIZE = 0;

struct node {
    int data;
    struct node* next;
} *head = NULL;

void insertBegin(int data) {
    if (count >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    count++;
}

void insertEnd(int data) {
    if (count >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    count++;
}

void insertMiddle(int data, int pos) {
    if (count >= MAX_SIZE) {
        printf("List is full\n");
        return;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos <= 1 || head == NULL) {
        insertBegin(data);
        return;
    }

    struct node* temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    count++;
}

void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct node* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }
    free(temp);
    count--;
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        struct node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
    free(temp);
    count--;
}

void deleteMiddle(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos <= 1) {
        deleteBegin();
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    for (int i = 1; temp->next != head && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    count--;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Head\n");
}

int main() {
    int data, position, choice;

    printf("Enter the size of the list: ");
    scanf("%d", &MAX_SIZE);

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert in Middle\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Middle\n");
        printf("7. Display List\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertBegin(data);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertMiddle(data, position);
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteMiddle(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

