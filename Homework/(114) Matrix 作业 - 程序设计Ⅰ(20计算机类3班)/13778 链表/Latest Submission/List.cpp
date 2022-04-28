#include "List.h"
void PrintList(struct ListNode* head)
{   struct ListNode *pnode=head;
    while(pnode!=NULL)
    {   printf("%d ",pnode->value);
        pnode=pnode->next;
    }
}