# 队列的实现

# Description
实现队列的各个操作。
队列用一个结构体来存储，定义如下：
```
#define MAX_SIZE 100

struct queue {
	int front;
	int tail;
	int* elements;
};
```
队列的各个操作为：
```
// 初始化一个队列
void initialize(struct queue* q);
// 弹出队首元素，并返回该元素，如果队列为空，返回-1
int pop(struct queue* q);
// 向队列中增加元素，并返回该元素，如果队列已满，返回-1
int push(struct queue* q, int number);
// 返回队列长度
int get_size(struct queue* q);
// 返回队首元素，若队列为空，返回-1
int get_front(struct queue* q);
// 判断队列是否为空，若是，返回1，否则，返回0
int empty(struct queue* q);
// 输出队列，若队列为空，输出“Empty queue”
void list(struct queue* q);
```
# Input
首先输入整数$n$，表示接下来有$n$个操作。

然后输出$n$行，表示每个操作，1表示pop操作，2 num表示将数字$num$ push进队列，3表示get_size操作，4表示get_front操作，5表示判断队列是否为empty。

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
Curr queue is: 1 2
Size of queue is 2
Pop 1 successfully!
Curr queue is: 2
Queue is not empty!
Pop 2 successfully!
Pop failed!
Queue is empty!
Empty queue

```
