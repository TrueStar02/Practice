#include "List.h"

void FreeList(ListNode *head)
{
    while(head != NULL)
    {
        struct ListNode *tmpNode = head;
        head = head->next;
        free(tmpNode);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct ListNode *head = NULL;
    while(n--)
    {
        struct ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        scanf("%d", &(newNode->value));
        newNode->next = head;
        head = newNode;
    }
    PrintList(head);
    FreeList(head);
    return 0;
}
