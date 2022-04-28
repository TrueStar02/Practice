#include "TBST.h"
using namespace std;
int main()
{   TBST<int,string> bst;
    bst.insert(6,"G");
    bst.insert(8,"I");
    bst.insert(7,"H");
    bst.insert(9,"J");
    bst.insert(3,"D");
    bst.insert(4,"E");
    bst.insert(5,"F");
    bst.insert(1,"B");
    bst.insert(0,"A");
    bst.insert(2,"C");
    bst.thread();
    bst.layer();
    bst.ShowAll();
    
    cout<<bst.floor(11)<<endl;
    cout<<bst.ceiling(-1)<<endl;
}
