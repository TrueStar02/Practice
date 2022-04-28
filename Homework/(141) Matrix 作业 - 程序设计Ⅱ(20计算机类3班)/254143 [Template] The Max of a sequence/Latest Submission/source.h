#include<cstring>
template<typename T>
T max(T* arr,int n)
{   int x;
    T maxi=arr[0];
    for(x=1;x<n;x++)
        if(arr[x]>maxi)
            maxi=arr[x];
    return maxi;
} 