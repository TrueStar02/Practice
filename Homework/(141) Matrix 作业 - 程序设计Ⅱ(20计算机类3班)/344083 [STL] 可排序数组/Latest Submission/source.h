#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
class SortableArray
{   private:
        vector<T> vec;
    public:
        SortableArray(int x){}
        void pushBack(T val){vec.push_back(val);}
        void sort(void){std::sort(vec.begin(),vec.end());}
        void printArray()
        {   for(int x=0;x<vec.size();x++)
                cout<<vec[x]<<" ";
            cout<<endl;
        }


};