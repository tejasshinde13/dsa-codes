#include <stdio.h>
#include <stdlib.h>

#define MAX 5   

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int order) {
    if (isFull()) {
        printf("Queue Overflow! Cannot take more orders.\n");
        return;
    }
    if (front == -1) front = 0;  // first order
    queue[++rear] = order;
    printf("Order %d added to the queue.\n", order);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No orders to serve.\n");
        return;
    }
    printf("Order %d served and removed from queue.\n", queue[front]);
    front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty. No pending orders.\n");
        return;
    }
    printf("Current Orders in Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, orderNo;
    printf("=== Pizza Order Queue Simulation ===\n");
    while (1) {
        printf("\n1. Add Order (Enqueue)\n");
        printf("2. Serve Order (Dequeue)\n");
        printf("3. Display Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter order number: ");
                scanf("%d", &orderNo);
                enqueue(orderNo);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
