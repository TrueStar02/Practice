int *sort(const int * const array, int size)
{   int *ptr=(int *)malloc(size*sizeof(int));
    int x,y,temp;
    for(x=0;x<size;x++)
        ptr[x]=array[x];
    for(x=0;x<size-1;x++)
    for(y=x+1;y<size;y++)
        if(ptr[x]>ptr[y])
        {   temp=ptr[x];
            ptr[x]=ptr[y];
            ptr[y]=temp;
        }
    return ptr;
}