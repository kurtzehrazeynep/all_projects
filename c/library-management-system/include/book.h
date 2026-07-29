#ifndef BOOK_H
#define BOOK_H
#include <stdbool.h>
typedef struct
{
    int id;
    char book_title[100];
    char author_name[100];
    bool in_library;
} InventoryEntry;
InventoryEntry* create_book(int id,const char* book_title, const char* author_name, bool in_library);
int get_total_books_count(void);
void free_books(InventoryEntry*book);
#endif
