#include "reverse.h"
#include<stdio.h>
struct ListNode* reverse(struct ListNode* head)
{   if(head==NULL)
        return head;
    struct ListNode* newhead=head,*temp,*pnode=head->next;
    newhead->next=NULL;
    while(pnode!=NULL)
    {   temp=pnode;
        pnode=pnode->next;
        temp->next=newhead;
        newhead=temp;
    }
    return newhead;
}