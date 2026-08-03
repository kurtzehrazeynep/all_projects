#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

static int total_books_count = 0;

InventoryEntry *create_book(const char* id, const char *title, const char *author, bool in_library)
{
    InventoryEntry *new_book = (InventoryEntry *)malloc(sizeof(InventoryEntry));
    if (new_book == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strncpy(new_book->id, id, sizeof(new_book->id) - 1);
    new_book->id[sizeof(new_book->id) - 1] = '\0';

    strncpy(new_book->book_title, title, sizeof(new_book->book_title) - 1);
    new_book->book_title[sizeof(new_book->book_title) - 1] = '\0';

    strncpy(new_book->author_name, author, sizeof(new_book->author_name) - 1);
    new_book->author_name[sizeof(new_book->author_name) - 1] = '\0';

    new_book->in_library = in_library;

    total_books_count++;

    printf("New book: '%s-%s' has been added.\n", new_book->book_title, new_book->author_name);
    return new_book;
}
int get_total_books_count(void)
{
    return total_books_count;
}

void free_books(InventoryEntry *book)
{
    if (book != NULL)
    {
        free(book);
    }
    total_books_count--;
}
