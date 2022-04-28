#include<iostream>
#include<fstream>
#include "RBTree.h"
using namespace std;
int main()
{   ifstream fin("test.in");
    ofstream fout("test.out");
    int n,x,number;
    string name;
    cin>>n;
    RBTree<int,string> t;
    for(x=0;x<n;x++)
    {   fin>>number>>name;
        t.insert(number,name);
        //cout<<"Insert:"<<number<<endl;
    }
    t.layer();
    cout<<endl;
    fin.seekg(0);
    for(x=0;x<n;x++)
    {   fin>>number>>name;
        t.erase(number);
        //cout<<"Erase:"<<number<<endl;
         t.layer();
        cout<<endl;
    }
    return 0;

}
