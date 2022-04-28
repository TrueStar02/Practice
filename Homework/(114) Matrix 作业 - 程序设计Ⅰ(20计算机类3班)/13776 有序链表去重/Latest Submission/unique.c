#include <stdio.h>
#include <stdlib.h>
#include "unique.h"
struct ListNode* unique(struct ListNode* head)
{   if(head==NULL)
        return head;
    struct ListNode * pnode=head,*temp;
    while(pnode->next!=NULL)
    {   while(pnode->next!=NULL&&pnode->val==pnode->next->val)
        {   temp=pnode->next;
            pnode->next=pnode->next->next;
            free(temp);
        }
        if(pnode->next!=NULL)
        pnode=pnode->next;
    }
    return head;
}