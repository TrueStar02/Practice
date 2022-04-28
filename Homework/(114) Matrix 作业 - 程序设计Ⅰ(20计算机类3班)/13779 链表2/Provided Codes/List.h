#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int value;
    struct ListNode *next;
};

struct ListNode* ReverseList(struct ListNode *head);