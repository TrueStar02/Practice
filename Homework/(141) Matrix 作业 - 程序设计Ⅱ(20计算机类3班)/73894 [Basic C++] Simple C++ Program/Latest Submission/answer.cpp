#include<iostream>
#include<cmath>
using namespace std;
int main()
{   int a,b;
    double da,db;
    string str[10];
    cin>>a>>b>>da>>db;
    cin.get();
    int x;
    for(x=0;x<10;x++)
        getline(cin,str[x]);
    cout<<pow(a,b)<<endl;
    cout<<da*db<<endl;
    for(x=9;x>=0;x--)
        cout<<str[x]<<endl;
}