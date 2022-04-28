import reversi

class Battle:
    def __init__(self,ba0,ba1,ba2,ba3,bd,wa0,wa1,wa2,wa3,wd):
        self.blackskip=False
        self.whiteskip=False
        self.black=reversi.Reversi(True,ba0,ba1,ba2,ba3,bd)
        self.white=reversi.Reversi(False,wa0,wa1,wa2,wa3,wd)

    def run(self):
        i=19
        #print("Black position:"+str(i))
        #self.black.printgraph()
        j=self.white.trainget(i)
        #print("White position:"+str(j))
        #self.white.printgraph()
        while not(self.blackskip and self.whiteskip):
            self.blackskip=False
            self.whiteskip=False
            i=self.black.trainget(j)
            if i == -1:
                self.blackskip=True
            #print("Black position:"+str(i))
            #self.black.printgraph()
            j=self.white.trainget(i)
            if j == -1:
                self.whiteskip=True
            #print("White position:"+str(j))
            #self.white.printgraph()
        bsum=self.black.getres()
        wsum=self.white.getres()
        #print("Result:"+str(bsum)+":"+str(wsum))
        if bsum>wsum:
            return 2,0
        elif bsum==wsum:
            return 1,1
        else:
            return 0,2