#ifndef MSD_H_
#define MSD_H_
#include<iostream>
#include<cassert>
using namespace std;
bool isSorted(string * arr,int n);
class MSD
{   private:
        int len;
        int num;
        string * aux;
        void sort(string * arr,int beg,int end,int n);
    public:
        MSD(){}
        void operator()(string * arr,int n);
};
void MSD::sort(string * arr,int beg,int end,int n)
{   int x,y;
    int count[129];
    for(x=0;x<128;x++)
        count[x+1]=0;
    for(x=beg;x<=end;x++)
        count[arr[x][n]+1]++;
    count[0]=beg;
    for(x=0;x<128;x++)
        count[x+1]+=count[x];
    for(x=beg;x<=end;x++)
    {   aux[count[arr[x][n]]]=arr[x];
        count[arr[x][n]]++;
    }
    for(x=beg;x<=end;x++)
        arr[x]=aux[x];
    for(x=0;x<128;x++)
        if(count[x]<count[x+1])
            sort(arr,count[x],count[x+1]-1,n+1);
}
void MSD::operator()(string * arr,int n)
{   num=n;
    aux=new string[num];
    sort(arr,0,n-1,0);
    delete [] aux;
    assert(isSorted(arr,num));
}
bool isSorted(string * arr,int n)
{   for(int x=1;x<n;x++)
        if(arr[x-1]>arr[x])
            return 0;
    return 1;
}
#endif