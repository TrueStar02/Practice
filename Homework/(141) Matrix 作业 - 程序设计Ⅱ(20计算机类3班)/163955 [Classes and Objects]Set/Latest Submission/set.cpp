#include "set.hpp"
Set::Set(){size=0;}
    // Create an set with some element.
    Set::Set(int* m, int s)
    {   size=s;
        int x,y;
        members[0]=m[0];
        for(x=1;x<s;x++)
        {   for(y=0;y<x;y++)
                if(m[x]==members[y])
                {   size--;
                    break;
                }
                if(y!=x)continue;
            for(y=x-1;y>=0;y--)
            if(members[y]>m[x])
              members[y+1]=members[y];
            else
                break;
         members[y+1]=m[x];
        }   
    }
    // append a element to set.
    // If element in the set, return false.
    // Or insert in set and return true.
    bool Set::append(int e)
    {   int x,y;
        for(y=0;y<size;y++)
            if(members[y]==e)
                return 0;
        for( x=size-1;x>=0;x--)
            if(members[x]>e)
                members[x+1]=members[x];
            else
                break;
            members[x+1]=e;
    size++;
    return 1;
    }
    // remove a element by its value from set.
    // If element in the set, then remove it and return true.
    // Or return false.
    bool Set::remove(int e)
    {  int y;
        for(y=0;y<size;y++)
            if(members[y]==e)
                break;
        if(y==size)
           return 0;
        for(y++;y<=size-1;y++)
            members[y-1]=members[y];
        size--;
        return 1;

    }
    // return true if the set is empty, or return false.
    bool Set::isEmptySet() const
    {return !size;}
    
    // return set.
    int* Set::getMembers(){return members;}
    
    // return size of set.
    int Set::getSize() const{return size;}
 
    // return false if element not in the set, or return true.
    bool Set::isInSet(int e) const
    {   int y;
        for(y=0;y<size;y++)
            if(members[y]==e)
                return 1;
        if(y==size)
           return 0;

    }