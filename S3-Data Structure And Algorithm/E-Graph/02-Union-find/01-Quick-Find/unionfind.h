#ifndef UNIONFIND_H_
#define UNIONFIND_H_
class UnionFind
{   private:
        int * id;
        int count;
        int size;
    public:
        UnionFind(int n);
        UnionFind(const UnionFind & uf);
        UnionFind(UnionFind && uf);
        UnionFind & operator=(const UnionFind & uf);
        UnionFind & operator=(UnionFind && uf);
        ~UnionFind(){delete [] id;}
        void Union(int p,int q);
        int Find(int p);
        bool isConnected(int p,int q){return Find(p)==Find(q);}
        int Count(void){return count;}
};
UnionFind::UnionFind(int n):size(n)
{   id=new int[n];
    int x;
    count=n;
    for(x=0;x<n;x++)
        id[x]=x;
}
UnionFind::UnionFind(const UnionFind & uf):size(uf.size)
{   id=new int[uf.size];
    int x;
    count=uf.count;
    for(x=0;x<size;x++)
        id[x]=uf.id[x];
}
UnionFind::UnionFind(UnionFind && uf):size(uf.size)
{   id=uf.id;
    uf.id=nullptr;
    count=uf.count;
}
UnionFind & UnionFind::operator=(const UnionFind & uf)
{   if(this==&uf)
        return *this;
    delete [] id;
    id=new int[uf.size];
    int x;
    count=uf.count;
    size=uf.size;
    for(x=0;x<count;x++)
        id[x]=uf.id[x];
    return *this;
}
UnionFind & UnionFind::operator=(UnionFind && uf)
{   delete [] id;
    id=uf.id;
    uf.id=nullptr;
    count=uf.count;
    size=uf.size;
    return * this;
}
void UnionFind::Union(int p,int q)
{   if(id[p]!=id[q])
    {   int x,idq=id[q],idp=id[p];
        for(x=0;x<size;x++)
            if(id[x]==idq)
                id[x]=idp;
        count--;
    }
}
int UnionFind::Find(int p){   return id[p];}
#endif