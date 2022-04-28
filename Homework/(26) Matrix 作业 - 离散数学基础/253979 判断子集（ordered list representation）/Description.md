# 判断子集（ordered list representation）

实现判断子集的函数：
```
bool subset(const Set & A, const Set & B);
```
如果A是B的子集，则返回true，否则返回false。


假定用有序向量（从小到大排列）表示集合：
```
typedef vector<int> Set;
```
注意，这种情况下，判断子集应该使用线性时间复杂度算法（不使用嵌套循环）。


提示：提交代码中#include "Set.h"。

