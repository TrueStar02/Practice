#include<iostream>
using namespace std;
template<class T>
class Stack
{
public:
    Stack(){num=0;elements=new T[1000];}              
    bool empty(){return !num;}        
    T peek(){return elements[num-1];}             
    void push(T value){elements[num]=value;num++;}
    T pop(){num--;return elements[num];}                 // Removes the element at the top of the stack and returns it.<br />
    int getsize(){return num;} 
    ~Stack()  {delete [] elements;}
     void printStack()
     {     int x;
            for(x=num-1;x>=0;x--)
                cout<<elements[x]<<endl;


     }           // Returns the number of elements in the stack.<br />
private:
    T* elements;          // Points to an array that stores elements in the stack.<br />
    int num;                 // The number of the elements in the stack.<br />
};