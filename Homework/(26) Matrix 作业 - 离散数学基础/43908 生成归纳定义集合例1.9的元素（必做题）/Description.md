# 生成归纳定义集合例1.9的元素（必做题）

### 问题
试编写函数，生成归纳定义集合例1.9的元素。

### 输入
一个正整数n，表示使用规则次数
### 输出
打印使用n次规则生成的元素，并按照字典序排列。每个元素占一行。

### 测试样例输入
```
3
```

### 测试样例输出
```
00000
00100
01010
01110
10001
10101
11011
11111
```

提示：
1. 建议编写使用n次规则生成元素的函数，例如，
```
vector<string> genElements(int n);
```
2. 请勿将所有代码堆砌到main函数中。

3. 关于C++类型string, 请参考[string](http://cplusplus.com/reference/string/)。

***警示：先写一个伪代码算法，然后再实现。你必须用一个独立的函数实现核心算法！***