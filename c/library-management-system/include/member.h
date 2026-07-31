#ifndef MEMBER_H
#define MEMBER_H
#include <stdbool.h>
typedef struct
{
    char id[50];
    char member_name[100];
    bool is_the_member_registered;
    char borrowed_books_list[10][100];
    int borrowed_books_count;
    bool is_banned;
    char ban_reason[200];
} Member;
Member *create_member(const char *id, const char *member_name);
int get_total_member_counts(void);
void free_members(Member *member);
#endif