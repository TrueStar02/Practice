#include<set>
#include<iterator>
#include<algorithm>
int sumOfIntersection(const set<int>& set1, const set<int>& set2)
{   vector<int> u;
    set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),insert_iterator<vector<int>> (u,u.begin()));
    int s=0;
    for(int x=0;x<u.size();x++)
        s+=u[x];
    return s;


}