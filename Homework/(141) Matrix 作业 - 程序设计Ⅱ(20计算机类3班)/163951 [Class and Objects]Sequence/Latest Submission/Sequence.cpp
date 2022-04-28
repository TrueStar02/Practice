#include "Sequence.h"
Sequence::Sequence(){a=new int[10000];msize=0;}
	Sequence::~Sequence(){delete [] a;}
	int Sequence::size(){return msize;}
	bool Sequence::empty(){return !msize;}
	bool Sequence::find(int value)
    {   for(int x=0;x<msize;x++)
            if(a[x]==value)
                return 1;
        return 0;
    }
	int & Sequence::at(int pos){return a[pos];}
	int Sequence::front(){return a[0];}
	int Sequence::back(){return a[msize-1];} 
	void Sequence::insert(int value)
    {   a[msize]=value;
        msize++;
    }
	void Sequence::insert(int pos, int value)
    {   for(int y=msize-1;y>=pos;y--)
            a[y+1]=a[y];
        a[pos]=value;
            msize++;
    }
	void Sequence::clear(){msize=0;}
	void Sequence::reverse()
    {       int y,temp;
         for(y=0;y<msize/2;y++)
         {  temp=a[y];
            a[y]=a[msize-1-y];
            a[msize-1-y]=temp;
         }
    }
	void Sequence::reverse(int fir, int las)
    {     int y,temp;
         for(y=fir;y<(las+fir)/2;y++)
         {  temp=a[y];
            a[y]=a[fir+las-1-y];
            a[fir+las-1-y]=temp;
         }

    }
	void Sequence::replace(int value1, int value2)
    {   for(int x=0;x<msize;x++)
            if(a[x]==value1)
                a[x]=value2;

    }
	void Sequence::swap(Sequence &seq2)
    {
        int * b=a;
        int temp=msize;
        a=seq2.a;
        msize=seq2.msize;
        seq2.a=b;
        seq2.msize=temp;
    }
