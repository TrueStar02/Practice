int smallestElementIndex(int array[], int size)
{   int min=*array,index=0,x;
    for(x=1;x<size;x++)
        if(array[x]<min)
        {  min=array[x];
            index=x;
        }
    return index;

}