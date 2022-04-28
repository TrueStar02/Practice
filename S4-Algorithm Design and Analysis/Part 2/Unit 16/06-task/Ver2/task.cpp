#include<iostream>
#include<algorithm>
#include<vector>
#include "unionfind.h"
using namespace std;
struct Task
{   int num;
    int deadline;
    int punishment;
};
int main()
{   int x,y,n;
    cin>>n;
    Task arr[n];
    int tot_p=0;
    int timeLine[n];
    for(x=0;x<n;x++)
    {   arr[x].num=x;
        timeLine[x]=-1;
        cin>>arr[x].deadline>>arr[x].punishment;
        tot_p+=arr[x].punishment;
    }
    sort(arr,arr+n,[](const Task & t1,const Task & t2){return t1.punishment>t2.punishment;});
    UnionFind uf(n);
    Interval temp;
    int changed;
    for(x=0;x<n;x++)
    {   if(timeLine[arr[x].deadline-1]==-1)
        {   changed=x;
            timeLine[arr[x].deadline-1]=x;
            tot_p-=arr[x].punishment;
            //cout<<"a ";
        }    
        else
        {   temp=uf.getRange(arr[x].deadline-1);
            if(temp.begin>0)
            {   timeLine[temp.begin-1]=x;
                changed=temp.begin-1;
                tot_p-=arr[x].punishment;
                //cout<<"b ";
            }    
            else
            {   if(timeLine[n-1]==-1)
                {   changed=n-1;
                    timeLine[n-1]=x;
                    //cout<<"c ";
                }
                else
                {   
                    temp=uf.getRange(n-1);
                    changed=temp.begin-1;
                    timeLine[temp.begin-1]=x;
                    //cout<<"d ";
                }

            }
        }
        if(changed>0&&timeLine[changed-1]!=-1)
            uf.Union(changed-1,changed);
        if(changed<n-1&&timeLine[changed+1]!=-1)
            uf.Union(changed,changed+1);
       
    }
    cout<<tot_p<<endl;
    for(y=0;y<n;y++)
        cout<<timeLine[y]<<" ";
    cout<<endl; 
    return 0;
}