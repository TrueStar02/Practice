#include <stdio.h>
#include <stdlib.h>
#include "unique.h"
int main(){
	int n, num;
	scanf("%d", &n);

	struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode* curr = head;
    for(int i = 0; i < n; ++i){
        scanf("%d", &num);
        struct ListNode* tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
        tmp->val = num;
        tmp->next = NULL;
        curr->next = tmp;
        curr = curr->next;
    }
    curr = head;
    head = head->next;
    free(curr);
    head = unique(head);
    curr = head;
    while(curr != NULL){
        printf("%d->", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
    while(head){
        struct ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }
	return 0;
}