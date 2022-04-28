# [Inheritance]anonymous

## Description
Anonymous has met a problem.To solve this problem, he has to write 4 classes.<br/>
These classes are point, vector, circle and todo.<br/>
```
        point
          /  \
        /      \
       vector  circle
        \      /
         \    /
         todo
```
We can use two double varibles x and y to describe a point;<br/>
We can use four double varibles x, y, dx and dy to describe a vector;<br/>
We can use three double varibles x, y and r to describe a circle;<br/>
We can use five double varibles x, y, dx, dy and r to describe a todo;<br/>
<br/>
Your should complete a print function in each class.<br/>
In point, you should print<br/>
point : x y<br/>
<br/>
In vector, you should print<br/>
length : length<br/>
point : x y<br/>
<br/>
In circle, you should print<br/>
area : area<br/>
point : x y<br/>
<br/>
In todo, you should print<br/>
volume : volume<br/>
length : length<br/>
point : x y<br/>
area : area<br/>
point : x y<br/>
<br/>
For example:<br/>
volume : 5.97<br/>
length : 1.41<br/>
point : 1.00 1.00<br/>
area : 3.14<br/>
point : 1.00 1.00<br/>
<br/>
## sample input:

1 1 1 1 1

## sample output:

point : 1.00 1.00<br/>
<br/>
length : 1.41<br/>
point : 1.00 1.00<br/>
<br/>
area : 3.14<br/>
point : 1.00 1.00<br/>
<br/>
volume : 0.00<br/>
length : 0.00<br/>
point : 0.00 0.00<br/>
area : 0.00<br/>
point : 0.00 0.00<br/>
<br/>
volume : 5.97<br/>
length : 1.41<br/>
point : 1.00 1.00<br/>
area : 3.14<br/>
point : 1.00 1.00<br/>

## Hint
 这里详细解释一下几个类把。<br/>
<br/>
point是点。用一个坐标x, y来描述。<br/>
<br/>
vector是向量。但是我们假设这个向量是从一个点x, y出发的向量，向量的信息为(dx,dy)<br/>
<br/>
也就是从(x,y)到 (x+dx, y+dy)的一个向量<br/>
<br/>
circle是一个在(x,y)点，半径为r的圆<br/>
<br/>
todo是将圆按向量从(x,y)平移到(x+dx, y+dy)经过的所有区域。至于为什么叫todo只是随手取的。volume其实是指这个区域的面积此处用错了<br/>
<br/>
输出行末没有空格，冒号两边有空格， 数字之间用空格隔开，输出保留两位小数。 pi(π) 取acos(-1.0)。。需要`#include<cmath>`
<br/>
 <br/>
<br/>
这题不使用虚继承也可以实现，但是直接访问会发现从todo访问x,y时会产生错误。<br/>
<br/>
可以在派生类中调用基类的print实现。所以特意把输出格式定为题中这种。<br/>
<br/>
标程用了虚继承，想使用虚继承可自学ppt最后几页。<br/>

**copy from 王毅峰**