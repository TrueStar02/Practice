int isPrime(int n)
{   int i=1,x;
    for(x=2;x*x<=n;x++)
        if(n%x==0)
        {   i=0;
            break;
        }
     return i;
}