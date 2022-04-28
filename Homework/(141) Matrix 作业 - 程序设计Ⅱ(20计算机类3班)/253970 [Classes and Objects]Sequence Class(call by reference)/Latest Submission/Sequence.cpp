#include "Sequence.h"
Sequence::Sequence(){msize=0;a=new int[10000];}
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
void Sequence::insert(int value){a[msize]=value;msize++;}
void Sequence::insert(int pos, int value)
{   if(pos>msize)return;
    for(int x=msize-1;x>=pos;x--)
        a[x+1]=a[x];
    a[pos]=value;
    msize++;
}
void Sequence::clear(){msize=0;}
void Sequence::reverse(){reverse(0,msize);} //全部翻转
void Sequence::reverse(int fir, int las)
{   int x,y,temp;
    for(x=fir,y=las-1;x<y;x++,y--)
    {   temp=a[x];
        a[x]=a[y];
        a[y]=temp;
    }

} //从哪里到哪里反转
void Sequence::replace(int value1, int value2)
{   for(int x=0;x<msize;x++)
        if(a[x]==value1)
           a[x]=value2;
      

}
void Sequence::swap(Sequence &seq2)
{   if(&seq2==this)return;
    int * tp=a;
    int temp=msize;
    a=seq2.a;
    msize=seq2.msize;
    seq2.msize=temp;
    seq2.a=tp;
}