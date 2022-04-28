#include<iostream>
#include<fstream>
using namespace std;
void WriteBinary(ofstream & fout,int n);
int main()
{   ifstream fin("source.txt");
    ofstream fout("target.txt");
    bool state=0;
    string text;
    fin>>text;
    int x,len=text.length(),count=0;
    for(x=0;x<len;x++)
    {   if(text[x]-48==state)
            count++;
        else
        {   WriteBinary(fout,count);
            state^=1;
            count=1;
        }
    }
    WriteBinary(fout,count);
    return 0;
}
void WriteBinary(ofstream & fout,int n)
{   while(n>15)
    {   fout<<"11110000";
        n-=15;
    }
    fout<<((n&8)>>3)<<((n&4)>>2)<<((n&2)>>1)<<(n&1);
}