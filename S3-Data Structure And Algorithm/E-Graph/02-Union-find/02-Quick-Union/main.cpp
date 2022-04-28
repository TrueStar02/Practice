#include<iostream>
#include<fstream>
#include "unionfind.h"
using namespace std;
int main()
{   int nodes,edges,cases;
    ifstream fin("test.txt");
    fin>>nodes>>edges>>cases;
    UnionFind uf(nodes);
    int a,b,x;
    for(x=0;x<edges;x++)
    {   fin>>a>>b;
        uf.Union(a,b);
    }
    for(x=0;x<cases;x++)
    {   fin>>a>>b;
        cout<<uf.isConnected(a,b);
    }
    return 0;
}