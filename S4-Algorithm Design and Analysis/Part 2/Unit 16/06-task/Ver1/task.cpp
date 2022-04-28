#include<iostream>
#include<algorithm>
#include<vector>
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
    for(x=0;x<n;x++)
    {   arr[x].num=x;
        cin>>arr[x].deadline>>arr[x].punishment;
        tot_p+=arr[x].punishment;
    }
    sort(arr,arr+n,[](const Task & t1,const Task & t2){return t1.punishment>t2.punishment;});
    vector<int> selected;
    bool flag;
    int index;
    for(x=0;x<n;x++)
    {   flag=1;
        index=-1;
        for(y=0;y<selected.size();y++)
        {   if(arr[selected[y]].deadline>arr[x].deadline)
            {   index=y;
                if(arr[x].deadline<y+1)
                {   flag=0;
                    break;
                }
                for(;y<selected.size();y++)
                {   if(arr[selected[y]].deadline<y+2)
                    {   flag=0;
                        break;
                    }

                }
                break;
            }

        }
        if(index==-1)
        {   if(arr[x].deadline<selected.size()+1)
                flag=0;
            else
                index=selected.size();
        }
       // cout<<flag<<" "<<index<<" ";
        if(flag)
        {   selected.insert(selected.begin()+index,x);
            tot_p-=arr[x].punishment;
        }
        for(y=0;y<selected.size();y++)
            cout<<arr[selected[y]].num<<" ";
        cout<<endl;
    }
    cout<<tot_p<<endl;
    return 0;
}