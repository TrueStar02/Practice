#include<iostream>
#include<vector>
using namespace std;
struct Node
{   int weight;
    int dp;
    int mode;
    vector<int> child;
    Node(int w,vector<int> && v):weight(w),child(v),dp(0),mode(0){}
};
typedef vector<Node> Tree;
void best(Tree & tree,int index);
void print(Tree & tree,int index);
int main()
{   int n,x,y,s,w,c;
    cin>>n;
    Tree tree;
    for(x=0;x<n;x++)
    {   vector<int> v;
        cin>>w>>s;
        for(y=0;y<s;y++)
        {   cin>>c;
            v.push_back(c);
        }       
        tree.push_back(Node(w,move(v)));
    }
    best(tree,0);
    cout<<tree[0].dp<<endl;
    print(tree,0);
    cout<<endl;
    return 0;
}
void best(Tree & tree,int index)
{   int x,y,i1,i2;
    for(x=0;x<tree[index].child.size();x++)
        best(tree,tree[index].child[x]);
    int sum1=0,sum2=tree[index].weight>0?tree[index].weight:0;
    for(x=0;x<tree[index].child.size();x++)
    {   i1=tree[index].child[x];
        sum1+=tree[i1].dp;
        for(y=0;y<tree[i1].child.size();y++)
        {   i2= tree[i1].child[y];
            sum2+=tree[i2].dp;
        }
    }
    if(sum1>sum2)
    {   tree[index].mode=1;
        tree[index].dp=sum1;
    }    
    else
    {   tree[index].mode=2;
        tree[index].dp=sum2;
    }
}
void print(Tree & tree,int index)
{   int x,y,i1,i2;
    if(tree[index].weight>0&&tree[index].mode==2)
        cout<<index<<" ";
    for(x=0;x<tree[index].child.size();x++)
    {   i1=tree[index].child[x];
        if(tree[index].mode==1)
            print(tree,i1);
        else
        {   for(y=0;y<tree[i1].child.size();y++)
            {   i2= tree[i1].child[y];
                print(tree,i2);
            }
        }
    }
}