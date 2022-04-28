#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
struct Graph
{   
    vector<vector<int>> arr;
    bool operator<(const Graph & other)const{return arr<other.arr;}
    Graph(){arr.resize(4);}
};
struct State
{   Graph graph;
    int x0;
    int y0;
    int no;
    int step;
    int dist;
    int cost;
    int father;
    bool operator<(const State & other)const{return cost>other.cost;}
    State(int * init,int n=0,int s=0,int f=-1):father(f),step(s),no(n)
    {   
        int x;
        int tx,ty;
        dist=0;
        for(x=0;x<16;x++)
        {   graph.arr[x>>2].push_back(init[x]);
            if(16==init[x])
            {   x0=x>>2;
                y0=x&3;
            }
            tx=(init[x]-1)>>2;
            ty=(init[x]-1)&3;
            dist+=abs(tx-(x>>2))+abs(ty-(x&3));                        
        }
        cost=dist+(step<<3);
    }
    void update()
    {   int x,y;
        dist=0;
        for(x=0;x<4;x++)
        for(y=0;y<4;y++)
        {   if(graph.arr[x][y]==16)
            {   x0=x;
                y0=y;
            }
            dist+=abs(x-((graph.arr[x][y]-1)>>2))+abs(y-((graph.arr[x][y]-1)&3));
        }    
        cost=dist+(step<<3);
    }
    void print()
    {   int x,y;
        for(x=0;x<4;x++)
        {   for(y=0;y<4;y++)
                cout<<graph.arr[x][y]<<' ';
            cout<<'\n';
        }
        cout<<x0<<' '<<y0<<endl;
        cout<<step<<' '<<dist<<' '<<cost<<'\n'<<'\n';
    }
};

int main()
{   priority_queue<State> pq;
    map<int,State> umap;
    set<Graph> uset;
    int init[16];
    int x,tp;
    for(x=0;x<16;x++)
        cin>>init[x];
    State s(init);
    State s1=s;
    uset.insert(s.graph);
    umap.insert(pair<int,State>(s.no,s));
    s.print();
    int cnt=1;
    pq.push(s);
    for(x=0;x<1000000;x++)
    //while(pq.size())
    {   s=pq.top();
        pq.pop();
        //s.print();
        s.step++;
        if(s.x0>0)
        {   s1=s;
            s1.graph.arr[s.x0][s.y0]=s1.graph.arr[s.x0-1][s.y0];
            s1.graph.arr[s.x0-1][s.y0]=16;
            s1.update();
            s1.father=s.no;
            if(uset.end()==uset.find(s1.graph))
            {   if(s1.dist==0)
                    break;
                s1.no=cnt;
                cnt++;
                uset.insert(s1.graph);
                umap.insert(pair<int,State>(s1.no,s1));
                pq.push(s1);
            }  
        }
        if(s.y0>0)
        {   s1=s;
            s1.graph.arr[s.x0][s.y0]=s1.graph.arr[s.x0][s.y0-1];
            s1.graph.arr[s.x0][s.y0-1]=16;
            s1.update();
            s1.father=s.no;
            if(uset.end()==uset.find(s1.graph))
            {   if(s1.dist==0)
                    break;
                s1.no=cnt;
                cnt++;
                uset.insert(s1.graph);
                umap.insert(pair<int,State>(s1.no,s1));
                pq.push(s1);
            }  
        }
        if(s.x0<3)
        {   s1=s;
            s1.graph.arr[s.x0][s.y0]=s1.graph.arr[s.x0+1][s.y0];
            s1.graph.arr[s.x0+1][s.y0]=16;
            s1.update();
            s1.father=s.no;
            if(uset.end()==uset.find(s1.graph))
            {   if(s1.dist==0)
                    break;
                s1.no=cnt;
                cnt++;
                uset.insert(s1.graph);
                umap.insert(pair<int,State>(s1.no,s1));
                pq.push(s1);
            }  
        }
        if(s.y0<3)
        {   if(s1.dist==0)
                break;
            s1=s;
            s1.graph.arr[s.x0][s.y0]=s1.graph.arr[s.x0][s.y0+1];
            s1.graph.arr[s.x0][s.y0+1]=16;
            s1.update();
            s1.father=s.no;
            if(uset.end()==uset.find(s1.graph))
            {   if(s1.dist==0)
                    break;
                s1.no=cnt;
                cnt++;
                uset.insert(s1.graph);
                umap.insert(pair<int,State>(s1.no,s1));
                pq.push(s1);
            }  
        }
    }
    s1.print();
    return 0;
}