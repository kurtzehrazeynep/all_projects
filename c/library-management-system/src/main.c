#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    LibraryManagement system;
    init_library(&system);
    char choice_str[100];
    int choice;
    char book_id[50];
    char member_id[50];
    char member_name[100];
    char title[100];
    char author_name[100];
    char ban_reason[200];

    do
    {
        printf("\n=== BOOK & JSON TEST MENU ===\n");
        printf("1. Add New Book\n");
        printf("2. List All Books\n");
        printf("3. View Total Count Statistics\n");
        printf("4. Register a member.\n");
        printf("5. List members\n");
        printf("6. delete book\n");
        printf("7. Cancel membership registration\n");
        printf("8. Lend a book.\n");
        printf("9. return book\n");
        printf("10. Ban member\n");
        printf("11. Lift the ban\n");
        printf("12. Exit\n");
        printf("Your choice: ");
        
        if (fgets(choice_str, sizeof(choice_str), stdin) == NULL)
        {
            continue;
        }
        choice_str[strcspn(choice_str, "\r\n")] = '\0';

        // Boş girdi kontrolü
        if (choice_str[0] == '\0')
        {
            printf("Invalid Option!\n");
            continue;
        }

        // strtol kullanarak metnin tamamen sayı olup olmadığını denetliyoruz
        char *endptr;
        long val = strtol(choice_str, &endptr, 10);

        // Eğer sayının devamında harf kaldıysa (*endptr != '\0') veya sayı 1-12 aralığında değilse geçersiz say
        if (*endptr != '\0' || val < 1 || val > 12)
        {
            printf("Invalid Option!\n");
            continue; // Döngünün başına dön ve tekrar menü sor
        }

        choice = (int)val;

        if (choice == 1)
        {
            printf("Enter Book ID: ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strcspn(book_id, "\r\n")] = '\0';

            printf("Enter Book Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\r\n")] = '\0';

            printf("Enter Author Name: ");
            fgets(author_name, sizeof(author_name), stdin);
            author_name[strcspn(author_name, "\r\n")] = '\0';

            add_book(&system, book_id, title, author_name);
        }
        else if (choice == 2)
        {
            printf("Listing All Books...\n");
            list_all_books(&system);
        }
        else if (choice == 3)
        {
            printf("Viewing Statistics...\n");
            view_total_count_statistics(&system);
        }
        else if (choice == 4)
        {
            printf("Please Enter Member ID: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strcspn(member_id, "\r\n")] = '\0';

            printf("Enter Member Name: ");
            fgets(member_name, sizeof(member_name), stdin);
            member_name[strcspn(member_name, "\r\n")] = '\0';

            add_member(&system, member_id, member_name);
        }
        else if (choice == 5)
        {
            list_all_members(&system);
        }
        else if (choice == 6)
        {
            printf("Please Enter Book ID: ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strcspn(book_id, "\r\n")] = '\0';
            remove_book(&system, book_id);
        }
        else if (choice == 7)
        {
            printf("Please enter the ID of the member you wish to cancel: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strcspn(member_id, "\r\n")] = '\0';
            delete_member_registration(&system, member_id);
        }
        else if (choice == 8)
        {
            printf("Please enter the ID of the book you wish to borrow: ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strcspn(book_id, "\r\n")] = '\0';

            printf("Please enter the member ID of the person to whom the book will be lent: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strcspn(member_id, "\r\n")] = '\0';

            lend_book(&system, book_id, member_id);
        }
        else if (choice == 9)
        {
            printf("Enter the ID of the member who will make the return: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strcspn(member_id, "\r\n")] = '\0';

            printf("Please Enter The ID of the book you wish to return: ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strcspn(book_id, "\r\n")] = '\0';

            return_book(&system, book_id, member_id);
        }
        else if (choice == 10)
        {
            printf("Enter the ID of the member to be banned: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strcspn(member_id, "\r\n")] = '\0';

            printf("Please Enter The Reason for the ban: ");
            fgets(ban_reason, sizeof(ban_reason), stdin);
            ban_reason[strcspn(ban_reason, "\r\n")] = '\0';

            ban_member(&system, member_id, ban_reason);
        }
        else if (choice == 11)
        {
            printf("Enter the ID of the User whose ban is to be lifted: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strcspn(member_id, "\r\n")] = '\0';

            lift_the_ban(&system, member_id);
        }
        else if (choice == 12)
        {
            printf("Exiting test system. Goodbye!\n");
            return 0;
        }
    } while (1);

    return 0;
}