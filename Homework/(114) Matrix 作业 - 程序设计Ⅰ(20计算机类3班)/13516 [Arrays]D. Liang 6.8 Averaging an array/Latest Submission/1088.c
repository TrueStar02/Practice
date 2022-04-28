int average_int(int array[], int size)
{   double avg=0;
    int x;
    for(x=0;x<size;x++)
        avg+=(double)array[x];
    avg/=size;
    return (int)avg;

}
double average_double(double array[], int size)
{   double avg=0;
    int x;
    for(x=0;x<size;x++)
        avg+=array[x];
    avg/=size;
    return avg;

}