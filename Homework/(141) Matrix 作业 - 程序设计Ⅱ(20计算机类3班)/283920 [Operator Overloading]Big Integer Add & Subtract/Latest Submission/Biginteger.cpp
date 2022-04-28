#include "Biginteger.h"
BigInteger::BigInteger()
{
    size_=0;
    data_=NULL;
   
}
BigInteger::BigInteger(const string& number)
{   size_=number.length();
    data_=new int[size_];
    int x;
    for(x=0;x<size_;x++)
        data_[x]=number[x]-48;

}
  BigInteger::BigInteger(const BigInteger& other)
  { size_=other.size_;
    data_=new int[size_];
    int x;
    for(x=0;x<size_;x++)
        data_[x]=other.data_[x];

  }
BigInteger operator+(const BigInteger& left,
                              const BigInteger& right)
{   BigInteger b;
    if(left.size_>right.size_)
        b.size_=left.size_+1;
    else
        b.size_=right.size_+1;
    b.data_=new int[b.size_];
    int x;
    for(x=0;x<b.size_;x++)
        b.data_[x]=0;
    int i=left.size_-1,j=right.size_-1,k=b.size_-1;
    for(;i>=0||j>=0;i--,j--,k--)
    {   if(i>=0&&j>=0)
        {   b.data_[k]+=left.data_[i]+right.data_[j];
            if(b.data_[k]>=10)
            {    b.data_[k]-=10;
                b.data_[k-1]++;
            }
        }    
        else if(i>=0&&j<0)
        {b.data_[k]+=left.data_[i];
            if(b.data_[k]>=10)
            {    b.data_[k]-=10;
                b.data_[k-1]++;
            }
        }
            else if(i<0&&j>=0)
           { b.data_[k]+=right.data_[j];
            if(b.data_[k]>=10)
            {    b.data_[k]-=10;
                b.data_[k-1]++;
            }
           }
    }
    return b;
}
 
BigInteger operator-(const BigInteger& left,
                              const BigInteger& right)
{
    BigInteger b;
    b.size_=left.size_;
    b.data_=new int[b.size_];
    int x;
    for(x=0;x<b.size_;x++)
        b.data_[x]=left.data_[x];
    int j=right.size_-1,k=b.size_-1;
    for(;j>=0;j--,k--)
    {   
           b.data_[k]-=right.data_[j];
            if(b.data_[k]<0)
            {    b.data_[k]+=10;
                b.data_[k-1]--;
            }
            
       
    }
   if(b.data_[k]<0)
            {    b.data_[k]+=10;
                b.data_[k-1]--;
            }
    return b;
}
ostream& operator<<(ostream& out, const BigInteger& Bint)
{   int x;
    bool flag=0;
    for(x=0;x<Bint.size_;x++)
    {
        if(flag||Bint.data_[x])
        {out<<Bint.data_[x];
            flag=1;
        }

    }
    if(flag==0)
    out<<0;
    return out;
}
  BigInteger::~BigInteger(){delete [] data_;}