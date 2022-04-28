#include<iostream>
#include<fstream>
#include "TripleCut.h"
using namespace std;
int main()
{   int n,x;
    cin>>n;
    ifstream fin("test.txt");
    ofstream fout("result.txt");
    string arr[n];
    for(x=0;x<n;x++)
        getline(fin,arr[x]);
    MSD sorting;
    sorting(arr,n);
    for(x=0;x<n;x++)
        fout<<arr[x]<<endl;
    return 0;
}