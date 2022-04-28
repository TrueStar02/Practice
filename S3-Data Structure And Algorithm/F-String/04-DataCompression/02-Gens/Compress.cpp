#include<iostream>
#include<fstream>
using namespace std;
void WriteBinary(ofstream & fout,int n);
int main()
{   ifstream fin("source.txt");
    ofstream fout("target.txt");
    string text;
    fin>>text;
    int x,len=text.length(),count=0;
    for(x=0;x<len;x++)
    {   switch(text[x])
        {   case 'A':fout<<"00";
                break;
            case 'G':fout<<"01";
                break;
            case 'C':fout<<"10";
                break;
            case 'T':fout<<"11";
                break;    
            default:
                throw "Invalid Input!";
        }
    }
    return 0;
}
