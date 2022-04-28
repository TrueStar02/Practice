#include<iostream>
#include<fstream>
#include "TripleST.h"
using namespace std;
string getAllInput(ifstream & fin);
void initTree(TripleST<int> & tr);
string to12Bit(int n);
int main()
{   ifstream fin("source.txt");
    ofstream fout("target.txt");
    string input=getAllInput(fin);
    TripleST<int> tr;
    int count=257;
    initTree(tr);
    string pre;
    while(input.length())
    {   pre=tr.longestPrefix(input);
        fout<<to12Bit(tr[pre]);
        if(count<4096&&pre.length()<input.length())
        {   tr.insert(input.substr(0,pre.length()+1),count);
            count++;
        }
        input=input.substr(pre.length());
    }
    return 0;
}
string getAllInput(ifstream & fin)
{   string all,input;
    while(getline(fin,input)&&!fin.eof())
    {   all+=input;
        all+='\n';
    }
    return all;
}   
void initTree(TripleST<int> & tr)
{   int step,x;
    tr.insert(string(1,char(64)),64);
    for(step=32;step>=1;step/=2)
        for(x=step;x<128;x+=step*2)
            tr.insert(string(1,char(x)),x);
}
string to12Bit(int n)
{   string str="            ";
    for(int x=11;x>=0;x--)
    {   str[x]=(n&1)+48;
        n>>=1;
    }
    return str;
}