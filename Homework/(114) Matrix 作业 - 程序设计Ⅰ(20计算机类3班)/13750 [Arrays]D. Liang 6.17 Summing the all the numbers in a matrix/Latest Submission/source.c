int sumMatrix(int matrix[4][4])
{   int sum=0;
    int x,y;
    for(x=0;x<=3;x++)
    for(y=0;y<=3;y++)
        sum+=matrix[x][y];
    return sum;
}