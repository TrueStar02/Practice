#ifndef CLOSURE_H_
#define CLOSURE_H_
class Walshall
{   private:
        bool ** mat;
        int n;
    public:
        Walshall(int ele,bool **a):n(ele),mat(a){}
        bool ** operator()(int x);
};
bool ** Walshall::operator()(int a)
{   int i,j,k;
    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        mat[i][j]|=(mat[i][k]&mat[k][j]);
    return mat;
}
class DFS
{   private:
        bool ** arr;
        bool ** result;
        int n;
        void dfsfunc(int ver,int now);
    public:
        DFS(int ele,bool ** a):n(ele),arr(a){result=new bool*[n];}
        bool ** operator()(int x);
};
void DFS::dfsfunc(int ver,int now)
{   int x;
    result[now][ver]=1;
    for(x=0;x<n;x++)
        if(!result[now][x]&&arr[ver][x])
            dfsfunc(x,now);
}
bool ** DFS::operator()(int a)
{   int x,y;
    for(x=0;x<n;x++)
    {   result[x]=new bool[n];
        for(y=0;y<n;y++)
            result[x][y]=0;
        dfsfunc(x,x);
    }
    return result;
}
#endif
