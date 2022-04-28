#ifndef STRASSEN_H_
#define STRASSEN_H_
int ** add(int ** a,int ** b,int size);
int ** paste( int ** lu,int ** ld,int ** ru,int ** rd,int size);
int ** createMatrix(int size);
void freeMatrix(int ** mat,int size);
int ** calculate(int ** a,int ** b,int ax,int ay,int bx,int by,int size);
int ** Strassen(int ** a,int ** b,int size){return calculate(a,b,0,0,0,0,size);}
int ** calculate(int ** a,int ** b,int ax,int ay,int bx,int by,int size)
{   if(size==1)
    {   int ** result=createMatrix(1);
        result[0][0]=a[ax][ay]*b[bx][by];
        return result;
    }
    else
    {   
        int ** lu=add(calculate(a,b,ax,ay,bx,by,size/2),calculate(a,b,ax,ay+size/2,bx+size/2,by,size/2),size/2);
        int ** ld=add(calculate(a,b,ax+size/2,ay,bx,by,size/2),calculate(a,b,ax+size/2,ay+size/2,bx+size/2,by,size/2),size/2);
        int ** ru=add(calculate(a,b,ax,ay,bx,by+size/2,size/2),calculate(a,b,ax,ay+size/2,bx+size/2,by+size/2,size/2),size/2);
        int ** rd=add(calculate(a,b,ax+size/2,ay,bx,by+size/2,size/2),calculate(a,b,ax+size/2,ay+size/2,bx+size/2,by+size/2,size/2),size/2);
        return paste(lu,ld,ru,rd,size);
    }

}
int ** add(int ** a,int ** b,int size)
{   int ** result=createMatrix(size);
    int x,y;
    for(x=0;x<size;x++)
    for(y=0;y<size;y++)
        result[x][y]=a[x][y]+b[x][y];    
    return result;
}
int ** paste( int ** lu,int ** ld,int ** ru,int ** rd,int size)
{   int ** result=createMatrix(size);
    int x,y;
    for(x=0;x<size/2;x++)
    for(y=0;y<size/2;y++)
    {   result[x][y]=lu[x][y];
        result[x+size/2][y]=ld[x][y];
        result[x][y+size/2]=ru[x][y];
        result[x+size/2][y+size/2]=rd[x][y];
    }
    freeMatrix(lu,size/2);
    freeMatrix(ld,size/2);
    freeMatrix(ru,size/2);
    freeMatrix(rd,size/2);
    return result;
}
int ** createMatrix(int size)
{   int ** mat=new int*[size];
    int x;
    for(x=0;x<size;x++)
        mat[x]=new int[size];
    return mat;
}
void freeMatrix(int ** mat,int size)
{   int x;
    for(x=0;x<size;x++)
        delete mat[x];
    delete mat;
}
#endif