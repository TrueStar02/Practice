#ifndef STRASSEN_H_
#define STRASSEN_H_
int ** split(int ** mat,int ax,int ay,int size);
int ** add(int ** a,int ** b,int size);
int ** sub(int ** a,int ** b,int size);
int ** multiply(int ** a,int ** b,int size);
int ** paste( int ** lu,int ** ld,int ** ru,int ** rd,int size);
int ** createMatrix(int size);
void freeMatrix(int ** mat,int size);
int ** calculate(int ** a,int ** b,int size);
int ** Strassen(int ** a,int ** b,int size){return calculate(a,b,size);}
int ** calculate(int ** a,int ** b,int size)
{   if(size==1)
    {   int ** result=createMatrix(1);
        result[0][0]=a[0][0]*b[0][0];
        return result;
    }
    else
    {   
        int ** a11=split(a,0,0,size/2);
        int ** a12=split(a,0,size/2,size/2);
        int ** a21=split(a,size/2,0,size/2);
        int ** a22=split(a,size/2,size/2,size/2);
        int ** b11=split(b,0,0,size/2);
        int ** b12=split(b,0,size/2,size/2);
        int ** b21=split(b,size/2,0,size/2);
        int ** b22=split(b,size/2,size/2,size/2);
        int ** s1=sub(b12,b22,size/2);
        int ** s2=add(a11,a12,size/2);
        int ** s3=add(a21,a22,size/2);
        int ** s4=sub(b21,b11,size/2);
        int ** s5=add(a11,a22,size/2);
        int ** s6=add(b11,b22,size/2);
        int ** s7=sub(a12,a22,size/2);
        int ** s8=add(b21,b22,size/2);
        int ** s9=sub(a11,a21,size/2);
        int ** s10=add(b11,b12,size/2);
        int ** p1=calculate(a11,s1,size/2);
        int ** p2=calculate(s2,b22,size/2);
        int ** p3=calculate(s3,b11,size/2);
        int ** p4=calculate(a22,s4,size/2);
        int ** p5=calculate(s5,s6,size/2);
        int ** p6=calculate(s7,s8,size/2);
        int ** p7=calculate(s9,s10,size/2);
        freeMatrix(a11,size/2);
        freeMatrix(a12,size/2);
        freeMatrix(a21,size/2);
        freeMatrix(a22,size/2);
        freeMatrix(b11,size/2);
        freeMatrix(b12,size/2);
        freeMatrix(b21,size/2);
        freeMatrix(b22,size/2);
        freeMatrix(s1,size/2);
        freeMatrix(s2,size/2);
        freeMatrix(s3,size/2);
        freeMatrix(s4,size/2);
        freeMatrix(s5,size/2);
        freeMatrix(s6,size/2);
        freeMatrix(s7,size/2);
        freeMatrix(s8,size/2);
        freeMatrix(s9,size/2);
        freeMatrix(s10,size/2);
        int ** tp1=add(p5,p4,size/2);
        int ** tp2=sub(p2,p6,size/2);
        int ** c11=sub(tp1,tp2,size/2);
        int ** c12=add(p1,p2,size/2);
        int ** c21=add(p3,p4,size/2);
        freeMatrix(tp1,size/2);
        freeMatrix(tp2,size/2);
        tp1=add(p5,p1,size/2);
        tp2=add(p3,p7,size/2);
        int ** c22=sub(tp1,tp2,size/2);
        freeMatrix(p1,size/2);
        freeMatrix(p2,size/2);
        freeMatrix(p3,size/2);
        freeMatrix(p4,size/2);
        freeMatrix(p5,size/2);
        freeMatrix(p6,size/2);
        freeMatrix(p7,size/2);
        freeMatrix(tp1,size/2);
        freeMatrix(tp2,size/2);
        return paste(c11,c21,c12,c22,size);
    }
}
int ** split(int ** mat,int ax,int ay,int size)
{   int ** result=createMatrix(size);
    int x,y;
    for(x=0;x<size;x++)
    for(y=0;y<size;y++)
        result[x][y]=mat[ax+x][ay+y];
    return result;
}
int ** add(int ** a,int ** b,int size)
{   int ** result=createMatrix(size);
    int x,y;
    for(x=0;x<size;x++)
    for(y=0;y<size;y++)
        result[x][y]=a[x][y]+b[x][y];
    return result;
}
int ** sub(int ** a,int ** b,int size)
{   int ** result=createMatrix(size);
    int x,y;
    for(x=0;x<size;x++)
    for(y=0;y<size;y++)
        result[x][y]=a[x][y]-b[x][y];
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