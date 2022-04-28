# Set Intersection (ordered list representation)

Assume that a set is represented by an ordered vector: 
```
typedef int T;
typedef vector<T> Set;
```
Implement the following set operation:
```
Set setIntersection(const Set &A, const Set &B)；
```
/*
*Assume that A and B are sets , which are  integers of increasing order,  it returns the intersection of A and B .
For example, A = (2,3,5,12), B = (3,5,8,9), then the result returned is (3,5).
**/

注意：应该使用线性时间复杂度算法（不用嵌套循环）。