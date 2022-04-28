#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
bool isValidProp(string s);
int main(void)
{	string t;
	cin>>t;
	cout<<isValidProp(t);
	return 0;
}
bool isValidProp(string s)
{	int x;
	int left=0,right=0;
	stack<bool> prop;
	stack<bool> link;
	for(x=0;x<s.length();x++)
	{	if(isalpha(s[x]))
			prop.push(1);
		else if(s[x]=='~')
		{	if(s[x-1]!='(')
				return 0;
			link.push(0);
		}
		else if(s[x]=='(')
			left++;
		else if(s[x]==')')
		{	right++;
			if(!isalpha(s[x-1])&&s[x-1]!=')')
				return 0;
			else 
			{	if(prop.empty())
					return 0;
				if(link.top())
				{	prop.pop();
					if(prop.empty())
						return 0;
				}
				link.pop();
			}
		}
		else if((s[x]=='\\'&&s[x+1]=='/'||s[x]=='/'&&s[x+1]=='\\'||s[x]=='-'&&s[x+1]=='>')&&(s[x-1]==')'||isalpha(s[x-1])))
		{	x++;
			link.push(1);
		}
		else if((s[x]=='<'&&s[x+1]=='-'&&s[x+2]=='>')&&(s[x-1]==')'||isalpha(s[x-1])))
		{	x+=2;
			link.push(1);
		}
		else
			return 0;
	}
	if(left==right&&link.empty()&&prop.size()==1)
		return 1;
	return 0;
}
