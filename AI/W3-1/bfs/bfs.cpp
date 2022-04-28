#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int graph[18][37];
int label[18][37];
int prior[18][37][2];
struct Point
{   int x;
    int y;
    Point(int x0=0,int y0=0):x(x0),y(y0){}
};
int main()
{   
    ifstream fin("MazeData.txt");
    ofstream fout("MazeSolution.out");
    string str;
    int x,y,sx,sy,dx,dy;
    for(x=0;x<18;x++)
    {   fin>>str;
        
        for(y=0;y<36;y++)
        {   if(str[y]=='0')
                graph[x][y]=0;
            else if(str[y]=='1')
                graph[x][y]=1;
            else if(str[y]=='S')
            {   sx=x;
                sy=y;
                graph[x][y]=0;
            }    
            else
            {   dx=x;
                dy=y;
                graph[x][y]=0;
            }
            

        }

    }
   
    Point p(dx,dy);
    label[dx][dy]=1;
    queue<Point> q;
    q.push(p);
    while(q.size())
    {   p=q.front();
        q.pop();
        if(p.x==sx&&p.y==sy)
            break;
        if(label[p.x-1][p.y]==0&&graph[p.x-1][p.y]==0)
        {   label[p.x-1][p.y]=1;
            prior[p.x-1][p.y][0]=p.x;
            prior[p.x-1][p.y][1]=p.y;
            q.push(Point(p.x-1,p.y));
        }
        if(label[p.x+1][p.y]==0&&graph[p.x+1][p.y]==0)
        {   label[p.x+1][p.y]=1;
            prior[p.x+1][p.y][0]=p.x;
            prior[p.x+1][p.y][1]=p.y;
            q.push(Point(p.x+1,p.y));
        }
        if(label[p.x][p.y-1]==0&&graph[p.x][p.y-1]==0)
        {   label[p.x][p.y-1]=1;
            prior[p.x][p.y-1][0]=p.x;
            prior[p.x][p.y-1][1]=p.y;
            q.push(Point(p.x,p.y-1));
        }
        if(label[p.x][p.y+1]==0&&graph[p.x][p.y+1]==0)
        {   label[p.x][p.y+1]=1;
            prior[p.x][p.y+1][0]=p.x;
            prior[p.x][p.y+1][1]=p.y;
            q.push(Point(p.x,p.y+1));
        }
    }
    for(x=sx,y=sy;x!=0||y!=0;)
    {   graph[x][y]=2;
        dx=x;
        dy=y;
        x=prior[dx][dy][0];
        y=prior[dx][dy][1];
    }
    for(x=0;x<18;x++)
    {   for(y=0;y<36;y++)
            fout<<graph[x][y];
        fout<<'\n';
    }
    return 0;
}