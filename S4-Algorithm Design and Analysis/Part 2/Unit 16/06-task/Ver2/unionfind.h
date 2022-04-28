#ifndef UNIONFIND_H_
#define UNIONFIND_H_
struct Interval
{   int begin;
    int end;
};
class UnionFind
{   private:
        int * id;
        int * num;
        Interval * range;
        int  size;
        int count;
    public:
        UnionFind(int n);
        UnionFind(const UnionFind & uf)=delete;
        UnionFind(UnionFind && uf)=delete;
        UnionFind & operator=(const UnionFind & uf)=delete;
        UnionFind & operator=(UnionFind && uf)=delete;
        ~UnionFind(){delete [] id;delete [] num;delete [] range;}
        void Union(int p,int q);
        int Find(int p);
        Interval getRange(int p);
        bool isConnected(int p,int q){return Find(p)==Find(q);}
        int Count(void){return count;}
};
UnionFind::UnionFind(int n):size(n)
{   id=new int[n];
    num=new int[n];
    range=new Interval[n];
    int x;
    count=n;
    for(x=0;x<n;x++)
    {   id[x]=x;
        num[x]=1;
        range[x].begin=range[x].end=x;
    }
}

void UnionFind::Union(int p,int q)
{   int pid=Find(p);
    int qid=Find(q);
    if(pid!=qid)
    {   if(num[pid]>num[qid])
        {   id[qid]=pid;
            num[pid]+=num[qid];
            if(range[pid].begin>range[qid].begin)
                range[pid].begin=range[qid].begin;
            if(range[pid].end<range[qid].end)
                range[pid].end=range[qid].end;
        }
        else
        {   id[pid]=qid;
            num[qid]+=num[pid];
            if(range[pid].begin<range[qid].begin)
                range[qid].begin=range[pid].begin;
            if(range[pid].end>range[qid].end)
                range[qid].end=range[pid].end;
        }
        count--;
    }
}
int UnionFind::Find(int p)
{   while(p!=id[p])
        p=id[p];
    return p;
}
Interval UnionFind::getRange(int p)
{   int m=Find(p);
    return range[m];
}
#endif