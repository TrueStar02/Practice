#include<iostream>
#include<fstream>
using namespace std;
int main()
{   ifstream fin("target.txt");
    ofstream fout("final.txt");
    string bin_str;
    bool state=0;
    fin>>bin_str;
    int x,y,count,len=bin_str.length();
    for(x=0;x<len;x+=4)
    {   count=8*(bin_str[x]-48)+4*(bin_str[x+1]-48)+2*(bin_str[x+2]-48)+bin_str[x+3]-48;
        for(y=0;y<count;y++)
            fout<<state;
        state^=1;
    }
    return 0;
}