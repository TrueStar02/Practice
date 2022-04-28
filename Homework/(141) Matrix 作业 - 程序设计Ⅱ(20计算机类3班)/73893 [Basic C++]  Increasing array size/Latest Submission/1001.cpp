int * doubleCapacity(int *list, int size)
{   int *nptr=new int[size*2],x;
    for(x=0;x<size;x++)
     {   nptr[x]=list[x];
        nptr[size+x]=0;
     }
     return nptr;
}