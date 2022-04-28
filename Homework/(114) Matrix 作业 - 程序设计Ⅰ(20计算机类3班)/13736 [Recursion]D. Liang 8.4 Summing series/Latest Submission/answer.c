double m(int i)
{   double sum=0.0;
    int x;
    for(x=1;x<=i;x++)
        sum+=1.0/((double)x);
    return sum;
}