int gcd(int n, int m)
{   int a1=m,b1=n,temp;
    if(a1<b1)
    {   temp=a1;
        a1=b1;
        b1=temp;
    }
    while(a1%b1)
    {   temp=a1;
        a1=b1;
        b1=temp%b1;
    }
    return b1;
}