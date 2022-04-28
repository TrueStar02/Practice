int gcd(int m, int n)
{   int temp;
    if(!(m&&n))return m+n;
    if(m<n)
    {
        temp=m;
        m=n;
        n=temp;
    }
    while(m%n)
    {
        temp=m;
        m=n;
        n=temp%n;
    }
    return n;
}