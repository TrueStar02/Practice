#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
bool insert(int position, int value)
{   int x;
    node *pnode=head;
    if(position<0||(position>0&&head==NULL))
        return 0;
    for(x=2;x<=position;x++)
    {   
        pnode=pnode->next;
        if(pnode==NULL)
            return 0;
    }
    node *pnew=(node *)malloc(sizeof(node));
    pnew->value=value;
    pnew->next=NULL;
    if(head==NULL)
     {  
         head=pnew;
     }
    else if(position==0)
    {	pnew->next=pnode;
        head=pnew;
    }
    else
    {   pnew->next=pnode->next;
        pnode->next=pnew;
    }
    size++;
    return 1;
}
int get(int position)
{   int x;
    node *pnode=head;
   
    for(x=1;x<=position;x++)
    {    
    	pnode=pnode->next;
    }
    return (pnode->value);

}
void clear()
{   node *temp;
    while(head!=NULL)
    {   temp=head;
        head=head->next;
        free(temp);
    }
}