# 栈的实现

# Description
实现栈的各个操作。
栈用一个结构体来存储，定义如下：
```
#define MAX_SIZE 100

struct stack {
	int top;
	int* elements;
};
```
栈的各个操作为：
```
// 初始化一个栈
void initialize(struct stack* s);
// 弹出栈顶元素，并返回该元素，如果栈为空，返回-1
int pop(struct stack* s);
// 向栈中增加元素，并返回该元素，如果栈已满，返回-1
int push(struct stack* s, int number);
// 返回栈的长度
int get_size(struct stack* s);
// 返回栈顶元素，若栈为空，返回-1
int get_top(struct stack* s);
// 判断栈是否为空，若是，返回1，否则，返回0
int empty(struct stack* s);
// 输出栈，若栈为空，输出“Empty stack”
void list(struct stack* s);
```
# Input
首先输入整数$n$，表示接下来有$n$个操作。

然后输出$n$行，表示每个操作，1表示pop操作，2 num表示将数字$num$ 压进栈，3表示get_size操作，4表示get_front操作，5表示判断栈是否为empty。

# Output
每步操作对应的输出见main.c。

# Example
## input
```
10
2 1
2 2
6
3
1
6
5
1
1
4

```
## output
```
Push 1 successfully!
Push 2 successfully!
Wrong op! Curr stack is: 2 1
Size of stack is 2
Pop 2 successfully!
Wrong op! Curr stack is: 1
Stack is not empty!
Pop 1 successfully!
Pop failed!
Stack is empty!
Empty stack

```
