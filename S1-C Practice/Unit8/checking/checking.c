#include<stdio.h>
#include<stdbool.h>
#define MAX 100000000
#define MIN -100000000
long getlong(void);
bool badlimits(long begin,long end,long lowest,long highest);
long squaresum(long begin,long end);
int main(void)
{	long begin,end,answer;
 	printf("Tell me the lower limit:");
 	begin=getlong();
 	printf("Tell me the upper limit:");
 	end=getlong();
 	while(begin!=0||end!=0)
 	{	if(badlimits(begin,end,MIN,MAX))
  			printf("Please try again!\n");
  		else
  		{	answer=squaresum(begin,end);
   			printf("The result you want is %ld\n",answer);
  		}
  		printf("Now start the next group:) or press two zeros to quit\n");
  		printf("Tell me the lower limit:");
  		begin=getlong();
  		printf("Tell me the upper limit:");
 		end=getlong();
 	}
 	printf("Byebye!\n");
 	return 0;
}  
long getlong(void)
{	long number;
 	char ch;
 	while(scanf("%ld",&number)!=1)
 	{	while((ch=getchar())!='\n')
 			putchar(ch);
  		printf(" isn't an interger!Try again:");
 	}
 	return number;
}   
bool badlimits(long begin,long end,long lowest,long highest)    
{	bool error=0;
 	if(begin>end)
 	{	printf("%ld is bigger than %ld!\n",begin,end);
  		error=1;
 	}
 	if(begin>highest||end>highest)
 	{	printf("The number should be %ld or smaller.\n",highest);
  		error=1;
 	}
 	if(begin<lowest||end<lowest)
 	{	printf("The number should be %ld or bigger.\n",lowest);
  		error=1;
 	}
 	return error;
}
long squaresum(long begin,long end)
{	long x,sum=0;
 	for(x=begin;x<=end;x++)
 		sum+=x*x;
 	return sum;
} 
                                                                                                 
