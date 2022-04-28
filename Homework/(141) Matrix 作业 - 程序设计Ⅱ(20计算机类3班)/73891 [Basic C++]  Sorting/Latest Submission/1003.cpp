int *sort(const int * const array, int size)
{   int *nptr=new int[size];
    int x,y,temp;
    for(x=0;x<size;x++)
    nptr[x]=array[x];
    for(x=0;x<size-1;x++)
    for(y=x+1;y<size;y++)
        if(nptr[x]>nptr[y])
        {   temp=nptr[x];
            nptr[x]=nptr[y];
            nptr[y]=temp;
        }
    return nptr;
}