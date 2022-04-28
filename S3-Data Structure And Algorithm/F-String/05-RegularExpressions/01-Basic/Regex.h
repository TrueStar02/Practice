#ifndef REGEX_H_
#define REGEX_H_
#include<iostream>
#include<stack>
#include<vector>
#include "Digraph.h"
using namespace std;
class Regex
{   private:
        string exp;
        int len;
        Graph nfa;
        bool * label;
        bool * meaningful;
        void bitOr(bool * op);
        void clearLabel(void);
    public:
        Regex(string str);
        ~Regex(){delete [] label;delete [] meaningful;}
        bool match(const string & str);
        string showReg(void){return exp;}
        void debug(void){nfa.PrintList();for(int x=0;x<=len;x++)cout<<meaningful[x];cout<<endl;}
};
void Regex::bitOr(bool * op)
{   int x;
    for(x=0;x<=len;x++)
        label[x]|=op[x];
}
void Regex::clearLabel(void)
{   int x;
    for(x=0;x<=len;x++)
        label[x]=0;
}
Regex::Regex(string str):exp('('+str+')'),len(exp.length()),nfa(len+1)
{   label=new bool[len+1];
    meaningful=new bool[len+1];
    stack<int> st;
    stack<int> or_index;
    int x,lp;
    for(x=0;x<len;x++)
    {   lp=x;
        meaningful[x]=1;
        if(exp[x]=='\\')
        {   meaningful[x]=0;
            nfa.AddEdge(x,x+1);
            x++;
            meaningful[x]=1;
            continue;
        }
        else if(exp[x]=='('||exp[x]=='|')
            st.push(x);
        else if(exp[x]==')')
        {   while(exp[st.top()]=='|')
            {   nfa.AddEdge(st.top(),x);
                or_index.push(st.top());
                st.pop();
            }
            lp=st.top();
            while(or_index.size())
            {   nfa.AddEdge(lp,or_index.top()+1);
                or_index.pop();
            }
            st.pop();
        }
        if(x<len-1)
        {   if(exp[x+1]=='*'||exp[x+1]=='+')
                nfa.AddEdge(x+1,lp);
            if(exp[x+1]=='*'||exp[x+1]=='?')
                nfa.AddEdge(lp,x+1);
        }
        if(exp[x]=='('||exp[x]=='*'||exp[x]==')'||exp[x]=='?'||exp[x]=='+')
        {   nfa.AddEdge(x,x+1);
            meaningful[x]=0;
        }
        else if(exp[x]=='|')
            meaningful[x]=0;
    }
}
bool Regex::match(const string & str)
{   int str_len=str.length();
    int x,y;
    vector<int> vec;
    clearLabel();
    bitOr(nfa.Reachable(0));
    for(x=0;x<str_len;x++)
    {   for(y=0;y<len;y++)
            if(label[y]&&meaningful[y]&&(exp[y]==str[x]||(exp[y]=='.'&&exp[y-1]!='\\')))
                vec.push_back(y+1);
            clearLabel();
            for(y=0;y<vec.size();y++)
                bitOr(nfa.Reachable(vec[y]));
            vec.clear();
    }
   return label[len];   
}
#endif