#include "Relation.h"
bool transitive(const Relation &R, const Set &A)
{   int x,y,z;
    if(!R.size())return 1;
    vector<pair<int,int> > R0(R.begin(),R.end());
    Relation::iterator i0;
    for(x=0;x<=R.size()-1;x++)
    for(y=0;y<=R.size()-1;y++)
    {	if(R0[x].second==R0[y].first)
    {
					i0=R.find(pair<int,int>(R0[x].first,R0[y].second));
    	if(i0==R.end())return 0;
    }
	}
    return 1;

}