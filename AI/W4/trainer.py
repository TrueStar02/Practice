from math import ceil
import multiprocessing
import battle
import random

class Trainer:
    def __init__(self,size,times):
        self.size=size
        self.times=times
        self.max_score=size*(size-1)*2
        self.floor=ceil(self.max_score*0.3)

    def a_battle(self,arglist):
        barg0=(arglist[2]>>48)
        barg1=(arglist[2]>>32)&0xffff
        barg2=(arglist[2]>>16)&0xffff
        barg3=arglist[2]&0xffff
        warg0=(arglist[3]>>48)
        warg1=(arglist[3]>>32)&0xffff
        warg2=(arglist[3]>>16)&0xffff
        warg3=arglist[3]&0xffff
        M=battle.Battle(barg0,barg1,barg2,barg3,4,warg0,warg1,warg2,warg3,4)
        a,b=M.run()
        return arglist[0],arglist[1],a,b

    def getrand(self,table):
        k=random.randint(0,table[self.size-1]-1)
        for j in range(0,self.size):
            if k<table[j]:
                return j

    def next_generation(self,gene,score):
        list=[]
        for i in range(0,self.size):
            k=random.randint(0,self.max_score-1)
            if score[i]<=k:
                l=random.randint(0,63)
                r=random.randint(0,63)
                if l<r:
                    continue
                gene[i]^=((1<<(l+1))-(1<<r))
        if score[0]<self.floor:
            score[0]=1
        else:
            score[0]-=self.floor-2
        for i in range(1,self.size):
            if score[i]<self.floor:
                score[i]=1
            else:
                score[i]-=self.floor-2
            score[i]+=score[i-1]
        for i in range(0,20):
            a=self.getrand(score)
            b=self.getrand(score)
            pos=random.randint(1,63)
            mask=(1<<pos)-1
            list.append((gene[a]&(~mask))|gene[b]&mask)
        return list  
            
    def train(self):
        p=multiprocessing.Pool(multiprocessing.cpu_count())
        score=[]
        gene=[]
        for i in range(0,self.size):
            score.append(0)
            gene.append(random.randint(0,2**64-1))
        for t in range(0,self.times):
            args=[]
            for i in range(0,self.size-1):
                for j in range(i+1,self.size):
                    args.append((i,j,gene[i],gene[j]))
                    args.append((j,i,gene[j],gene[i]))
            for res in p.imap(self.a_battle,args):
                score[res[0]]+=res[2]
                score[res[1]]+=res[3]
            print(score)
            if t!=self.times-1:            
                gene=self.next_generation(gene,score)
                for i in range(0,self.size):
                    score[i]=0
        for i in range(0,self.size):
            print("Score:"+str(score[i]))
            print("arg0:"+str(gene[i]>>48))
            print("arg1:"+str((gene[i]>>32)&0xffff))
            print("arg2:"+str((gene[i]>>16)&0xffff))
            print("arg3:"+str(gene[i]&0xffff))

if __name__ == '__main__':
    tr=Trainer(20,100)
    tr.train()