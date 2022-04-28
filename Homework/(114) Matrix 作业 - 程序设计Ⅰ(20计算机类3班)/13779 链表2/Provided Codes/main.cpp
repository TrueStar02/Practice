#include "List.h"

void PrintList(struct ListNode* head)
{
    bool space_flag = false;
    while(head != NULL)
    {
        if(space_flag) printf(" ");
        else space_flag = true;
        printf("%d", head->value);
        head = head ->next;
    }
    puts("");
}

void FreeList(struct ListNode *head)
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
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &(newNode->value));
        newNode->next = head;
        head = newNode;
    }
    head = ReverseList(head);
    PrintList(head);
    FreeList(head);
	return 0;
}