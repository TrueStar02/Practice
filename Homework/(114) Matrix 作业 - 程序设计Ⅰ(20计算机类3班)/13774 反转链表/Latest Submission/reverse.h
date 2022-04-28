#ifndef REVERSE_H
#define REVERSE_H

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head);

#endif