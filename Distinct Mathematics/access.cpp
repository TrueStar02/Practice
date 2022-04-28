#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
vector<string> foo(int n);
void Show(const string & t){cout<<t<<endl;}
int main(void)
{   int n;
	cin>>n;
	vector<string> solution=foo(n);
	for_each(solution.begin(),solution.end(),Show);
    return 0;
}
vector<string> foo(int n)
{	vector<string> back;
	if(n>0)
	{	vector<string> temp=foo(n-1);
		vector<string>::iterator iter;
		for(iter=temp.begin();iter!=temp.end();iter++)
		{	back.push_back("~("+(*iter)+")");
			back.push_back("p/\\("+(*iter)+")");
			back.push_back("q/\\("+(*iter)+")");
			back.push_back("r/\\("+(*iter)+")");
			back.push_back("p\\/("+(*iter)+")");
			back.push_back("q\\/("+(*iter)+")");
			back.push_back("r\\/("+(*iter)+")");
			back.push_back("p->("+(*iter)+")");
			back.push_back("q->("+(*iter)+")");
			back.push_back("r->("+(*iter)+")");
			back.push_back("p<->("+(*iter)+")");
			back.push_back("q<->("+(*iter)+")");
			back.push_back("r<->("+(*iter)+")");
			back.push_back("("+(*iter)+")/\\p");
			back.push_back("("+(*iter)+")/\\q");
			back.push_back("("+(*iter)+")/\\r");
			back.push_back("("+(*iter)+")\\/p");
			back.push_back("("+(*iter)+")\\/q");
			back.push_back("("+(*iter)+")\\/r");
			back.push_back("("+(*iter)+")->p");
			back.push_back("("+(*iter)+")->q");
			back.push_back("("+(*iter)+")->r");
			back.push_back("("+(*iter)+")<->p");
			back.push_back("("+(*iter)+")<->q");
			back.push_back("("+(*iter)+")<->r");
		}
	}
	else
	{	back.push_back("p");
		back.push_back("q");
		back.push_back("r");
	}
	return back;
}
