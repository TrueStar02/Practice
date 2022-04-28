#include "List.h"
struct ListNode* ReverseList(struct ListNode *head)
{   struct ListNode *newhead=head,*pnode=head->next,*temp;
    newhead->next=NULL;
    while(pnode!=NULL)
    {   temp=pnode;
        pnode=pnode->next;
        temp->next=newhead;
        newhead=temp;
    }
    return newhead;

}