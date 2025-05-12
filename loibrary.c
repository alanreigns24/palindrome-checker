#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book* prev;
    struct Book* next;
};

struct Book* head = NULL;

void addBook(int id, char title[], char author[]) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->prev = NULL;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBook;
        newBook->prev = temp;
    }

    printf("Book added: %s by %s\n", title, author);
}

void displayBooks() {
    struct Book* temp = head;
    if (temp == NULL) {
        printf("Library is empty.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    while (temp != NULL) {
        printf("ID: %d | Title: %s | Author: %s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}

void deleteBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            printf("Book with ID %d deleted.\n", id);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

void searchBook(int id) {
    struct Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Found - ID: %d | Title: %s | Author: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book with ID %d not found.\n", id);
}

int main() {
    int choice, id;
    char title[100], author[100];

    while (1) {
        printf("\n--- Library Book Management ---\n");
        printf("1. Add Book\n2. Display Books\n3. Delete Book\n4. Search Book\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Book Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;  // remove newline
                printf("Enter Author Name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0;
                addBook(id, title, author);
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;

            case 4:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBook(id);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
