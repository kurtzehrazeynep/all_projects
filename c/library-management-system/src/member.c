#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <member.h>

static int total_members_count = 0;

Member *create_member(int id, char *member_name, bool is_the_member_registered, char *borowed_books_list, bool is_banned, char *ban_reason)
{
    Member *new_member = (Member *)malloc(sizeof(Member));
    if (new_member == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_member->id = id;

    strncpy(new_member->member_name, member_name, sizeof(member_name));
    new_member->member_name[sizeof(member_name) - 1] = '\0';

    new_member->is_the_member_registered = is_the_member_registered;

    strncpy(new_member->borrowed_books_list, borowed_books_list, sizeof(borowed_books_list));
    new_member->borrowed_books_list[sizeof(borowed_books_list) - 1] = '\0';

    new_member->is_banned = is_banned;

    strncpy(new_member->ban_reason, ban_reason, sizeof(ban_reason));
    new_member->ban_reason[sizeof(ban_reason) - 1] = '\0';
}

int get_total_member_counts(void)
{
    return total_members_count;
}

void free_members(Member *member)
{
    if (member != NULL)
    {
        free(member);
    }
}
