#include<iostream>
#include<queue>
using namespace std;
int print(void);
int main()
{   int n,x;
    cin>>n;
    for(x=0;x<n;x++)
        cout<<print()<<endl;
    return 0;
}
int print(void)
{   int tot,pos,x,input;
    queue<int> q;
    priority_queue<int> pri_q;
    cin>>tot>>pos;
    for(x=0;x<tot;x++)
    {   cin>>input;
        q.push(input);
        pri_q.push(input);
    }
    int tm=0;
    while(1)
    {   if(pri_q.top()==q.front())
        {   tm++;
            if(pos==0)
                return tm;
            pri_q.pop();
            q.pop();
            pos--;
        }
        else
        {   q.push(q.front());
            q.pop();
            if(pos==0)
                pos=q.size()-1;
            else
                pos--;
        }
    }

}