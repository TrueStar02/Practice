#include "array.hpp"
 typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;
array::array(size_t size)
{   _data=new int[size];
    _size=size;
}
  
  array::~array()
  {
      delete [] _data;
  }
  // Capacity
  // Return maximum size
  size_t array::max_size(void)
  {
      return _size;
  }
 
  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
  data_type& array::at(const data_type& i)
  {
      return _data[i];
  }
  // Access first element
  data_type& array::front(){return _data[0];}
  // Access last element
  data_type& array::back(){return _data[_size-1];}
  // Get pointer to data
  pointer array::data(){return _data;}
  void array::fill(const data_type& value)
  {
      for(int x=0;x<_size;x++)
        _data[x]=value;
  }
  // Resize the array (newSize > oldSize)
  void array::resize(int newSize)
  {
      int *ptr=new int[newSize];
      for(int x=0;x<_size;x++)
        ptr[x]=_data[x];
        delete [] _data;
        _data=ptr;
        _size=newSize;
  }
  // Sort the array in the section [from, to)
  void array::sort(int from, int to)
  {     int temp;
      for(int x=from;x<to-1;x++)
      for(int y=x+1;y<=to-1;y++)
        if(_data[x]>_data[y])
        {   temp=_data[x];
            _data[x]=_data[y];
           _data[y]=temp;
        }
  }