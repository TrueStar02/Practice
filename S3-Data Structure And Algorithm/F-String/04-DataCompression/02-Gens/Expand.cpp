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
    for(x=0;x<len;x+=2)
    {   count=2*(bin_str[x]-48)+(bin_str[x+1]-48);
        switch(count)   
        {   case 0:fout<<'A';
                break;
            case 1:fout<<'G';
                break;
            case 2:fout<<'C';
                break;
            case 3:fout<<'T';
                break;
        }
    }
    return 0;
}