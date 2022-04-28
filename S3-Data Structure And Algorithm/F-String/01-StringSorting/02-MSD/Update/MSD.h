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
        void insertionSort(string * arr,int beg,int end,int n);
    public:
        MSD(){}
        void operator()(string * arr,int n);
};
void MSD::sort(string * arr,int beg,int end,int n)
{   if(beg+14>=end)
        insertionSort(arr,beg,end,n);
    else
    {   int low=beg,mid=beg+1,high=end;
        string temp;
        if(arr[low][n]<arr[mid][n])
        {   temp=arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
        }
        if(arr[mid][n]>arr[high][n])
        {   temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
        }
        if(arr[low][n]>arr[high][n])
        {   temp=arr[high];
            arr[high]=arr[low];
            arr[low]=temp; 
        }
        while(mid<=high)
        {   if(arr[mid][n]<arr[low][n])
            {   temp=arr[mid];
                arr[mid]=arr[low];
                arr[low]=temp;
                low++;
                mid++;
            }
            else if(arr[mid][n]==arr[low][n])
                mid++;
            else
            {   temp=arr[mid];
                arr[mid]=arr[high];
                arr[high]=temp;
                high--;
            }
        }
        sort(arr,beg,low-1,n);
        sort(arr,low,high,n+1);
        sort(arr,mid,end,n);
    }
}
void MSD::insertionSort(string * arr,int beg,int end,int n)
{   int x,y;
    string temp;
    for(x=beg+1;x<=end;x++)
    {   temp=arr[x];
        for(y=x-1;y>=beg;y--)
        {   if(arr[y].substr(n)<=temp.substr(n))
                break;
            else
                arr[y+1]=arr[y];
        }
        arr[y+1]=temp;
    }
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