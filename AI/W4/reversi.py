from posixpath import split

def break_string(str):
    list1=str.split(" ",-1)
    a=int(list1[0])
    b=int(list1[1])
    return a,b

class Reversi():
    def __init__(self,fm,a0,a1,a2,a3,d): 
        self.value=(256,-16,64,32,32,64,-16,256,-16,-32,4,2,2,4,-32,-16,64,4,16,8,8,16,4,64,32,2,8,1,1,8,2,32,32,2,8,1,1,8,2,32,64,4,16,8,8,16,4,64,-16,-32,4,2,2,4,-32,-16,256,-16,64,32,32,64,-16,256) 
        self.firstmove=fm
        self.arg0=a0
        self.arg1=a1
        self.arg2=a2
        self.arg3=a3
        self.depth=d
        if not self.firstmove:
            self.graph=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
            self.validlist=[19,26,37,44]
        else:
            self.graph=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
            self.validlist=[18,20,34]  

    def getval(self,list,val1,isblack):
        val0=0
        cnt=0
        for i in range(0,64):
            val0 += list[i]*self.value[i]
            if list[i] != 0:
                cnt+=1
        if isblack == False:
            val1=-val1
        if (isblack and cnt%2==0) or ((not isblack) and cnt%2==1):
            val2=-1
        else:
            val2=1
        val3=list[0]+list[7]+list[56]+list[63]
        x1=x2=x3=x4=0
        y1=y2=y3=y4=0
        if list[0] != 0:            
            for i in range(1,7):
                if list[i]==list[0]:
                    x1+=1
                else:
                    break
            for i in range(1,7):
                if list[i*8]==list[0]:
                    y1+=1
                else:
                    break
            val3+=list[0]*(x1+y1)
            if x1>=2 and y1>=2 and list[9]==list[0]:
                val3+=list[0]
        if list[7] != 0:
            for i in range(6,0,-1):
                if list[i]==list[7]:
                    x2+=1
                else:
                    break
            for i in range(1,7):
                if list[i*8+7]==list[7]:
                    y2+=1
                else:
                    break
            val3+=list[7]*(x2+y2)
            if x2>=2 and y2>=2 and list[14]==list[7]:
                val3+=list[7]
        if list[56] != 0:
            for i in range(1,7):
                if list[56+i]==list[56]:
                    x3+=1
                else:
                    break
            for i in range(6,0,-1):
                if list[i*8]==list[56]:
                    y3+=1
                else:
                    break
            val3+=list[56]*(x3+y3)
            if x3>=2 and y3>=2 and list[49]==list[56]:
                val3+=list[56]
        if list[63] != 0:
            for i in range(6,0,-1):
                if list[56+i]==list[63]:
                    x4+=1
                else:
                    break
            for i in range(6,0,-1):
                if list[i*8+7]==list[63]:
                    y4+=1
                else:
                    break
            val3+=list[63]*(x4+y4)
            if x4>=2 and y4>=2 and list[54]==list[63]:
                val3+=list[63]
        if x1==6 and x2==6:
            val3-=4*list[0]
        if x3==6 and x4==6:
            val3-=4*list[63]
        if y1==6 and y3==6:
            val3-=4*list[0]
        if y2==6 and y4==6:
            val3-=4*list[63]
        return self.arg0*val0+self.arg1*val1+self.arg2*val2+self.arg3*val3

    def isvalid(self,a,b,list,isblack):
        if a<0 or a>7 or b<0 or b>7 or list[a*8+b] != 0:
            return False
        if isblack:
            my=1
            your=-1
        else:
            my=-1
            your=1
        if a>1 and list[(a-1)*8+b]==your: #u
            i=a-1
            while i>=0:
                if list[8*i+b] != your:
                    if list[8*i+b] == my:
                        return True
                    break
                i-=1
        if a>1 and b<6 and list[(a-1)*8+b+1]==your: #ur
            i=a-1
            j=b+1
            while i>=0 and j<8:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        return True
                    break
                i-=1
                j+=1
        if b<6 and list[a*8+b+1]==your: #r
            j=b+1
            while j<8:
                if list[8*a+j] != your:
                    if list[8*a+j] == my:
                        return True
                    break
                j+=1
        if a<6 and b<6 and list[(a+1)*8+b+1]==your: #dr
            i=a+1
            j=b+1
            while i<8 and j<8:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        return True
                    break
                i+=1
                j+=1
        if a<6 and list[(a+1)*8+b]==your: #d
            i=a+1
            while i<8:
                if list[8*i+b] != your:
                    if list[8*i+b] == my:
                        return True
                    break
                i+=1
        if a<6 and b>1 and list[(a+1)*8+b-1]==your: #dl
            i=a+1
            j=b-1
            while i<8 and j>=0:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        return True
                    break
                i+=1
                j-=1
        if b>1 and list[a*8+b-1]==your: #l
            j=b-1
            while j>=0:
                if list[8*a+j] != your:
                    if list[8*a+j] == my:
                        return True
                    break
                j-=1
        if a>1 and b>1 and list[(a-1)*8+b-1]==your: #ul
            i=a-1
            j=b-1
            while i>=0 and j>=0:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        return True
                    break
                i-=1
                j-=1  
        return False  

    def step(self,a,b,list,isblack):
        flag=False
        if isblack:
            my=1
            your=-1
        else:
            my=-1
            your=1
        list[a*8+b]=my 
        if a>1: #u
            i=a-1
            while i>=0:
                if list[8*i+b] != your:
                    if list[8*i+b] == my:
                        flag=True
                    break
                i-=1
        if flag:
            i=a-1
            while i>=0:
                if list[8*i+b] == your:
                    list[8*i+b] = my
                else:
                    break
                i-=1
        flag=False
        if a>1 and b<6: #ur
            i=a-1
            j=b+1
            while i>=0 and j<8:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        flag=True
                    break
                i-=1
                j+=1
        if flag:
            i=a-1
            j=b+1
            while i>=0 and j<8:
                if list[8*i+j] == your:
                    list[8*i+j] = my
                else:
                    break
                i-=1
                j+=1
        flag=False
        if b<6: #r
            j=b+1
            while j<8:
                if list[8*a+j] != your:
                    if list[8*a+j] == my:
                        flag=True
                    break
                j+=1
        if flag:
            j=b+1
            while j<8:
                if list[8*a+j] == your:
                    list[8*a+j] = my
                else:
                    break
                j+=1
        flag=False
        if a<6 and b<6: #dr
            i=a+1
            j=b+1
            while i<8 and j<8:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        flag=True
                    break
                i+=1
                j+=1
        if flag:
            i=a+1
            j=b+1
            while i<8 and j<8:
                if list[8*i+j] == your:
                    list[8*i+j] = my
                else:
                    break
                i+=1
                j+=1
        flag=False
        if a<6 : #d
            i=a+1
            while i<8:
                if list[8*i+b] != your:
                    if list[8*i+b] == my:
                        flag=True
                    break
                i+=1
        if flag:
            i=a+1
            while i<8:
                if list[8*i+b] == your:
                    list[8*i+b] = my
                else:
                    break
                i+=1
        flag=False
        if a<6 and b>1: #dl
            i=a+1
            j=b-1
            while i<8 and j>=0:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        flag=True
                    break
                i+=1
                j-=1
        if flag:
            i=a+1
            j=b-1
            while i<8 and j>=0:
                if list[8*i+j] == your:
                    list[8*i+j] = my
                else:
                    break
                i+=1
                j-=1   
        flag=False
        if b>1: #l
            j=b-1
            while j>=0:
                if list[8*a+j] != your:
                    if list[8*a+j] == my:
                        flag=True
                    break
                j-=1
        if flag:
            j=b-1
            while j>=0:
                if list[8*a+j] == your:
                    list[8*a+j] = my
                else:
                    break
                j-=1
        flag=False
        if a>1 and b>1: #ul
            i=a-1
            j=b-1
            while i>=0 and j>=0:
                if list[8*i+j] != your:
                    if list[8*i+j] == my:
                        flag=True
                    break
                i-=1
                j-=1  
        if flag:
            i=a-1
            j=b-1
            while i>=0 and j>=0:
                if list[8*i+j] == your:
                    list[8*i+j] = my
                else:
                    break
                i-=1
                j-=1   
        
    def getstep(self):
        print("Input the position:")
        s=input()
        a,b=break_string(s)
        if(a*8+b in self.validlist):
            self.step(a,b,self.graph,not self.firstmove)
            return True
        else:
            return False

    def updatevalid(self,isblack,graph):
        newlist=[]
        for i in range(0,64):
            if graph[i] == 0 and self.isvalid(i//8,i%8,graph,isblack) == True:
                newlist.append(i)
        return newlist
    
    def printgraph(self):
        str=""
        for i in range(0,8):
            for j in range(0,8):
                if self.graph[i*8+j] == 0 :
                    str+='.'
                elif self.graph[i*8+j] == 1:
                    str+='#'
                else:
                    str+='O'
            str+='\n'
        print(str)

    
    def alphabeta(self,list,alpha,beta,dp,isMax):
        if isMax:
            val=-10000000000
            my=1
        else:
            val=10000000000
            my=-1
        if dp==0:
            valid=self.validlist
        else:
            valid=self.updatevalid(isMax,list)
        if len(valid)==0 or dp==self.depth:
            return -1,self.getval(list,len(valid),isMax)
        si=-1
        for i in valid:
            tempgraph=list[:]
            self.step(i//8,i%8,tempgraph,isMax)
            index,value=self.alphabeta(tempgraph,alpha,beta,dp+1,not isMax)
            if (isMax and val<value) or ((not isMax) and val>value):
                val=value
                si=i
            if (isMax and val>=beta) or ((not isMax) and val<=alpha):
                break
            if isMax and val>alpha:
                alpha=val
            elif (not isMax) and val<beta:
                beta=val
        return si,val  

    def calculate(self):
        pos,val=self.alphabeta(self.graph,-10000000000,10000000000,0,self.firstmove)
        self.step(pos//8,pos%8,self.graph,self.firstmove)
        return pos,val
        
    def run(self):
        while True:
            self.printgraph()
            people_no=False
            ai_no=False
            if len(self.validlist) != 0:
                while False == self.getstep():
                    print("Invalid position!")
            else:
                print("You have no choice!")
                people_no = True
            self.printgraph()
            self.validlist=self.updatevalid(self.firstmove,self.graph)
            if len(self.validlist) != 0:
                print(str(self.calculate())) 
            else:
                print("I have no choice")
                ai_no=True
            if people_no and ai_no:
                print("Game ended")
                s=0
                for i in range(0,64):
                    s+=self.graph[i]
                if s>0:
                    print("Winner:Black")
                elif s==0:
                    print("Draw")
                else:
                    print("Winner:White")
                print("Checkboard:")
                self.printgraph()
                break
            else:
                self.validlist=self.updatevalid(not self.firstmove,self.graph)
                
    def getres(self):
        if self.firstmove:
            my=1
        else:
            my=-1
        cnt=0
        for i in range(0,64):
            if self.graph[i] == my:
                cnt+=1
        return cnt

    def trainget(self,pos):
        if pos!=-1:
            self.step(pos//8,pos%8,self.graph,not self.firstmove)
        self.validlist=self.updatevalid(self.firstmove,self.graph)
        if len(self.validlist) != 0:
            return self.calculate()
        else:
            return -1

if __name__ == '__main__':
    R=Reversi(True,1009,61022,21798,60847,4) 
    R.run()