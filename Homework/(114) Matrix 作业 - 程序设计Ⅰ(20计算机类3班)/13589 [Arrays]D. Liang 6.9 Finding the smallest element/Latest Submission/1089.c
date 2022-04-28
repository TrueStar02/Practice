int smallestElement(int array[], int size)
{   int min=*array,x;
    for(x=1;x<size;x++)
        if(array[x]<min)
            min=array[x];
    return min;

}