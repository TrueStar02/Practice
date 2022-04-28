void reverse(int array[], int size)
{   int x,temp;
    for(x=0;x<size/2;x++)
    {   temp=array[x];
        array[x]=array[size-x-1];
        array[size-x-1]=temp;
    }
}