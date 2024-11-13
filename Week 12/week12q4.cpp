#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books
#define MAX_BOOKS 100

// Structure to represent a book
typedef struct {
    char title[100];
    char author[100];
    int year;
    int bookID;
} Book;

// Function to add a book to the library
void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter the title of the book: ");
    getchar(); // To clear the buffer
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // Remove the trailing newline character

    printf("Enter the author of the book: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // Remove the trailing newline character

    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);

    // Assign a unique book ID based on the current number of books in the library
    newBook.bookID = *bookCount + 1;

    // Add the new book to the library array
    library[*bookCount] = newBook;
    (*bookCount)++;

    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks(Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", library[i].bookID);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n", library[i].year);
        printf("-----------------------------\n");
    }
}

// Function to search a book by title
void searchBookByTitle(Book library[], int bookCount, const char *title) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, title) != NULL) {
            found = 1;
            printf("\nBook Found:\n");
            printf("Book ID: %d\n", library[i].bookID);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("-----------------------------\n");
        }
    }

    if (!found) {
        printf("No book found with the title \"%s\".\n", title);
    }
}

// Main function to interact with the user
int main() {
    Book library[MAX_BOOKS];  // Array to store books
    int bookCount = 0;        // Count of books in the library

    int choice;
    char searchTitle[100];

    while (1) {
        // Display menu
        printf("\nLibrary Information System\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Search a book by title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                printf("Enter the title of the book to search: ");
                getchar();  // To clear the buffer
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = 0;  // Remove trailing newline
                searchBookByTitle(library, bookCount, searchTitle);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

