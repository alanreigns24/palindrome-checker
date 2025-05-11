#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
    char customerName[50];
    struct Order* next;
};

struct Order *front = NULL, *rear = NULL;

void enqueue(char name[]) {
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
    strcpy(newOrder->customerName, name);
    newOrder->next = NULL;

    if (rear == NULL) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }
    printf("Order placed for %s\n", name);
}

void dequeue() {
    if (front == NULL) {
        printf("No orders in queue.\n");
        return;
    }

    struct Order* temp = front;
    printf("Delivering order for %s\n", front->customerName);
    front = front->next;
    free(temp);

    if (front == NULL)
        rear = NULL;
}

void displayQueue() {
    struct Order* temp = front;
    printf("\n--- Pending Orders ---\n");
    while (temp != NULL) {
        printf("Customer: %s\n", temp->customerName);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char name[50];

    do {
        printf("\n1. Place Order\n2. Deliver Order\n3. View Orders\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                enqueue(name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
        }
    } while (choice != 4);

    return 0;
}
