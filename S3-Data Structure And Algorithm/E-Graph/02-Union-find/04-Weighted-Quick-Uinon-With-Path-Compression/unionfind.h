#ifndef UNIONFIND_H_
#define UNIONFIND_H_
class UnionFind
{   private:
        int * id;
        int * num;
        int  size;
        int count;
    public:
        UnionFind(int n);
        UnionFind(const UnionFind & uf);
        UnionFind(UnionFind && uf);
        UnionFind & operator=(const UnionFind & uf);
        UnionFind & operator=(UnionFind && uf);
        ~UnionFind(){delete [] id;delete [] num;}
        void Union(int p,int q);
        int Find(int p);
        bool isConnected(int p,int q){return Find(p)==Find(q);}
        int Count(void){return count;}
};
UnionFind::UnionFind(int n):size(n)
{   id=new int[n];
    num=new int[n];
    int x;
    count=n;
    for(x=0;x<n;x++)
    {   id[x]=x;
        num[x]=1;
    }
}
UnionFind::UnionFind(const UnionFind & uf):size(uf.size)
{   id=new int[uf.size];
    num=new int[uf.size];
    int x;
    count=uf.count;
    for(x=0;x<count;x++)
    {   id[x]=uf.id[x];
        num[x]=uf.num[x];
    } 
}
UnionFind::UnionFind(UnionFind && uf)
{   id=uf.id;
    num=uf.num;
    uf.id=nullptr;
    uf.num=nullptr;
    count=uf.count;
}
UnionFind & UnionFind::operator=(const UnionFind & uf)
{   if(this==&uf)
        return *this;
    delete [] id;
    delete [] num;
    id=new int[uf.size];
    num=new int[uf.size];
    int x;
    count=uf.count;
    size=uf.size;
    for(x=0;x<count;x++)
    {   id[x]=uf.id[x];
        num[x]=uf.num[x];
    }
    return *this;
}
UnionFind & UnionFind::operator=(UnionFind && uf)
{   delete [] id;
    delete [] num;
    id=uf.id;
    num=uf.num;
    uf.id=nullptr;
    uf.num=nullptr;
    count=uf.count;
    return * this;
}
void UnionFind::Union(int p,int q)
{   int pid=Find(p);
    int qid=Find(q);
    if(pid!=qid)
    {   if(num[pid]>num[qid])
        {   id[qid]=pid;
            num[pid]+=num[qid];
        }
        else
        {   id[pid]=qid;
            num[qid]+=num[pid];
        }
        count--;
    }
}
int UnionFind::Find(int p)
{   if(p==id[p])
        return p;
    else 
    {   while(id[id[p]]!=id[p])
            id[p]=id[id[p]];
        return id[p];
    }
}
#endif
