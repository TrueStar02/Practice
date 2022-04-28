int * doubleCapacity(int *list, int size)
{   int *ptr;
    ptr=(int *)malloc(size*2*sizeof(int));
    memcpy(ptr,list,size*sizeof(int));
    for(int x=size;x<size*2;x++)
        *(ptr+x)=0;
    return ptr;
}