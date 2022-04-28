import time
inf=500000000

def writeLocalTime(log_obj):
    localtime=time.asctime(time.localtime(time.time()))
    log_obj.write("Local time: "+localtime+"\n")

class Graph():
    def __init__(self,n):
        self.ver=n
        self.tb={}
        self.rtb={}
        self.dist=[]
        self.adj=[]
        self.label=[]
        self.pre=[]
        self.count=0
        for i in range(0,n):
            self.dist.append(0)
            self.adj.append({})
            self.label.append(0)
            self.pre.append(0)

    def addEdge(self,a,b,w,log_obj):
        x=self.tb.get(a,-1)
        if x==-1:
            self.tb[a]=self.count
            self.tb[a[0:1]]=self.count
            self.rtb[self.count]=a
            x=self.count
            self.count+=1
        y=self.tb.get(b,-1)
        if y==-1:
            self.tb[b]=self.count
            self.tb[b[0:1]]=self.count
            self.rtb[self.count]=b
            y=self.count
            self.count+=1
        self.adj[x][y]=w
        self.adj[y][x]=w    
    def Dijkstra(self,begin,endi):
        bi=self.tb.get(endi,-1)
        ei=self.tb.get(begin,-1)
        if bi==-1 or ei==-1:
            print("Invalid input!")
            log_obj.write("Invalid input!\n")
        else:
            self.label[bi]=1
            self.dist[bi]=0
            self.pre[bi]=-1
            for i in range(0,self.ver):
                if i!=bi:
                    self.dist[i]=self.adj[bi].get(i,inf)
                    self.label[i]=0
                    self.pre[i]=bi

            for i in range(1,self.ver):
                min=inf
                index=-1
                for j in range(0,self.ver):
                    if self.label[j] != 1 and self.dist[j]<min:
                        min=self.dist[j]
                        index=j
                self.label[index]=1
                for adjvex,weight in self.adj[index].items():
                    if self.label[adjvex]==0 and self.dist[index]+weight<self.dist[adjvex]:
                        self.dist[adjvex]=self.dist[index]+weight
                        self.pre[adjvex]=index
                
            i=ei
            print("Shortest Path:",end="")
            log_obj.write("Shortest Path:\n")
            while i!=bi:
                print(self.rtb[i]+"->",end="")
                log_obj.write(self.rtb[i]+"->")
                i=self.pre[i]
            print(self.rtb[i]+"")
            log_obj.write(self.rtb[i]+"\n")
            print("Distance:",end="")
            log_obj.write("Distance:")
            print(self.dist[ei])
            log_obj.write(str(self.dist[ei]))
            log_obj.write("\n")


log_obj=open("log.txt","a")
log_obj.write("Power on\n")
writeLocalTime(log_obj)

with open ('Romania.txt') as file_obj:
    lines=file_obj.readlines()
    n,m=lines[0].rstrip().split()
    m=int(m)
    n=int(n)
    
    graph=Graph(n)
    for i in range(1,m+1):
        a,b,w=lines[i].rstrip().split()
        w=int(w)
        graph.addEdge(a,b,w,log_obj)

while True:
    print("Enter the start point(0 to exit):",end="")
    b=input().rstrip().lower().title()
    if b=="0":
        break
    print("Enter the destination(0 to exit):",end="")
    e=input().rstrip().lower().title()
    if e=="0":
        break
    graph.Dijkstra(b,e)
    
print("Thank you to use the system!")   
log_obj.write("Power off\n")
writeLocalTime(log_obj)
log_obj.close()