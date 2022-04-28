
template<typename T>
int find_lower_bound(T * arr,int size,T val)
{   int i=-1;
    T temp;
    bool p=0;
    int x;
    for(x=0;x<size;x++)
    {   if(arr[x]<val&&(!p||temp<arr[x]))
        {    i=x;
            temp=arr[x];
            p=1;
        }

    }
    return i;
}
