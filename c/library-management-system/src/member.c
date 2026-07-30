#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

static int total_members_count = 0;

Member *create_member(const char *id, const char *member_name)
{
    Member *new_member = (Member *)malloc(sizeof(Member));
    if (new_member == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strncpy(new_member->id, id, sizeof(new_member->id));
    new_member->id[sizeof(id) - 1] = '\0';

    strncpy(new_member->member_name, member_name, sizeof(member_name));
    new_member->member_name[sizeof(member_name) - 1] = '\0';

    new_member->is_the_member_registered = true;

    new_member->is_banned = false;

    strcpy(new_member->ban_reason, "");

    total_members_count++;
    return new_member;
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
    total_members_count--;
}
