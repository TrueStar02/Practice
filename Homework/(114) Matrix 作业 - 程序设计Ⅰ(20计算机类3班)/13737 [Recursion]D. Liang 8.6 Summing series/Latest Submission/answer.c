double m(int i)
{   double sum=0.0;
    int x;
    for(x=1;x<=i;x++)
        sum+=x/((double)(x+1));
    return sum;
}