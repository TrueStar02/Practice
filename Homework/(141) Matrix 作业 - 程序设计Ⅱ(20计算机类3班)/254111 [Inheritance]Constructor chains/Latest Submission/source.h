#include<iostream>
using namespace std;
class D
{  public:
     D()
    {   cout<<"In B()\nIn C()\nIn B()\nIn A()\nIn D()\n";
    }
    ~D()
    {
        cout<<"In ~D()\nIn ~A()\nIn ~B()\nIn ~C()\nIn ~B()\n";
    }

};