# [C] 二叉树链表实现

## Descrption
使用链表实现二叉树的构造并完成中序遍历。

首先在头文件中定义结点结构体如下：
```
typedef struct node {
  int x;
  struct node* left;
  struct node* right;
} BN;
```
其次要实现两个函数，函数buildTree通过读入一串整数以层次优先从左到右的方式构建一个二叉树，函数outputTree输出此树的中序遍历。两个函数的原型
如下：

void buildTree(BN** rootptr);

void outputTree(BN* root);

输入：N个正整数，1<=N<=30，以空格间隔，以-1结束。注意-1不包含在此树的结构中，只是作为输入结束的符号。

输出：一行按照中序遍历排列的正整数，以空格间隔，最后一个输出的元素后仍然有空格，且没有换行

注意：main函数已经给出，并且在其中给出了树的根节点的指针以及整棵树free的过程，buildTree函数内所有的结点应以malloc形式生成，如果一个结
点没有左儿子或者右儿子，则相应的指针应该等于NULL。



## Sample Input
```
1 2 3 4 5 6 7 8 9 -1

```
## Sample Output
```
8 4 9 2 5 1 6 3 7
```

*From : 贾亚晖*
