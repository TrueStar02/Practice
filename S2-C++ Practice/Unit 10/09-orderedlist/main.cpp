#include "list.h"
void Print(Item item);
int main(void)
{	List l;
	Item i1={"Andy",77.5};
	Item i2={"Amy",66.5};
	Item i3={"Cathy",60.7};
	Item i4={"Ben",76.4};
	Item i5={"Elsa",99.9};
	l.add(i1);
	l.traverse(Print);
	l.add(i2);
	l.traverse(Print);
	l.add(i5);
	l.traverse(Print);
	l.add(i4);
	l.traverse(Print);
	cout<<l.search(i4)<<endl;
	cout<<l.kill(i3)<<endl;
	l.add(i3);
	l.traverse(Print);
	l.kill(i5);
	l.traverse(Print);
	l.kill(i2);
	l.traverse(Print);
	l.kill(i4);
	l.traverse(Print);
	l.kill(i3);
	l.traverse(Print);
	l.kill(i2);
	cout<<l.count()<<endl;
	return 0;
	
}
void Print(Item item)
{	cout<<"Name:"<<item.name<<"  Score:"<<item.score<<endl;
}
