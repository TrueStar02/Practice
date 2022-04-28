#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool Next(vector<int> & v)
{	int size=v.size();
	int i=size-2;
	int temp;
	while(i>=0&&v[i]>v[i+1])i--;
	if(i<0)return 0;
	int j=size-1;
	while(v[i]>v[j])j--;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
	int r=size-1;
	int s=i+1;
	while(r>s)
	{	temp=v[r];
		v[r]=v[s];
		v[s]=temp;
		r--;
		s++;		
	}
	return 1;	
}
int main()
{  int n,m,x,y,i;
	cin>>n>>m;
	for(x=1;x<=m;x++)
	{	vector<int> s;
		for(y=0;y<n;y++)
		{	cin>>i;
			s.push_back(i);
			cout<<i;
		}	
		if(Next(s))	
		{
				cout<<"<";
			for(y=0;y<n;y++)
			cout<<s[y];
		}
		cout<<endl;
	}
	
}