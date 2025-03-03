#include <stdio.h>
#include <stdlib.h>

int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;
int n;

void Enqueue(int a[], int* front, int* rear, int x) {
    if (*rear == n - 1) {
        printf("Queue is Full \n");
    } else {
        if (*front == -1) {
            *front = 0;
        }
        (*rear)++;
        a[*rear] = x;
        printf("Element %d inserted \n", x);
    }
}

void Dequeue(int a[], int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is Empty \n");
    } else {
        printf("Element %d deleted \n", a[*front]);
        (*front)++;
        if (*front > *rear) {
            *front = *rear = -1;
        }
    }
}

int AreQueuesIdentical(int a1[], int front1, int rear1, int a2[], int front2, int rear2) {
    // Display Queue 1
    if (front1 == -1 || front1 > rear1) {
        printf("Queue 1 is Empty \n");
    } else {
        printf("Queue 1: ");
        for (int i = front1; i <= rear1; i++) {
            printf("%d \t", a1[i]);
        }
        printf("\n");
    }

    // Display Queue 2
    if (front2 == -1 || front2 > rear2) {
        printf("Queue 2 is Empty \n");
    } else {
        printf("Queue 2: ");
        for (int i = front2; i <= rear2; i++) {
            printf("%d \t", a2[i]);
        }
        printf("\n");
    }

    // Now check if both queues are identical
    if (rear1 - front1 != rear2 - front2) {
        return 0; // Different size, not identical
    }

    for (int i = front1; i <= rear1; i++) {
        if (a1[i] != a2[i]) {
            return 0; // Different elements, not identical
        }
    }
    return 1; // Identical queues
}

int main() {
    printf("Enter the size of the Queue: ");
    scanf("%d", &n);

    int a1[n], a2[n], e;
    
    while (1) {
        int ch;
        printf("\n1. Enqueue to Queue 1\n");
        printf("2. Enqueue to Queue 2\n");
        printf("3. Dequeue from Queue 1\n");
        printf("4. Dequeue from Queue 2\n");
        printf("5. Displays and Checks if Queues are Identical\n");
        printf("6. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert into Queue 1: ");
                scanf("%d", &e);
                Enqueue(a1, &front1, &rear1, e);
                break;
            case 2:
                printf("Enter element to insert into Queue 2: ");
                scanf("%d", &e);
                Enqueue(a2, &front2, &rear2, e);
                break;
            case 3:
                Dequeue(a1, &front1, &rear1);
                break;
            case 4:
                Dequeue(a2, &front2, &rear2);
                break;
            case 5:
                if (AreQueuesIdentical(a1, front1, rear1, a2, front2, rear2)) {
                    printf("Queues are identical\n");
                } else {
                    printf("Queues are not identical\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

