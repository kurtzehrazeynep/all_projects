#ifndef LİBRARY_H
#define LİRARY_H
#include "book.h"
#include "member.h"

typedef struct
{
    InventoryEntry bookshelf[100];
    int bookcount;

    Member members[100];
    int membercount;

} LibraryManagement;

void init_library(LibraryManagement *lib);
void view_total_count_statistics(const LibraryManagement *lib);

void add_book(LibraryManagement *lib, const char *id, const char *title, const char *author);
void list_all_books(const LibraryManagement *lib);
void remove_book(LibraryManagement *lib, const char *id);

void add_member(LibraryManagement *lib, const char *id, const char *member_name);
void list_all_members(const LibraryManagement *lib);
void delete_member_registration(LibraryManagement *lib, const char *id);
void ban_member(LibraryManagement *lib, const char *id, const char *ban_reason);
void lift_the_ban(LibraryManagement *lib, const char *id);

void lend_book(LibraryManagement *lib, const char *book_id, const char *member_id);
void return_book(LibraryManagement *lib, const char *book_id, const char *member_id);

void load_books_from_file(LibraryManagement *lib);
void save_books_to_file(const LibraryManagement *lib);
void load_members_from_file(LibraryManagement *lib);
void save_members_to_json(const LibraryManagement *lib);

#endif