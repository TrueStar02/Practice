#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void initialize(struct stack* s)
{   s->elements=(int *)malloc(MAX_SIZE*sizeof(int));
    s->top=0;
}
int pop(struct stack* s)
{   if(s->top==0)
        return -1;
    s->top--;
    return s->elements[s->top];

}

int push(struct stack* s, int number)
{   if(s->top==100)
        return -1;
    s->elements[s->top]=number;
    s->top++;
    return number;

}

int get_size(struct stack* s)
{   return s->top;
}
int get_top(struct stack* s)
{   if(!s->top)
        return -1;
    return s->elements[s->top-1];
}
int empty(struct stack* s)
{   return !(s->top);

}
void list(struct stack* s)
{   int x;   
    for(x=(s->top)-1;x>=1;x--)
        printf("%d ",s->elements[x]);
    if(empty(s))
        puts("Empty stack");
    else
        printf("%d\n",*(s->elements));
}