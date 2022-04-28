#include<stdio.h>
void print(int size);
int main(void)
{   int num,size,x;
    scanf("%d",&num);
    for(x=1;x<=num;x++)
    {   scanf("%d",&size);
        print(size);
    }
    return 0;
}
void print(int size)
{   for(int x=1;x<=size;x++)  
    {    for(int y=1;y<=size;y++)
        {   if(x==1||y==1||x==y)
                printf(" 1");
            else
                printf(" 0");
        }
        printf("\n");
    }
}