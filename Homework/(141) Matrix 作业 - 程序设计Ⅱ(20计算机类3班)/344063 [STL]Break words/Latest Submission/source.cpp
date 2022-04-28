#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool handler(const string & t1,const string & t2)
{return t1.length()>t2.length();}
int main()
{   vector<string> dic;
    int n,x,y;
    cin>>n;
    string t;
    for(x=0;x<n;x++)
    {   cin>>t;  
        dic.push_back(t);
    }
    sort(dic.begin(),dic.end(),handler);
    
    for(x=48;x<58;x++)
    dic.push_back(string(1,char(x)));
    for(x=97;x<97+26;x++)
    dic.push_back(string(1,char(x)));
    cin>>t;
    int pos;
    for(x=0;x<t.length();x++)
    {   for(y=0;y<dic.size();y++)
        {	pos=t.find(dic[y],x);
		 if(pos==x)
            {   t.insert(t.begin()+pos+dic[y].length(),' ');
                x=pos+dic[y].length();
				break;
            }
		}
    }
    cout<<t;
}