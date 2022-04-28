void bubbleSort(double arr[], int n)
{   int x,y;
    double temp;
    for(x=0;x<n-1;x++)
    for(y=x+1;y<n;y++)
    {   if(arr[x]>arr[y])
        {   temp=arr[x];
            arr[x]=arr[y];
            arr[y]=temp;
        }

    }
}