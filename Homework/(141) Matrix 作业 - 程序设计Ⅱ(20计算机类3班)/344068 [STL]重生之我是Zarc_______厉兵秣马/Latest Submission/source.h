#include<map>
#include<vector>
#include<iostream>
using namespace std;
void nature_complete(map<string, int> &nature)
{   int x,i;
    string name;
    for(x=1;x<=7;x++)
    {   cin>>name>>i;
        nature.insert(pair<string,int>(name,i));
        
    }
    cin>>i;

}
void card_complete(vector<pair<string, int> >& card, map<string, int> &nature)
{   string t1,t2;
    int s,att,d,add,x,y;
    pair<string,int> p1;
    for(x=0;x<18;x++)
    {   cin>>t1>>s>>att>>d>>add>>t2;
        p1.first=t1;
        if(s>12||t2=="god")
            p1.second=-1000000;
        else
        {   p1.second=s+att*10+d*10+add*100000;
            if(t2=="wind"||t2=="water"||t2=="land")
                p1.second+=1;
            else if(t2=="fire")
               p1.second+=2; 
            else if(t2=="dark")  
              p1.second+=10;  
            else if(t2=="light")  
              p1.second-=1000; 
        }
        card.push_back(p1);
            

    }
    
    for(x=0;x<17;x++)
    for(y=x+1;y<18;y++)
    {   if(card[x].second<card[y].second)
        {   p1=card[x];
           card[x]=card[y];
            card[y]=p1;
        }

    }

}
bool compare(pair<string,int> a, pair<string, int> b)
{   return a.second>b.second;

}
void print(vector<pair<string, int>> ::iterator begin, vector<pair<string, int>> ::iterator end)
{      for(vector<pair<string, int>> ::iterator iter=begin;iter!=begin+4;iter++)
            cout<<(*iter).first<<endl;
}