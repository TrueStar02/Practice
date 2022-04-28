#include "Set.h"
#include <cstring>
Set setIntersection(const Set &A, const Set &B)
{
    vector<int> IS;
    int* temp;
    if(A.size()==0||B.size()==0)
    {
        return IS;
    }
    else if(A[A.size()-1]>B[B.size()-1])
    {
        temp=new int[A[A.size()-1]+1];
        memset(temp,0,sizeof(int)*A[A.size()-1]+1);
    }
    else
    {
        temp=new int[B[B.size()-1]+1];
        memset(temp,0,sizeof(int)*B[B.size()-1]+1);
    }
    for(vector<int>::const_iterator it=A.begin();it!=A.end();it++)
    {
        temp[*it]++;
    }
    for(vector<int>::const_iterator it=B.begin();it!=B.end();it++)
    {
        temp[*it]++;
    }
    for(vector<int>::const_iterator it=A.begin();it!=A.end();it++)
    {
        if(temp[*it]==2)
        IS.push_back(*it);
    }
    delete[] temp;
    return IS;
}