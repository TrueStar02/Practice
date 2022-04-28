#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Task
{   int num;
    int relax;
    int time;
};
struct compTime
{
    bool operator()(const Task & t1,const Task & t2){return t1.time>t2.time;}
};
int main()
{   priority_queue<Task,vector<Task>,compTime> pq; 
    int n,x;
    cin>>n;
    Task arr[n];
    for(x=0;x<n;x++)
    {   arr[x].num=x;
        cin>>arr[x].relax>>arr[x].time;
    }
    Task temp;
    sort(arr,arr+n,[](const Task & t1,const Task & t2){return t1.relax<t2.relax;});
    int t=0,sum=0;
    x=0;
    while(pq.size()||x<n)
    {   t++;
        while(x<n&&arr[x].relax==t)
        {   pq.push(arr[x]);
            x++;
        }
        if(pq.size())
        {   temp=pq.top();
            temp.time--;
            pq.pop();
            if(temp.time)
                pq.push(temp);
            else
                sum+=t;
            cout<<temp.num<<" ";
            
        }
    }
    cout<<endl<<sum<<endl;
}