# 计算幂集

### 任务

给定集合，计算其所有子集：
```
vector<Set> powerset(const Set &S);
```

本题无需提交，可以自己测试。例如，使用下面的打印函数查看输出的子集是否正确：
```
//print a given set A.
void print(string s, const Set & A){
    cout <<s<<"{";
    for (size_t i=0;i<A.size();i++){
         if (i != A.size()-1)
             cout << A[i] <<",";
         else
            cout<<A[i];
    }
    cout<< "}"<< endl;
}
//print all the subsets of a give set S.
void printSubsets(const Set &S){
    vector<Set> p = powerset(S);
    print("Set:", S);
    cout << "subsets:"<<endl;
    for (size_t i=0; i< p.size(); i++)
       print("",p[i]);  
}
```
如果您使用教材上给出的算法计算所有子集，对于给定集合S={1,2,3}，printSubsct(S)的结果可能是这样的：
```
Set:{1,2,3}
subsets:
{}
{3}
{2}
{2,3}
{1}
{1,3}
{1,2}
{1,2,3}
```
 
 您不妨对算法稍加修改，对于给定集合S={1,2,3}，printSubsct(S)的结果可能是这样的
 ```
 Set:{1,2,3}
subsets:
{}
{1}
{2}
{1,2}
{3}
{1,3}
{2,3}
{1,2,3}
 ```
 
 当然，您可能会想到使用递归，that is great!