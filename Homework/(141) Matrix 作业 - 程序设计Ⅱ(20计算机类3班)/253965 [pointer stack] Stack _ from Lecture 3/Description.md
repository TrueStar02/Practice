# [pointer stack] Stack _ from Lecture 3

## description
```
构建使用指针构建动态堆栈。
已知每一个数据节点的结构体：
typedef int ELEMENT;  // 为堆栈元素类型起一个别名
struct NODE {
     ELEMENT element;	// 存放堆栈的元素
     NODE* link;		// 指向下一个结点的链接
};
类声明：
class STACK {
public:
     STACK();   // 构造函数，设置栈顶为空指针
     ~STACK(); // 析构函数，释放堆栈结点占用的存储空间
	
     void push(ELEMENT obj);  // 将元素obj压入栈顶
     void pop();  // 将当前栈顶的元素弹出栈中。要求：栈不为空。
     ELEMENT get_top();  // 返回当前栈顶的元素值。要求：栈不为空。
     int is_empty();  // 判断当前堆栈是否为空，空则返回1，非空则返回0
     void display();  // 自顶向下显示堆栈中的元素

private:
    NODE* top;	// 堆栈的栈顶
};
```
```
输出格式为：
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
1 20
2 19
3 18
4 17
5 16
6 15
7 14
8 13
9 12
10 11
11 10
12 9
13 8
14 7
15 6
16 5
17 4
18 3
19 2
20 1

```