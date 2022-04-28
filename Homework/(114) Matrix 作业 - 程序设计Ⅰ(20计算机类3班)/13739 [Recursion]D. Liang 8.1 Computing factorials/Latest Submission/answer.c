long factorial(int n)
{   int x;
    long mut=1;
    for(x=1;x<=n;x++)
        mut*=x;
    return mut;
}