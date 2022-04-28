#include "BST.h"
using namespace std;
int main()
{   BST<int,string> bst;
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
    bst.ShowAll();
    BST<int,string> bst2(bst);
    bst.clear();
    bst2.ShowAll();
    bst2.erase(8);
    bst2.ShowAll();
    bst2.erase(6);
    bst2.ShowAll();
    bst=bst2;
    bst.insert(6,"G");
    cout<<bst.floor(8)<<endl;
    cout<<bst.ceiling(8)<<endl;
    bst.ShowAll();
}
