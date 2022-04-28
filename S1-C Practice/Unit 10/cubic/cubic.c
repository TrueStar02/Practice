#include<stdio.h>
#define PLANE 4
int sum(int (*arr)[3][2],int n);
int main()
{int arr[4][3][2]={{{0,1},{10,11},{20,21}},{{100,101},{110,111},{120,121}},{{200,201},{210,211},{220,221}},{{300,301},{310,311},{320,321}}};
 int (*ptr)[3][2];
 ptr=arr;
 printf("%p\n%p\n%p\n%p\n",ptr,ptr[0][0]+1,ptr[0]+1,ptr+1);
 int result=sum(arr,PLANE);
 printf("%d\n",result);
 return 0;
}
int sum(int (*arr)[3][2],int n)
{int x,y,z,sum=0;
 for(x=0;x<n;x++)
 for(y=0;y<3;y++)
 for(z=0;z<2;z++)
 sum+=arr[x][y][z];
 return sum;
}
