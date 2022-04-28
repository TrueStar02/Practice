#ifndef TREE_H_
#define TREE_H_
#include<math.h>
typedef struct node {
  int x;
  struct node* left;
  struct node* right;
} BN;
void buildTree(BN** rootptr);
void outputTree(BN* root);
static BN * CreateNode(int num);
static void Print(BN * trnode);
void buildTree(BN** rootptr)
{   int num,count=0,time;
    BN *temp,*find;
    while(scanf("%d",&num)&&num!=-1)
    {   temp=CreateNode(num);
        count++;
        if(count==1)
        	*rootptr=temp;
        else
        {	find=*rootptr;
        	time=(int)(log(count)/log(2));
        	while(time>1)
        	{	time--;
        		if((count>>time)&1)
        			find=find->right;
        		else
        			find=find->left;
        	}
        	if(count&1)
        		find->right=temp;
        	else
        		find->left=temp;
        }
    }
}
void outputTree(BN* root)
{   Print(root);
}
static BN * CreateNode(int num)
{   BN *newnode=(BN *)malloc(sizeof(BN));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->x=num;
    return newnode;
}

static void Print(BN * trnode)
{   if(trnode!=NULL)
    {   Print(trnode->left);
        printf("%d ",trnode->x);
        Print(trnode->right);
    }
}
#endif