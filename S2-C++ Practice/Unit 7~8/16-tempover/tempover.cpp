#include<iostream>
using namespace std;
struct Detail
{	string name;
	double score;
};
template <typename T>
void ShowArray(T *arr[],int size);
template <typename T>
void ShowArray(T arr[],int size);
int main(void)
{	int x,arr[5]={0,1,2,3,4};
	Detail person[3]={{"Paff",96.5},{"NEKO",60.1},{"Robo-Head",100.0}};
	double *ptr[3];
	for(x=0;x<=2;x++)
		ptr[x]=&person[x].score;
	ShowArray(arr,5);
	ShowArray(ptr,3);
	return 0;
}
template <typename T>
void ShowArray( T *arr[],int size)
{	int x;
	for(x=0;x<size;x++)
		cout<<*arr[x]<<" ";
	cout<<endl;
}
template <typename T>
void ShowArray( T arr[],int size)
{	int x;
	for(x=0;x<size;x++)
		cout<<arr[x]<<" ";
	cout<<endl;
}
