# 计算度数序列（邻接表表示）

### 任务一
假设无向图用邻接表表示。请实现下列返回无向图度数序列(degree sequence)的函数：
```
vector<int> degreeSequence(const ALGraph &g);
```
这里ALGraph是你定义的邻接表表示。

注：The degree sequence of an undirected graph is the non-increasing sequence of its vertex degrees. 
### 任务二

定义一个构造给定图邻接表表示的函数：
```
ALGraph mkGraph();
```
函数将读取如下格式的标准输入，并返回所构造的对象：
第一行是图的结点数n和边数m，然后是m对结点。假定n个结点分别用0,1，..., n-1表示。例如，3个结点的完全图：
```
3 3
0 1
0 2
1 2
```
再比如，下面是4个结点3个边的图:
```
4 3
0 1
0 2
1 2
```

### 任务三
利用前面的函数，完成下面测试：
测试包含多个样例，第一行是测试样例数，即简单无向图的个数k，接下来是k个图，每个图用前面的格式给出。比如，下面是两个测试样例：

```
2
3 3
0 1
0 2
1 2

4 3
0 1
0 2
1 2
```
对于每个测试样例，构造该图，然后调用度数序列函数，并打印度数序列，每个度数序列占一行，每个度数后留一个空格（包括最后一个度数）。例如，前面测试样例的输出是：
```
2 2 2 
2 2 2 0 
```

