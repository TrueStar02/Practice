/* Function for computing mean of an array of double values */
double mean_double(double x[], int size)
{   double sum=0;
    int y;
    for(y=0;y<size;y++)
        sum+=y[x];
    return (sum/size);

}

/* Function for computing mean of an array of int values */
double mean_int(int x[], int size)
{   int sum=0;
    int y;
    for(y=0;y<size;y++)
        sum+=y[x];
    return ((double)sum/size);

}

/* Function for computing deviation of an array of double values */
double deviation_double(double x[], int size)
{   double sum=0,avg,sum2=0;
    int y;
    for(y=0;y<size;y++)
        sum+=y[x];
    avg=(sum/size);
    for(y=0;y<size;y++)
        sum2+=(y[x]-avg)*(y[x]-avg);
    return sqrt(sum2/(size-1));
}

/* Function for computing deviation of an array of int values */
double deviation_int(int x[], int size)
{   double sum=0,avg,sum2=0;
    int y;
    for(y=0;y<size;y++)
        sum+=(double)y[x];
    avg=(sum/size);
    for(y=0;y<size;y++)
        sum2+=(y[x]-avg)*(y[x]-avg);
    return sqrt(sum2/(size-1));
}
