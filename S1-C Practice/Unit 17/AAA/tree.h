#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
  int x;
  struct node* left;
  struct node* right;
} BN;
struct pair
{   BN *parent;
    BN *child;
};
typedef struct pair Pair;
void buildTree(BN** rootptr);
void outputTree(BN* root);
static BN * CreateNode(int num);
static void AddNode(BN **ptree,BN *trnode);
static Pair SearchNode(BN *root,int num);
static void Print(BN * trnode);
void buildTree(BN** rootptr)
{   int num;
    BN *temp;
    while(scanf("%d",&num)&&num!=-1)
    {   
    	temp=CreateNode(num);
        AddNode(rootptr,temp);
        Print(*rootptr);
        putchar('\n');
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
static void AddNode(BN **ptree,BN *trnode)
{   Pair temp;
    if(*ptree==NULL)
        *ptree=trnode;
    else
    {   if((*ptree)->x>trnode->x)
         {  if((*ptree)->left==NULL)
         		(*ptree)->left=trnode;
         	else
         		AddNode(&(*ptree)->left,trnode);
         }
        else 
         {   if((*ptree)->right==NULL)
         		(*ptree)->right=trnode;
         	else
         		AddNode(&(*ptree)->right,trnode);
         	
         }
         
    }   
}

static void Print(BN * trnode)
{   if(trnode!=NULL)
    {   Print(trnode->left);
        printf("%d ",trnode->x);
        Print(trnode->right);
    }
}
