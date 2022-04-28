#include<iostream>
using namespace std;
int maxSum(int * arr,int beg,int end)
{   if(beg==end)
        return arr[beg];
    else
    {   int x,mid=(beg+end)/2;
        int left=maxSum(arr,beg,mid);
        int right=maxSum(arr,mid+1,end);
        int sum=arr[mid],max1=arr[mid],max2=arr[mid+1];
        for(x=mid-1;x>=beg;x--)
        {   sum+=arr[x];
            if(sum>max1)
                max1=sum;
        }
        sum=arr[mid+1];
        for(x=mid+2;x<=end;x++)
        {   sum+=arr[x];
            if(sum>max2)
                max2=sum;
        }
        int cross=max1+max2;
        if(left>=right&&left>=cross)
            return left;
        else if(right>=left&&right>=cross)
            return right;
        else
            return cross;
    }
}
int main()
{   int n,x;
    cin>>n;
    int arr[n],delta[n-1];
    for(x=0;x<n;x++)
        cin>>arr[x];
    for(x=0;x<n-1;x++)
        delta[x]=arr[x+1]-arr[x];
    cout<<maxSum(delta,0,n-2)<<endl;
    return 0;
}
