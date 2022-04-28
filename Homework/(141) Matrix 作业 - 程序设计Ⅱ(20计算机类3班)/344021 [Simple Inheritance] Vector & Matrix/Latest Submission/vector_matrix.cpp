#include "vector_matrix.h"
#include<cmath>
Vector::Vector(){}
Vector::Vector(int dim, const int* e):dimension(dim)
{   elements=new int[dim];
    int x;
    for(x=0;x<dim;x++)
        elements[x]=e[x];
}
Vector::~Vector(){delete [] elements;}
    
int Vector::getDimension() const{return dimension;}
int * Vector::getElements() const{return elements;}
double Vector::getModule() const
{   int sum=0,x;
    for(x=0;x<dimension;x++)
        sum+=elements[x]*elements[x];
    return sqrt(sum);
} 
Matrix::Matrix(){}
Matrix::Matrix(int r, int c, const int* e):row(r),Vector(r*c,e){}
bool Matrix::Symmetric() const
{   if(row!=getDimension()/row)return 0;
    const int * ele=getElements();
    int x,y;
    for(x=0;x<row;x++)
    for(y=0;y<row;y++)
        if(ele[x*row+y]!=ele[y*row+x])
            return 0;
    return 1;
} 