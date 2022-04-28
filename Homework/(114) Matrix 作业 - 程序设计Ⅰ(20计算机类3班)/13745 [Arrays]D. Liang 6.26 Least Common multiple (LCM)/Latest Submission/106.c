#include<stdio.h>
void Process(int a,int b);
int main()
{   int tasks,x,a,b;
    scanf("%d",&tasks);
    for(x=1;x<=tasks;x++)
    {   scanf("%d%d",&a,&b);
        printf("test case %d:\n",x);
        Process(a,b);
    }
    return 0;
}
void Process(int a,int b)
{   int a1=a,b1=b,temp;
    if(a1<b1)
    {   temp=a1;
        a1=b1;
        b1=temp;
    }
    while(a1%b1)
    {   temp=a1;
        a1=b1;
        b1=temp%b1;
    }
    printf("%d %d %d\n",a,b,a*b/b1);
}