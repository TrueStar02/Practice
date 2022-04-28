#include<iostream>
using namespace std;
int main()
{   int r,c,x,y;
    cin>>r>>c;
    int arr[r][c];
    for(x=0;x<r;x++)
    for(y=0;y<c;y++)
        cin>>arr[x][y];
    for(x=0;x<r;x++)
    {   for(y=0;y<c;y++)
            cout<<arr[x][y]<<" ";
        cout<<endl;
    }
    return 0;
}