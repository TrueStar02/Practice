#include<iostream>
#include<fstream>
#include "Huffman.h"
using namespace std;
int main()
{   ifstream fin("target.txt");
    ofstream fout("final.txt");
    string bin_str;
    fin>>bin_str;
    Huffman tr(bin_str);
    fout<<tr.origin();
    return 0;
}