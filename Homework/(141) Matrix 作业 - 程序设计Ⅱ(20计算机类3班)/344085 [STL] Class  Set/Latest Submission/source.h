#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
template<typename T >
class Set
{
public:
 Set() {data=new T[2000];count=0;}
 Set(int maxSize ) {data=new T[2000];count=0;}
 ~Set() {delete data;}
 Set( const Set& s) 
 {  data=new T[2000];
    count=s.count;
    for(int x=0;x<count;x++)
        data[x]=s.data[x];
 }
 Set operator+( const Set& s )
 {  Set nset;
    int x;
    for(x=0;x<count;x++)
        nset.data[x]=data[x];
    nset.count=count;
    set<T> s2(data,data+count);
    for(x=0;x<s.count;x++)
    {   if(s2.find(s.data[x])==s2.end())
            {   nset.data[nset.count]=s.data[x];
                nset.count++;
            }

    }
    return nset;
 }
 Set operator-( const Set& s ) 
 {    set<T> s2(s.data,s.data+s.count);
    int c=0;
    Set nset;
    int x;
    for(x=0;x<count;x++)
    {   if(s2.find(data[x])==s2.end())
        {   nset.data[nset.count]=data[x];
            nset.count++;
        }
    }
    return nset;
 }
void operator=( const Set& s ) 
{   delete [] data;
    data=new T[2000];
    count=s.count;
    for(int x=0;x<count;x++)
        data[x]=s.data[x];

}
bool insert( T newItem ) 
{   int x,y;
    for(x=0;x<count;x++)
        if(data[x]==newItem)
            return 0;
    data[count]=newItem;
    count++;
    return 1;

}
bool erase( T targetItem ) 
{   int x,y;
    for(x=0;x<count;x++)
        if(data[x]>targetItem)
            return 0;
        else if(data[x]==targetItem)
            break;


        for(;x<count-1;x++)
            data[x]=data[x+1];
        count--;
        return 1;

}
void print()const
{   for(int x=0;x<count;x++)
        cout<<data[x]<<" ";
    cout<<endl;
}
 T* getData() const{return data;}
int getCount() const{return count;}
int getMaxSize() const{return 2000;}
private:
int count ;
int maxSize ;
 T* data ;
} ;