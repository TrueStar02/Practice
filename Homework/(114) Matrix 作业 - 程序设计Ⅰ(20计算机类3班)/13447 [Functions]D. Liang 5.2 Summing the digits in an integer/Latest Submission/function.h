int sumDigits(long n)
{int sum=0;
 if(n<0)
 n=-n;
 while(n!=0)
 {  sum+=n%10;
    n/=10;
 }
 return sum;
}