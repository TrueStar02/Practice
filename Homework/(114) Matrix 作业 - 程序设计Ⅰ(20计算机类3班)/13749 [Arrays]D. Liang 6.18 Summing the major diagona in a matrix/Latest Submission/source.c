int sumMajorDiagona(int matrix[4][4])
{   int sum=0;
    int x;
    for(x=0;x<=3;x++)
    
        sum+=matrix[x][x];
    return sum;
}