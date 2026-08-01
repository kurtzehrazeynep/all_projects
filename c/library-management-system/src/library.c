#include <stdio.h>
#include <stdlib.h>
#include "library.h"

void init_library(LibraryManagement *lib)
{
    lib->bookcount = 0;
    lib->membercount = 0;

    load_books_from_file(lib);
    load_members_from_file(lib);
}

void add_book(LibraryManagement *lib, const char *id, const char *title, const char *author)
{
    if (lib->bookcount < 100)
    {
        strcpy(lib->bookshelf[lib->bookcount].id, id);
        strcpy(lib->bookshelf[lib->bookcount].book_title, title);
        srtcpy(lib->bookshelf[lib->bookcount].author_name, author);
        lib->bookshelf[lib->bookcount].in_library = true;
        lib->bookcount++;

        save_books_to_file(lib);
        printf("Book succesfully saved!");
    }
    else
    {
        printf("⚠️ Bookshelf is ful!");
    }
}
void list_all_books(const LibraryManagement *lib)
{
    if (lib->bookcount == 0)
    {
        printf("The Bookshelf is empty!\n");
    }
    else
    {
        printf("\n--- Current Bookshelf Inventory ---\n");
        for (int i = 0; i < lib->bookcount; i++)
        {
            const char *status = lib->bookshelf[i].in_library ? "in library" : "Borrowed";

            printf("-[%s] %s by %s [%s]\n",
                   lib->bookshelf[i].id,
                   lib->bookshelf->book_title,
                   lib->bookshelf->author_name,
                   status);
        }
    }
}

void total_count_statistica(const LibraryManagement *lib)
{
    printf("Total Book Count : %d ", lib->bookcount);
    printf("Total Member Count : %d ", lib->membercount);
}

void add_member(LibraryManagement *lib, const char *id, const char *member_name)
{
    if (lib->members < 100)
    {
        strcpy(lib->members[lib->membercount].id, id);
        strcpy(lib->members[lib->membercount].member_name, member_name);
        lib->members[lib->membercount].is_the_member_registered = true;
        lib->members[lib->membercount].is_banned = false;
        strcpy(lib->members[lib->membercount].ban_reason, "");
        lib->members[lib->membercount].borrowed_books_count = 0;
        lib->membercount++;

        save_members_to_file(lib);
        printf("Member successfully saved!\n");
    }
    else
    {
        printf("⚠️ Member list is full!\n");
    }
}
void list_all_members(const LibraryManagement *lib)
{
    if (lib->membercount == 0)
    {
        printf("⚠️ No registered members found.\n");
    }
    else
    {
        printf("\n--- Registered Members List ---\n");
        for (int i = 0; i < lib->membercount; i++)
        {
            char status[200];
            if (lib->members[i].is_the_member_registered)
            {
                strcpy(status, "DEACTIVATED");
            }
            else if (lib->members[i].is_banned)
            {
                snprintf(status, sizeof(status), "🚫 BANNED (Reason: %s)", lib->members[i].ban_reason);
            }
            else
            {
                strcpy(status, "Active");
            }
            printf("- [%s] %s | Books Borrowed: %d | Status: %s\n",
                   lib->members[i].id,
                   lib->members[i].member_name,
                   lib->members[i].borrowed_books_count,
                   status);
        }
    }
}
void remove_book(LibraryManagement *lib, const char *id)
{
    int index = -1;
    for (int i = 0; i < lib->bookcount; i++)
    {
        if (strcmp(lib->bookshelf[i].id, id) == 0)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        if (lib->bookshelf[index].in_library)
        {
            for (int i = 0; i < lib->bookcount - 1; i++)
            {
                lib->bookshelf[i] = lib->bookshelf[i + 1];
            }
            lib->bookcount--;
            save_books_to_file(lib);
            rintf("Book ID %s has been removed from the library.\n", id);
        }
        else
        {
            printf("⚠️ Cannot remove book! It is currently borrowed.\n");
        }
    }
    else
    {
        printf("⚠️ Book not found.\n");
    }
}
void delete_member_registration(LibraryManagement *lib, const char *id)
{
    for (int i = 0; i < lib->membercount; i++)
    {
        if (strcmp(lib->members[i].id, id) == 0)
        {
            if (lib->members[i].borrowed_books_count == 0)
            {
                lib->members[i].is_the_member_registered = false;
                save_members_to_file(lib);
                printf("Member ID %s registration cancelled (Account deactivated).\n", id);
            }
            else
            {
                printf("⚠️ Cannot cancel membership! Member has unreturned books.\n");
            }
            return;
        }
    }
    printf("⚠️ Member not found.\n");
}
void lend_book(LibraryManagement *lib, const char *book_id, const char *member_id)
{
    int index;
    int index_m;
    for (int i = 0; i < lib->bookcount; i++)
    {
        if (strcmp(lib->bookshelf[i].id, book_id) != 0)
        {
            printf("⚠️ Book not found!");
            return NULL;
        }
        else if (strcmp(lib->bookshelf[i].id, book_id) == 0)
        {
            int index = i;
            if (lib->bookshelf[index].in_library == false)
            {
                printf("⚠️ Book is already borrowed by someone else.");
                return;
            }
        }
    }
    for (int i = 0; i < lib->membercount; i++)
    {
        if (strcmp(lib->members[i].id != 0))
        {
            printf("⚠️ Member not found!");
            return;
        }
        else if (strcmp(lib->members[i].id == 0))
        {
            index_m = i;
            if (lib->members[index_m].is_the_member_registered == false)
            {
                printf("⚠️ Lending failed! Member registration is cancelled.");
                return;
            }
            if (lib->members[index_m].is_banned)
            {
                printf("🚫 Lending Failed! Member is banned.");
                return;
            }
            lib->bookshelf[index].in_library = false;
            lib->members->borrowed_books_count++;
            strcnpy(lib->members[index_m].borrowed_books_list[lib->members[index_m].borrowed_books_count], lib->bookshelf[index].book_title);
            save_books_to_file(lib);
            save_members_to_file(lib);
            printf("Book '%s' succesfully lent to '%s'", lib->bookshelf[index].book_title, lib->members[index_m].member_name);
            return;
        }
    }
    return;
}
void return_book(LibraryManagement *lib, const char *book_id, const char *member_id)
{
    int index_m;
    int index_b;
    for (int i = 0; i < lib->membercount; i++)
    {
        if (strcmpy(lib->members[i].id, member_id) != 0)
        {
            printf("⚠️ Invalid member ID.");
            return NULL;
        }
        index_m = i;
    }
    for (int i = 0; i < lib->bookcount; i++)
    {
        if (strcmpy(lib->bookshelf[i].id, book_id) != 0)
        {
            printf("⚠️ Invalid member ID.");
            return NULL;
        }
    }
    for (int i = 0; i < lib->members->borrowed_books_count; i++)
    {
        if (strcmpy(lib->members[index_m].borrowed_books_list[i], lib->bookshelf[index_b].book_title) != 0)
        {
            printf("⚠️ This book was not borrowed by this member.");
            return;
        }
        else if (strcmpy(lib->members[index_m].borrowed_books_list[i], lib->bookshelf[index_b].book_title) == 0)
        {
            for (int i = 0; i < lib->members->borrowed_books_count; i++)
            {
                lib->members[index_m].borrowed_books_list[i] = lib->members[index_m].borrowed_books_list[i + 1];
                lib->members[index_m].borrowed_books_list[lib->members->borrowed_books_count - 1] = '\0';
            }
            lib->bookshelf[index_b].in_library = true;
            lib->members[index_m].borrowed_books_count--;
        }
    }
    save_books_to_file(lib);
    save_members_to_file(lib);
    return;
}
void ban_member(LibraryManagement *lib, const char *id, const char *ban_reason)
{
    for (int i = 0; i < lib->membercount; i++)
    {
        if (strcmpy(lib->members[i].id, id) != 0)
        {
            printf("⚠️ Member not found!.");
            return NULL;
        }
        else if (strcmpy(lib->members[i].id, id) == 0)
        {
            lib->members[i].is_banned = true;
            strcpy(lib->members[i]->ban_reason, ban_reason);
            save_members_to_file(lib);
            printf("🚫 Member %s has been banned. Reason %s", lib->members[i].member_name, lib->members[i].ban_reason);
        }
    }
    return;
}
void lift_the_ban(LibraryManagement *lib, const char *id)
{
    for (int i = 0; i < lib->membercount; i++)
    {
        if (strcmpy(lib->members[i].id, id) != 0)
        {
            printf("⚠️Member not found");
            return NULL;
        }
        else if (strcmpy(lib->members[i].id, id) == 0)
        {
            lib->members[i].is_banned = false;
            strcpy(lib->members[i].ban_reason, "");
            save_members_to_file;
            printf("Ban Lifted for member %s", lib->members[i].member_name),
        }
    }
    return;
}

// JSON BOLUMU
void save_books_to_file(const LibraryManagement *lib)
{
    FILE *file = fopen("books.txt", "w");
    if (file == NULL)
    {
        return;
    }
    for (int i = 0; i < lib->bookcount; i++)
    {
        fprintf(file, "%s|%s|%s|%d\n",
                lib->bookshelf[i].id,
                lib->bookshelf[i].book_title,
                lib->bookshelf[i].author_name,
                lib->bookshelf[i].in_library);
    }
    fclose(file);
}

void load_books_from_file(LibraryManagement *lib)
{
    FILE *file = fopen("books.txt", "r");
    if (file == NULL)
    {
        return;
    }
    lib->bookcount = 0;
    while (fscanf(file, "%49[^|]|%99[^|]|%99[^|]|%d\n",
                  lib->bookshelf[lib->bookcount].id,
                  lib->bookshelf[lib->bookcount].book_title,
                  lib->bookshelf[lib->bookcount].author_name,
                  (int *)&lib->bookshelf[lib->bookcount].in_library) == 4)
    {
        lib->bookcount++;
        if (lib->bookshelf >= 100)
        {
            break;
        }
    }
    fclose(file);
}
void save_members_to_file(const LibraryManagement *lib)
{
    FILE *file = fopen("members.txt", "w");
    if (file == NULL)
    {
        return;
    }
    for (int i = 0; i < lib->membercount i++)
    {
        fprintf(file, "%s|%s|%d|%d|%s|%d\n",
                lib->members[lib->membercount].id,
                lib->members[lib->membercount].member_name,
                (int *)&lib->members[lib->membercount].is_the_member_registered,
                (int *)&lib->members[lib->membercount].is_banned,
                lib->members[lib->membercount].ban_reason,
                (int *)&lib->members[lib->membercount].borrowed_books_count);
    }
    fclose(file);
}
void load_members_from_file(LibraryManagement *lib)
{
  FILE*file = fopen("members.txt","r");
  if (file == NULL)
  {
    return;
  }
  lib->membercount = 0;
  while (fscanf(file,"%49[^|]|%99[^|]|%d[^|]|%d[^|]|%9[]"))
  {

  }
  
  
}
