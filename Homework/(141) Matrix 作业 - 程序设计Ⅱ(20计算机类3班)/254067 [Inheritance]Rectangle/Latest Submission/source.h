class Rectangle
{   private:
        int x;
        int y;
        int len;
        int wid;
    public:
        Rectangle(int x0,int y0,int l,int w):x(x0),y(y0),len(l),wid(w){}
        void Move(int xm,int ym){x+=xm;y+=ym;}
        int Getx(void){return x;}
        int Gety(void){return y;}
        int Getlength(){return len;}
        int Getwidth(){return wid;}
		int Getarea(){return len*wid;}
};