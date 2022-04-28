#include<iostream>
#include<fstream>
#include "AVLTree.h"
using namespace std;
int main()
{   ifstream fin("test.in");
    ofstream fout("test.out");
    int n,x,number;
    string name;
    cin>>n;
    AVLTree<int,string> t0;
    for(x=0;x<n;x++)
    {   fin>>number>>name;
        t0.insert(number,name);
        //cout<<"Insert:"<<number<<endl;
    }
    AVLTree<int,string> t(t0);
    //t0.layer();
    cout<<endl;
    fin.seekg(0);
    for(x=0;x<n;x++)
    {   fin>>number>>name;
        t.erase(number);
        
           // t.layer();
        //cout<<"Erase:"<<number<<endl;
         cout<<x<<" ";
        cout<<endl;
    }
    return 0;

}
