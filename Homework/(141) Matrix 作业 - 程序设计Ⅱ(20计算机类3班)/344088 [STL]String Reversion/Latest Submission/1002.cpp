#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{   string t;
    int n,x,y;
    cin>>n;
    stack<char> st;
    for(x=1;x<=n;x++)
    {   cin>>t;
        for(y=0;y<t.length();y++)
        {   switch(t[y])
            {case '_':while(st.size())
                {   cout<<st.top(); 
                    st.pop();
                }
                cout<<'_';
                break;
            default:
                st.push(t[y]);
                break;
            }
        }
        while(st.size())
        {   cout<<st.top(); 
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}