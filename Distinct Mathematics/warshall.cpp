#include<iostream>
using namespace std;
int main()
{   int n,x,y,z,m,i,j;
    cin>>n;
    bool mat[n][n];
    for(x=0;x<n;x++)
    for(y=0;y<n;y++)
        cin>>mat[x][y];
    for(z=0;z<n;z++)
    for(x=0;x<n;x++)
    for(y=0;y<n;y++)
        mat[x][y]|=(mat[x][z]&mat[z][y]);
    cin>>m;
    for(x=0;x<m;x++)
    {   cin>>i>>j;
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
    return 0;
}