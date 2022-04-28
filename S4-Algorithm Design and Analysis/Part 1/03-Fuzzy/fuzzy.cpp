#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> Interval;
void sortFunc(vector<Interval> & arr,int beg,int end);
void Sort(vector<Interval> & arr){sortFunc(arr,0,arr.size()-1);}
Interval findPivot(vector<Interval> & arr,int beg,int end);
Interval Partition(vector<Interval> & arr,Interval pivot,int beg,int end);
int main()
{   int n,x,left,right;
    cin>>n;
    vector<Interval> arr;
    for(x=0;x<n;x++)
    {   cin>>left>>right;
        arr.push_back(Interval(left,right));
    }
    Sort(arr);
    for(x=0;x<n;x++)
        cout<<arr[x].first<<" "<<arr[x].second<<endl;
    return 0;
}
void sortFunc(vector<Interval> & arr,int beg,int end)
{   if(beg<end)
    {   Interval pivot=findPivot(arr,beg,end);
        Interval range=Partition(arr,pivot,beg,end);
        sortFunc(arr,beg,range.first-1);
        sortFunc(arr,range.second+1,end);
    }
}
Interval findPivot(vector<Interval> & arr,int beg,int end)
{   int left=arr[beg].first,right=arr[beg].second;
    int x;
    for(x=beg+1;x<=end;x++)
        if(arr[x].first<=right&&arr[x].second>=left)
        {   if(arr[x].first>left)
                left=arr[x].first;
            if(arr[x].second<right)
                right=arr[x].second;
        }
    return Interval(left,right);
}
Interval Partition(vector<Interval> & arr,Interval pivot,int beg,int end)
{   int left=beg,mid=beg,right=end;
    Interval temp;
    while(end>=mid)
    {   if(arr[mid].second>=pivot.second&&arr[mid].first<=pivot.first)
            mid++;
        else if(arr[mid].second<pivot.second)
        {   temp=arr[mid];
            arr[mid]=arr[left];
            arr[left]=temp;
            left++;
            mid++;
        }
        else
        {   temp=arr[mid];
            arr[mid]=arr[right];
            arr[right]=temp;
            right--;
        }
    }
    return Interval(left,right);
}