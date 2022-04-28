#include<iostream>
#include<fstream>
#include "TripleST.h"
using namespace std;
void PrintDictionary(const Dictionary & dic);
int main()
{   TripleST<int> tr;
    int x;
    /*tr.insert("she",1);
    tr.insert("sells",2);
    tr.insert("sea",3);
    tr.insert("shells",4);
    tr.insert("by",5);
    tr.insert("the",6);
    tr.insert("sea",7);
    tr.insert("shore",8);
    tr.debug();
    Dictionary dic=tr.allKeys();
    PrintDictionary(dic);
    Dictionary dic2=tr.keyMatch("..e");
    PrintDictionary(dic2);
    cout<<tr.longestPrefix("seashells")<<endl;
    cout<<tr.rank("shells")<<endl;
    cout<<tr.rank("seafood")<<endl;
    for(x=0;x<7;x++)
        cout<<tr.select(x)<<endl;
    cout<<tr.floor("sea")<<endl;
    cout<<tr.floor("shellsort")<<endl;
    cout<<tr.floor("ass")<<endl;
    cout<<tr.floor("this")<<endl;
    cout<<tr.ceiling("zebra")<<endl;
    cout<<tr.ceiling("those")<<endl;
    cout<<tr.ceiling("alpha")<<endl;
    cout<<tr.ceiling("sell")<<endl;
    cout<<tr.ceiling("shells")<<endl;
    cout<<tr.ceiling("shellsort")<<endl;
    tr.erase("sea");
    tr.erase("she");
    tr.erase("she");
    tr.debug();
    tr.erase("shells");
    tr.debug();
    tr.erase("sells");
    tr.erase("sea");
    tr.clear();*/
    ifstream fin("test.txt");
    cout<<"Test 2:";
    int num;
    cin>>num;
    string str;
    for(x=0;x<num;x++)
    {   fin>>str;
        tr.insert(str,x);
    }
    //tr.debug();
    fin.seekg(0);
    for(x=0;x<num/2;x++)
    {   fin>>str>>str;
        tr.erase(str);
    }
    tr.debug();
    tr.clear();

    return 0;
}
void PrintDictionary(const Dictionary & dic)
{   int x,size=dic.size();
    for(x=0;x<size;x++)
        cout<<dic[x]<<endl;

}