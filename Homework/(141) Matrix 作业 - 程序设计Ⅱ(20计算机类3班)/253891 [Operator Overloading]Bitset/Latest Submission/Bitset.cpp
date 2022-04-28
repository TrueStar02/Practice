#include "Bitset.h"
#include<iostream>
#include<cstring>
using namespace std;
bitset::bitset()
{   for(int x=0;x<5;x++)
        a[x]=0;
}
void bitset::set(int pos)
{   int index=pos/32;
    int offset=(pos%32);
    a[index]|=1<<offset;

}
        void bitset::reset(int pos)
        {   int index=pos/32;
            int offset=(pos%32);
            a[index]&=~(1<<offset);

        }
        int bitset::count() const
        {   int x,y;
            int count=0;
            for(x=0;x<5;x++)
            for(y=0;y<=31;y++)
                 count+=(a[x]>>y)&1;
            return count;
            
        }
        bool bitset::test(int pos) const
        {   int index=pos/32;
             int offset=(pos%32);
            return a[index]&(1<<offset);
        }
        bool bitset::any() const{return count();}
        bool bitset::none() const{return !count();}
        bool bitset::all() const
        {   for(int x=0;x<5;x++)
                if(a[x]!=0xFFFFFFFF)
                    return 0;
            return 1;
        }
        bitset& bitset::operator&= (const bitset& b)
        {  
            for(int x=0;x<=4;x++)
                a[x]=b.a[x]&a[x];
            return *this;
        }
        bitset& bitset::operator|= (const bitset& b)
          {  
            for(int x=0;x<=4;x++)
                a[x]=b.a[x]|a[x];
            return *this;
        }
        bitset& bitset::operator^= (const bitset& b)
          {   bitset r;
            for(int x=0;x<=4;x++)
               a[x]=b.a[x]^a[x];
            return *this;
        }
        bitset& bitset::operator= (const bitset& b)
          {   if(this==&b)return *this;
            for(int x=0;x<=4;x++)
               a[x]=b.a[x];
            return *this;
        }
        bitset& bitset::operator <<= (int pos)
        {   int x,y; 
        	unsigned int m,n;
            for(x=4;x>=1;x--)
            {  memcpy(&m,a+x,4);
            	memcpy(&n,a+x-1,4);
            	m<<=pos;
                m|=(n>>(32-pos));
                memcpy(a+x,&m,4);
                memcpy(a+x-1,&n,4);
            }
            memcpy(&m,a,4);
            memcpy(&n,a+4,4);
            m<<=pos;
            m|=(n>>(32-pos));
            memcpy(a,&m,4);
            memcpy(a+4,&n,4);
            return *this;
        }
        bitset& bitset::operator >>= (int pos)
        {  int x,y; 
        	unsigned int m,n;
           
            for(x=0;x<=3;x++)
            {  memcpy(&m,&(a[x]),4);
            	memcpy(&n,&(a[x+1]),4);
            	m>>=pos;
                m|=(n<<(32-pos));
                memcpy(&(a[x]),&m,4);
                memcpy(&(a[x+1]),&n,4);
            }
           
            a[4]>>=pos;
            
          
            return *this;

        }
        bitset bitset::operator~() const
          {   bitset r;
            for(int x=0;x<=4;x++)
                r.a[x]=~a[x];
            return r;
        }
        bitset bitset::operator&(const bitset& b) const
        {   bitset r;
             
            for(int x=0;x<=4;x++)
               r.a[x]=b.a[x]&a[x];
            return r;

        }
        bitset bitset::operator|(const bitset& b) const
          {   bitset r;
             
            for(int x=0;x<=4;x++)
               r.a[x]=b.a[x]|a[x];
            return r;

        }
        bitset bitset::operator^(const bitset& b) const
          {   bitset r;
             
            for(int x=0;x<=4;x++)
               r.a[x]=b.a[x]^a[x];
            return r;

        }
        bitset bitset::operator<<(int pos) const
        {   int x,y;
            bitset r;
            for(x=0;x<5;x++)
                r.a[x]=a[x];
            unsigned int m,n;
            for(x=4;x>=1;x--)
            {  memcpy(&m,&(r.a[x]),4);
            	memcpy(&n,&(r.a[x-1]),4);
            	m<<=pos;
                m|=(n>>(32-pos));
                memcpy(&(r.a[x]),&m,4);
                memcpy(&(r.a[x-1]),&n,4);
            }
            memcpy(&m,&(r.a[0]),4);
            memcpy(&n,&(r.a[4]),4);
            m<<=pos;
            m|=(n>>(32-pos));
            memcpy(&(r.a[0]),&m,4);
            memcpy(&(r.a[4]),&n,4);
            return r;
        }
        bitset bitset::operator>>(int pos) const
         {   int x,y;
            bitset r;
            for(x=0;x<5;x++)
                r.a[x]=a[x];
            unsigned int m,n;
            for(x=0;x<=3;x++)
            {  memcpy(&m,&(r.a[x]),4);
            	memcpy(&n,&(r.a[x+1]),4);
            	m>>=pos;
                m|=(n<<(32-pos));
                memcpy(&(r.a[x]),&m,4);
                memcpy(&(r.a[x+1]),&n,4);
            }
           
            r.a[4]>>=pos;
            
           
            return r;
        }
        bool bitset::operator== (const bitset& b) const
        {   for(int x=0;x<5;x++)
                if(a[x]!=b.a[x])
                    return 0;
            return 1;
        }
        bool bitset::operator!= (const bitset& b) const
         {   for(int x=0;x<5;x++)
                if(a[x]!=b.a[x])
                    return 1;
            return 0;
        }
        bool  bitset::operator[] (int pos) const
        { int index=pos/32;
             int offset=(pos%32);
            return a[index]&(1<<offset);

        }