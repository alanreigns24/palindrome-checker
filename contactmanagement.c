#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    struct Contact contacts[100];
    int count = 0, choice;
    char searchName[50];

    do {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[count].name);
                printf("Enter phone: ");
                scanf("%s", contacts[count].phone);
                count++;
                break;

            case 2:
                printf("\n--- Contacts ---\n");
                for (int i = 0; i < count; i++) {
                    printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
                }
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", searchName);
                for (int i = 0; i < count; i++) {
                    if (strcmp(contacts[i].name, searchName) == 0) {
                        printf("Found! Phone: %s\n", contacts[i].phone);
                        break;
                    }
                }
                break;
        }
    } while (choice != 4);

    return 0;
}
