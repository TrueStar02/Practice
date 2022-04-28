#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main() {                             
	vector<int> ivec(10, 2);             // 创建含10个值为2的元素的vector容器
	vector<int>::iterator iter;	         // 声明迭代器对象
	vector<int>::reverse_iterator riter;          // 声明迭代器对象
	
	// your code
	//用 iter 将第0个元素的值加10
    ivec[0]+=10;
    ivec[0]+=10;
	//用 riter 将第0个元素的值加10
	//用 iter 将最后一个元素的值改为100
    (*(ivec.end()-1))=100;
	//用 riter 将最后一个元素的值减20
    (*ivec.rbegin())-=20;
	//用 iter 正序输出所有元素
    for(iter=ivec.begin();iter!=ivec.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
	//用 riter 反向输出所有元素
    for(riter=ivec.rbegin();riter!=ivec.rend();riter++)
        cout<<*riter<<" ";
}