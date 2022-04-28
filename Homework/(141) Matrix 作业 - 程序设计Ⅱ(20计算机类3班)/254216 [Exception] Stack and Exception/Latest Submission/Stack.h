template<class T>

class Stack

{private:

    T data[5];

    int stack_size;


public:

    explicit Stack(){stack_size=0;}

    bool empty() const{return !stack_size;}

    int size() const{return stack_size;}

    T& top(){if(stack_size)return data[stack_size-1];else throw 1;}

    const T& top() const{if(stack_size)return data[stack_size-1];else throw 1;}

    void push(const T& x)
    {if(stack_size<5)
        {   data[stack_size]=x;
            stack_size++;
        }
        else if(x>data[4])
            data[4]=x;
    }

    void pop(){if(stack_size)stack_size--;else throw 1.1;}


};