#include<iostream>
#include<stack>
#define P 0xFFFF0000
#define Q 0xFF00FF00
#define R 0xF0F0F0F0
#define S 0xCCCCCCCC
#define T 0xAAAAAAAA
#define V 0xFFFFFFFF
using namespace std;
int main()
{	int n,x,y;
	cin>>n;
	string t;
	unsigned int temp1,temp2;
	for(x=0;x<n;x++)
	{	cin>>t;
		stack<unsigned int> st;
		for(y=0;y<t.length();y++)
		{	switch(t[y])
			{	case 'p':st.push(P);
					break;
				case 'q':st.push(Q);
					break;
				case 'r':st.push(R);
					break;
				case 's':st.push(S);
					break;
				case 't':st.push(T);
					break;
				case '~':temp1=st.top();
					st.pop();
					st.push(~temp1);
					break;
				case '*':temp1=st.top();
					st.pop();
					temp2=st.top();
					st.pop();
					st.push(temp1&temp2);
					break;
				case '+':temp1=st.top();
					st.pop();
					temp2=st.top();
					st.pop();
					st.push(temp1|temp2);
					break;
			}
		}
		if(st.top()==V)
			cout<<t<<":Yes\n";
		else
			cout<<t<<":No\n";
	}
	return 0;
}
