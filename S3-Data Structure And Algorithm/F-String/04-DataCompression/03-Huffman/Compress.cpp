#include<iostream>
#include<fstream>
#include "Huffman.h"
using namespace std;
int * countFrequency(ifstream & fin);
void showTable(const string * table);
void Compress(ifstream & fin,ofstream & fout,string * table);
int main()
{   ifstream fin("source.txt");
    ofstream fout("target.txt");
    int * fre=countFrequency(fin);
    Huffman tr(fre);
    string * table=tr.compressTable();
    showTable(table);
    tr.writeTree(fout);
    Compress(fin,fout,table);
    delete [] fre;
    return 0;
}
int * countFrequency(ifstream & fin)
{   char ch;
    int x;
    int * fre=new int[128];
    for(x=0;x<128;x++)
        fre[x]=0;
    while((ch=fin.get())!=EOF)
        fre[ch]++;
    fin.clear();
    fin.seekg(0);
    return fre;
}
void showTable(const string * table)
{   int x;
    for(x=0;x<128;x++)
    {   if(table[x]!="")
            cout<<char(x)<<" "<<table[x]<<endl;
    }
}
void Compress(ifstream & fin,ofstream & fout,string * table)
{   char ch;
    while((ch=fin.get())!=EOF)
        fout<<table[ch];
}
