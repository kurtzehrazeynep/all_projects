#include <stdio.h>
#include <string.h>
int main()
{
    int choice;
    int book_id[50];
    int member_id[50];
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

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;
        switch (choice)
        {
        case 1:
            printf("Enter Book ID: ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strspn(book_id, "\n")] = '\0';

            printf("Enter Book Title: ");
            fgets(title, sizeof(title), stdin);
            title[strspn(title, "\n")] = '\0';

            printf("Enter Author Name: ");
            fgets(author_name, sizeof(author_name), stdin);
            author_name[strspn(author_name, "\n")] = '\0';

            // system_add_book (id,title,author_name) gelicek

            break;
        case 2:
            printf("Liating All Books...");
            // system_list_all_books buraya gelicek
        case 3:
            printf("Viewing Statistics...");
            // system_view_total_count_statistics
        case 4:
            printf("Please Enter Member ID: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';

            printf("Enter Member Name: ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';
            // system_add_member(member_id,member_name)
        case 5:
            // system_list_all_members
        case 6:
            printf("Please Enter Book ID: ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strspn(book_id, "\n")] = '\0';
            // system_remove_book(id)
        case 7:
            printf("Please enter the ID  of the member you wish to cancel");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';
            // system_delete_member_registration(id)
        case 8:
            printf("Please enter the ID of the book you wish to borrow.");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strspn(book_id, "\n")] = '\0';

            printf("Please enter the member ID of the person to whom the book will be lent. ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';

        case 9:
            printf("Enter the ID of the member who will make the return.");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';

            printf("Please Enter The ID of the book you wish to return. ");
            fgets(book_id, sizeof(book_id), stdin);
            book_id[strspn(book_id, "\n")] = '\0';

            // system_return_book(book_id,member_id)

        case 10:
            printf("Enter the ID of the member to be banned. ");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';

            printf("Please Enter The Reason for the ban. ");
            fgets(ban_reason, sizeof(ban_reason), stdin);
            ban_reason[strspn(ban_reason, "\n")] = '\0';
        // system_ban_member(member_id,ban_reason)
        case 11:
            printf("Enter the ID of the User whose ban is to be lifted.");
            fgets(member_id, sizeof(member_id), stdin);
            member_id[strspn(member_id, "\n")] = '\0';

            // system_lisft_the_ban(member_id)
        case 12:
            printf("Exiting test system. Goodbye!");
            return 0;

        default:
            printf("Invalid Option!");
        }

    } while (1);
    return 0;
}