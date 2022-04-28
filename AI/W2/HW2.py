
from posixpath import split
import math

def break_string(str):
    list1=str.split("(",-1)
    str1=list1[0]
    list1=list1[1].split(",",-1)
    str2=list1[0]
    list1=list1[1].split(")",-1)
    return str1,str2,list1[0]
   
class KnowledgeGraph():
    def __init__(self): 
        self.constant_table={}            
        self.constant_rtable={}
        self.constant_count=0
        self.origin_str=[]
        self.variable_count=2
        self.predicate_table={}
        self.predicate_rtable={}
        self.predicate_count=0
        self.background=[]
        self.positive=[]
        self.pos_len=0
        self.negative=[]
        self.neg_len=0
        self.try_table=[]
        self.select_table=[]
        self.new_relation=[]
        self.target=""
        self.var_table=[' ',' ']
    
    def add_info(self,s):
        self.origin_str.append(s)

    def prepare(self,s):
        self.target,self.var_table[0],self.var_table[1]=break_string(s)
        for str in self.origin_str:
            pre,con1,con2=break_string(str)
            icon1=self.constant_table.get(con1,-1)
            icon2=self.constant_table.get(con2,-1)
            if icon1==-1:
                icon1=self.constant_count
                self.constant_count+=1
                self.background.append([])
                self.constant_table[con1]=icon1
                self.constant_rtable[icon1]=con1
            if icon2==-1:
                icon2=self.constant_count
                self.constant_count+=1
                self.background.append([])
                self.constant_table[con2]=icon2
                self.constant_rtable[icon2]=con2
            
            if pre==self.target:
                self.positive.append([icon1,icon2])
            else:
                self.negative.append([icon1,icon2])
                ipre=self.predicate_table.get(pre,-1)
                if ipre==-1:
                    ipre=self.predicate_count
                    self.predicate_count+=1
                    self.predicate_table[pre]=ipre
                    self.predicate_rtable[ipre]=pre
                self.background[ipre].append([icon1,icon2])

        for i in range(0,self.predicate_count):
            self.try_table.append([])
            for j in range(0,self.variable_count):
                for k in range(j+1,self.variable_count+1):
                    self.try_table[i].append([j,k,-1,[],[]])
                    self.try_table[i].append([k,j,-1,[],[]])
        self.pos_len=len(self.positive)
        self.neg_len=len(self.negative)

    def dfs_verify(self,tb,depth,tar_list):
        if(depth==len(self.select_table)):
            if (tb[0]==-1 or tb[0]==tar_list[0]) and (tb[1]==-1 or tb[1]==tar_list[1]):
                return 1
            else:
                return 0
        else:
            sum=0
            for list in self.background[self.select_table[depth][0]]:
                temptb=tb[:]
                if temptb[self.select_table[depth][1]]==-1 or temptb[self.select_table[depth][1]]==list[0]:
                    temptb[self.select_table[depth][1]]=list[0]
                else:
                    continue
                if temptb[self.select_table[depth][2]]==-1 or temptb[self.select_table[depth][2]]==list[1]:
                    temptb[self.select_table[depth][2]]=list[1]
                else:
                    continue
                sum+=self.dfs_verify(temptb,depth+1,tar_list)
            if(sum==0):
                return 0
            else:
                return 1

    def verify(self,bg_list,tar_list,try_list):
        tb=[]
        for i in range(0,self.variable_count+1):
            tb.append(-1)
        tb[try_list[0]]=bg_list[0]
        tb[try_list[1]]=bg_list[1]
        return self.dfs_verify(tb,0,tar_list)    

    def calculate_val(self,i,try_list): 
        b=0 
        for a_list in self.background[i]:
            for p_list in self.positive:
                if p_list not in try_list[3]:
                    b=self.verify(a_list,p_list,try_list)
                    if b>0: 
                        try_list[3].append(p_list)
            for n_list in self.negative:
                if n_list not in try_list[4]:
                    b=self.verify(a_list,n_list,try_list)
                    if b>0:
                        try_list[4].append(n_list)
        pos_c=len(try_list[3])
        neg_c=len(try_list[4])
        if pos_c==0:
            try_list[2]=-1
        else:
            try_list[2]=pos_c*(math.log2(pos_c/(pos_c+neg_c))-math.log2(self.pos_len/(self.pos_len+self.neg_len))) 
          
    def learn(self):
        while self.neg_len!=0:
            maxium=[-1,-1,-1,[],[]]
            index=-1
            for i in range(len(self.try_table)):
                for try_list in self.try_table[i]:
                    self.calculate_val(i,try_list)
                    if try_list[2]>maxium[2]:
                        maxium=try_list
                        index=i
            self.select_table.append([index,maxium[0],maxium[1]])

            self.positive=maxium[3]
            self.negative=maxium[4]
            self.pos_len=len(self.positive)
            self.neg_len=len(self.negative)
            for try_lists in self.try_table:
                for try_list in try_lists:
                    try_list[2],try_list[3],try_list[4]=-1,[],[]
            self.variable_count+=1
            for i in range(0,self.predicate_count):
                for j in range(0,self.variable_count):
                    self.try_table[i].append([j,self.variable_count,-1,[],[]])
                    self.try_table[i].append([self.variable_count,j,-1,[],[]])

    def dfs_find(self,tb,depth):
        if(depth==len(self.select_table)):
            newlist=[tb[0],tb[1]]
            if newlist not in self.positive and newlist not in self.new_relation:
                self.new_relation.append(newlist)
        else:
            for list in self.background[self.select_table[depth][0]]:
                temptb=tb[:]
                if temptb[self.select_table[depth][1]]==-1 or temptb[self.select_table[depth][1]]==list[0]:
                    temptb[self.select_table[depth][1]]=list[0]
                else:
                    continue
                if temptb[self.select_table[depth][2]]==-1 or temptb[self.select_table[depth][2]]==list[1]:
                    temptb[self.select_table[depth][2]]=list[1]
                else:
                    continue
                self.dfs_find(temptb,depth+1)

    def findnew(self):
        tb=[]
        for i in range(0,self.variable_count):
            tb.append(-1)
        self.dfs_find(tb,0)

    def output(self):
        for i in range(2,self.variable_count):
            self.var_table.append("var"+str(i))
        for i in range(len(self.select_table)-1):
            print(self.predicate_rtable[self.select_table[i][0]]+'('+str(self.var_table[self.select_table[i][1]])+','+str(self.var_table[self.select_table[i][2]])+")/\\",end="")
        print(self.predicate_rtable[self.select_table[len(self.select_table)-1][0]]+'('+str(self.var_table[self.select_table[len(self.select_table)-1][1]])+','+str(self.var_table[self.select_table[len(self.select_table)-1][2]])+")",end="")
        print('->'+self.target+'('+self.var_table[0]+','+self.var_table[1]+')')
        for relation in self.new_relation:
            print(self.target+'('+self.constant_rtable[relation[0]]+','+self.constant_rtable[relation[1]]+')')
              
n=int(input())
kg=KnowledgeGraph()

for i in range(0,n):
    kg.add_info(input())
            
kg.prepare(input())  
kg.learn()
kg.findnew() 
kg.output()         