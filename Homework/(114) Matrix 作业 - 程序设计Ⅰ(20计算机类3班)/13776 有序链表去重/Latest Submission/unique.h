#ifndef UNIQUE_H
#define UNIQUE_H

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* unique(struct ListNode* head);

#endif