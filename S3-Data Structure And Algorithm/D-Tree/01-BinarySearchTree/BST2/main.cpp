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
    //bst.ShowAll();
    bst.layer();
    cout<<bst.floor(11)<<endl;
    cout<<bst.ceiling(-1)<<endl;
    BST<int,string> bst2(bst);
    bst.clear();
    //bst2.ShowAll();
    cout<<endl;
    bst2.erase(8);
    bst2.layer();
    bst2.erase(6);
    cout<<endl;
    bst2.layer();
    bst=bst2;
    bst.insert(6,"G");
    bst.ShowAll();
    cout<<bst.rank(2)<<endl;
    cout<<bst.rank(7)<<endl;
}