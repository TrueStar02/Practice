long fib(int n)
{   long a=1,b=1,x,temp;
    if(n==0)
        return 0;
    if(n<3)
        return 1;
    for(x=3;x<=n;x++)
    {   temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}