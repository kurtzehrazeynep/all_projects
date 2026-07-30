#ifndef MEMBER_H
#define MEMBER_H
#include <stdbool.h>
typedef struct
{
    int id;
    char member_name[100];
    bool is_the_member_registered;
    char borrowed_books_list[10][50];
    bool is_banned;
    char ban_reason[200];
} Member;
Member *create_member(int id, const char *member_name, bool is_the_member_registered, const char *borowed_books_list, bool is_banned, const *ban_reason);
int get_total_member_counts(void);
void free_members(Member *member);
#endif