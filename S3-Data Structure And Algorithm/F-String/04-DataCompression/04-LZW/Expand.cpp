#include<iostream>
#include<fstream>
using namespace std;
int main()
{   ifstream fin("target.txt");
    ofstream fout("final.txt");
    string bin_str;
    fin>>bin_str;
    string table[4096],temp;
    int x,y,z,count=257,data;
    for(x=0;x<128;x++)
        table[x]=string(1,char(x));
    data=0;
    for(y=11,z=1;y>=0;y--,z*=2)
        data+=(bin_str[y]-48)*z;
    int len=bin_str.length();
    for(x=0;x<len;x+=12)
    {   temp=table[data];
        fout<<temp;
        if(x+12<len)
        {   data=0;
            for(y=11,z=1;y>=0;y--,z*=2)
                data+=(bin_str[x+y+12]-48)*z;        
            if(count<4096)
            {   if(table[data]!="")
                    table[count]=temp+table[data][0];
                else
                    table[count]=temp+temp[0];
                count++;
            }
        }
    }
    return 0;
}