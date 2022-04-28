#include "Set.h"
Set Sort(const Set & s)
{   Set s0=s;
    int x,y,temp;
    for(x=0;x<=s.size()-2;x++)
    for(y=x+1;y<=s.size()-1;y++)
    {   if(s0[x]>s0[y])
        {   temp=s0[x];
            s0[x]=s0[y];
            s0[y]=temp;
        }

    }
    return s0;

}
bool setEq(const Set & A, const Set & B)
{   if(A.size()!=B.size())return 0;
    if(A.size()==0)return 1;
    if(A.size()==1)
    {	if(A[0]==B[0])return 1;
    	else return 0;
    	
	}
    Set A0=Sort(A);
    Set B0=Sort(B);
    int x;
    for(x=0;x<A0.size();x++)
        if(A0[x]!=B0[x])
            return 0;
    return 1;
}