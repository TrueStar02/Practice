#ifndef STACK_H_
#define STACK_H_
#include<stdbool.h>
typedef int Item;
struct node
{	Item item;
	struct node *next;
};
typedef struct node Node;
struct stack
{	Node *first;
	Node *last;
	int items;
};
typedef struct stack Stack;
void InitializeStack(Stack *pst);
bool StackIsFull(Stack *pst);
bool StackIsEmpty(Stack *pst);
bool EnStack(Item item,Stack *pst);
bool DeStack(Item *item,Stack *pst);
int StackItemCount(Stack *pst);
void EmptyStack(Stack *pst);
#endif
