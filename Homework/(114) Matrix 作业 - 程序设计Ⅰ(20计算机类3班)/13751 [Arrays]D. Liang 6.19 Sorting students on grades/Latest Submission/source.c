#include<stdio.h>
#include<ctype.h>
struct student
{   int num;
    char answer[10];
    int score;
};
void Process(int num);
int main(void)
{   int tasks,x,person;
    scanf("%d",&tasks);
    for(x=1;x<=tasks;x++)
    {   scanf("%d",&person);
        printf("test case %d:\n",x);
        Process(person);
    }
    return 0;
}
void Process(int num)
{   struct student details[num],temp;
    int x,y;
    for(x=0;x<num;x++)
    {   details[x].num=x;
        details[x].score=0;
        for(y=0;y<=9;y++)
        {  while((details[x].answer[y]=getchar())&&(!isalpha(details[x].answer[y])))
            continue;
        }
    }
    char answer[10];
    for(y=0;y<=9;y++)
    {  while((answer[y]=getchar())&&(!isalpha(answer[y])))
            continue;
    }
 
 	for(x=0;x<num;x++)
    for(y=0;y<=9;y++)
    {   if(details[x].answer[y]==answer[y])
            details[x].score++;
    }
    for(x=0;x<num-1;x++)
    for(y=x+1;y<num;y++)
    if(details[x].score>details[y].score||(details[x].score==details[y].score)&&(details[x].num>details[y].num))
    {   temp=details[x];
        details[x]=details[y];
        details[y]=temp;
    }
    for(x=0;x<num;x++)
        printf("Student %d: %d\n",details[x].num,details[x].score);
   getchar();
}