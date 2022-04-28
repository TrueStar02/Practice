#include<stdio.h>
#include<stdbool.h>
int main(void)
{   int l,tasks,x,a,b,y;
    scanf("%d%d",&l,&tasks);
    bool road[l+1];
    for(x=0;x<=l;x++)
        road[x]=0;
    int tree=l+1;
    for(x=1;x<=tasks;x++)
    {   scanf("%d%d",&a,&b);
        for(y=a;y<=b;y++)
            road[y]=1;

    }
    for(x=0;x<=l;x++)
    if(road[x])
        tree--;
    printf("%d",tree);
    return 0;
}