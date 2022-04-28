#include "shape.h"
void Base::print() const
{	cout<<"Center position:("<<x<<","<<y<<")\n";
}
void Circle::print() const
{	cout<<"Circle:\n";
	cout<<"r="<<r<<endl;
	Base::print();
	cout<<"Area:"<<area()<<endl;
}
void Ellipse::print() const
{	cout<<"Ellipse:\n";
	cout<<"a="<<a<<"   b="<<b<<"  theta="<<theta<<endl;
	Base::print();
	cout<<"Area:"<<area()<<endl;
}
