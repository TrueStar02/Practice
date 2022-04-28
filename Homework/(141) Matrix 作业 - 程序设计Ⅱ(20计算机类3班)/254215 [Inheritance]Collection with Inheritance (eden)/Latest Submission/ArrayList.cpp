#include "ArrayList.hpp"
int Partition(int * arr,int beg,int end);
void QuickSort(int *arr,int beg,int end);
ArrayList::ArrayList()
{   _size=0;
    _maxsize=1;
    storage=new E[1];
}
ArrayList::~ArrayList(){delete [] storage;}
void ArrayList::add(E e)
{   if(_size==_maxsize)
        extend();
    storage[_size]=e;
    _size++;
}
void ArrayList::clear(void){_size=0;}
bool ArrayList::contain(E e)
{   int x;
    for(x=0;x<_size;x++)
        if(storage[x]==e)
            return 1;
    return 0;
}
bool ArrayList::isEmpty(void){return !_size;}
void ArrayList::remove(E e)
{   int x;
    int count=0;
    for(x=0;x<_size;x++)
    {   storage[x-count]=storage[x];
        if(storage[x]==e)
            count++;
    }
    _size-=count;
}
E& ArrayList::operator[](int index){return storage[index];}
E& ArrayList::get(int index){return storage[index];}
int ArrayList::indexOf(E element)
{   int x;
    for(x=0;x<_size;x++)
        if(storage[x]==element)
            return x;
    return -1;
}
void ArrayList::sort(void){ 
    QuickSort(storage,0,_size-1);
}
int ArrayList::size(void){return _size;}
void ArrayList::extend(void)
{   E * ptr=new E[_maxsize*2];
    int x;
    for(x=0;x<_size;x++)
        ptr[x]=storage[x];
    delete [] storage;
    _maxsize*=2;
    storage=ptr;

}
int Partition(int * arr,int beg,int end)
{   
    int temp;
    if(arr[beg]<arr[beg+1])
    {   temp=arr[beg+1];
        arr[beg+1]=arr[beg];
        arr[beg]=temp;
    }
    if(arr[end]<arr[beg+1])
    {   temp=arr[beg+1];
        arr[beg+1]=arr[end];
        arr[end]=temp;
    }
    if(arr[beg]>arr[end])
    {   temp=arr[end];
        arr[end]=arr[beg];
        arr[beg]=temp;
    }
    temp=arr[beg];
    while(beg<end)
    {   while(arr[end]>=temp&&beg<end)
            end--;
        arr[beg]=arr[end];
        while(arr[beg]<=temp&&beg<end)
            beg++;
        arr[end]=arr[beg];
    }
    arr[beg]=temp;
    return beg;
}
void QuickSort(int *arr,int beg,int end)
{   if(beg<end)
    {   int pivot=Partition(arr,beg,end);
        QuickSort(arr,beg,pivot-1);
        QuickSort(arr,pivot+1,end);
    }
}