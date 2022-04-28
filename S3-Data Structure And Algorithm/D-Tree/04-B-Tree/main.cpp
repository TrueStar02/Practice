#include<iostream>
#include<fstream>
#include "BTree.h"
using namespace std;
int main()
{   ifstream fin("test.in");
    ofstream fout("test.out");
    int n,x,number;
    string name;
    cin>>n;
    BTree<int,string,15> t0;
    for(x=0;x<n;x++)
    {   fin>>number>>name;
        t0.insert(number,name);
        cout<<endl<<x+1<<" "<<number<<endl;
        
    }
    BTree<int,string,15> t(t0);
    t0.layer();
    cout<<endl;
    fin.seekg(0);
    for(x=0;x<n;x++)
    {   fin>>number>>name;
        t.erase(number);
            
           cout<<endl<<x+1<<" Erase:"<<number<<endl;
             //t.layer();
        
        // cout<<x<<" ";
        //cout<<endl;
    }
    //t.erase(number);
    return 0;

}