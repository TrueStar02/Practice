#include "Set.h"
int two(int x)
{   int n=1;
    for(int y=1;y<=x;y++)
        n*=2;
    return n;
}
vector<Set> powerset(const Set &S)
{   int x,y,z;
    vector<Set> r;
    for(x=0;x<two(S.size());x++)
    {   y=x;
        Set t;
        for(z=0;z<S.size();z++)
        {   if(y%2)
                t.push_back(S[z]);
            y/=2;
        }
        r.push_back(t);
    }
    return r;
}
void print(string s, const Set & A){
    cout <<s<<"{";
    for (size_t i=0;i<A.size();i++){
         if (i != A.size()-1)
             cout << A[i] <<",";
         else
            cout<<A[i];
    }
    cout<< "}"<< endl;
}

void printSubsets(const Set &S){
    vector<Set> p = powerset(S);
    print("Set:", S);
    cout << "subsets:"<<endl;
    for (size_t i=0; i< p.size(); i++)
       print("",p[i]);  
}
