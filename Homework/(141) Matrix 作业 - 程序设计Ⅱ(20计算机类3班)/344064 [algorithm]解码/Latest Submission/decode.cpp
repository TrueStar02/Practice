#include<iostream>
using namespace std;
int main()
{   string t;
    size_t pos1,pos2;
    int x,y,num;
    char temp;
    while(cin>>t&&t!="x")
    {   while((pos1=t.find_first_of("0123456789"))!=string::npos)
        {   num=0;
            pos2=t.find_first_not_of("0123456789",pos1);
            if(pos2==string::npos)
                pos2=t.length();
            for(x=pos2-1,y=1;x>=pos1;x--,y*=10)
               num+=(t[x]-48)*y;
            temp=t[pos1-1];
            t.erase(t.begin()+pos1-1,t.begin()+pos2);
            
            t.insert(t.begin()+pos1-1,num,temp);
        }
        cout<<t<<endl;
    }

}