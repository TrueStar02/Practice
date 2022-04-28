#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
struct IDList
{   int id;
    list<int> l;
    IDList(int i):id(i){}
};
int main()
{   int n,x,m1,m2,y,z;
    cin>>n;
    string op;
    vector<IDList> v;
    for(x=0;x<n;x++)
    {   cin>>op;
        if(op=="new")
        {   cin>>m1;
            v.push_back(IDList(m1));
        }
        else if(op=="add")
        {   cin>>m1>>m2;
            for(y=0;y<v.size();y++)
                if(v[y].id==m1)
                {   v[y].l.push_back(m2);
                    break;
                }
        }
        else if(op=="merge")
        {   cin>>m1>>m2;
            int index1,index2;
            for(y=0;y<v.size();y++)
            {   if(v[y].id==m1)
                    index1=y;
                else if(v[y].id==m2)
                    index2=y;
            }
            v[index1].l.sort();
            v[index2].l.sort();
            v[index1].l.merge(v[index2].l);
            v[index2].l.clear();
        }
        else if(op=="out")
        {   cin>>m1;
            for(y=0;y<v.size();y++)
                if(v[y].id==m1)
                {   v[y].l.sort();
                    copy(v[y].l.begin(),v[y].l.end(),ostream_iterator<int,char> (cout," "));
                    cout<<endl;
                    break;
                }
        }
        else if(op=="unique")
        {   cin>>m1;
            for(y=0;y<v.size();y++)
                if(v[y].id==m1)
                {   v[y].l.unique();
                    break;
                }

        }
    }

}