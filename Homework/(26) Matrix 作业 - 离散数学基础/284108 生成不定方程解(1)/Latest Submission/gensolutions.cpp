#include<iostream>
using namespace std;
void print(int * arr,int *lim,int size)
{   cout<<"(";
    int x;
    for(x=0;x<size-1;x++)
        cout<<arr[x]+lim[x]<<",";
    cout<<arr[size-1]+lim[size-1]<<")\n";
}
int main()
{   int ukn,sum,x,limsum=0,count=0;
    cin>>ukn>>sum;
    int lim[ukn];
    for(x=0;x<ukn;x++)
    {   cin>>lim[x];
        limsum+=lim[x];
    }
    sum-=limsum;
    int arr[ukn];
    for(x=0;x<ukn-1;x++)
        arr[x]=0;
    arr[ukn-1]=sum;
    while(arr[0]!=sum)
    {   print(arr,lim,ukn);
        count++;
        for(x=ukn-1;x>=1;x--)
            if(arr[x]!=0)
                break;
            arr[x-1]++;
            arr[ukn-1]=arr[x]-1;
            if(x!=ukn-1)
                arr[x]=0;
    }
    print(arr,lim,ukn);
    count++;
    cout<<"Total solutions:"<<count<<endl;
    return 0;
}