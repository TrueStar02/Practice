#ifndef LSD_H_
#define LSD_H_
#include<iostream>
#include<cassert>
using namespace std;
bool isSorted(string * arr,int n);
class LSD
{   private:
        int len;
        int num;
        string * aux;
        int count[128];
    public:
        LSD(){}
        void operator()(string * arr,int n);
};
void LSD::operator()(string * arr,int n)
{   int x,y;
    num=n;
    aux=new string[num];
    len=arr[0].length();
    for(x=len-1;x>=0;x--)
    {   for(y=0;y<128;y++)
            count[y]=0;
        for(y=0;y<num;y++)
            count[arr[y][x]]++;
        for(y=1;y<128;y++)
            count[y]+=count[y-1];
        for(y=0;y<num;y++)
        {   aux[count[arr[y][x]-1]]=arr[y];
            count[arr[y][x]-1]++;
        }
        for(y=0;y<num;y++)
            arr[y]=aux[y];
    }
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