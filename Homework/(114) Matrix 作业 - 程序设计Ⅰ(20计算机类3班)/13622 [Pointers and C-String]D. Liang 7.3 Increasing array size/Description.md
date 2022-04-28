# [Pointers and C-String]D. Liang 7.3 Increasing array size

#Description
7.3 Increasing array size
Once an array is created, its size is fixed. Occasionally, you need to add more values to an array, but the array is full. In this case, you may create a new larger array to replace the existing array. Write a function with the following header:
```c
int * doubleCapacity(int *list, int size)
```
The function create a new array that dobules the size of the parameter list, and copy the values in the list to the new array, the remaining value should to zero.

For example, the following codes outputs: ``1 2 3 4 5 0 0 0 0 0``
```c
int list[5]={1,2,3,4,5};
int *newlist = doubleCapacity(list,5);
for(int i=0;i<2*5;i++)
  printf("%d ", *(newlist+i));
```
#Hint
Don't submit the main() function.
