int binarySearch(int array[], int key, int size)
{   int x,index=-1;
    for(x=0;x<size;x++)
        if(array[x]==key)
        {   index=x;
            break;

        }
    return index;
}