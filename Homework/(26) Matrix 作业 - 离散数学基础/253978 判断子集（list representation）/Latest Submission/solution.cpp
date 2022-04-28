#include "Set.h"
bool subset(const Set & A, const Set & B)
{   int x,y;
    for(x=0;x<A.size();x++)
    {   for(y=0;y<B.size();y++)
            if(A[x]==B[y])
                break;
        if(y==B.size())
            return 0;
    }
    return 1;
}