# 排列后继的生成

### 问题
给定{1,2,...,n}的一个全排列，求其字典序的直接后继。
### 输入
+ 第一行是一个正整数n（&le; 9），表示全排列是{1，2，..., n}的全排列

+ 第二行是全排列的个数m(&le; 10)

+ 接下来是m个{1,...,n}的全排列，两个数字之间用空格分隔

### 输出
对应每个全排列，按照格式要求输出该排列及其直接后继（如果存在）

### 输入样例
```
3
6
1 2 3 
1 3 2
2 1 3 
3 1 2 
3 2 1
2 3 1 
```


### 输出样例
```
123<132
132<213
213<231
312<321
321
231<312
```
