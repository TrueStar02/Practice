#include "wine.h"
int main(void)
{	Port p1("Gallo","tawny",20);
	cout<<p1<<endl;
	Port p2=p1;
	p2+=5;
	p2.Show();
	VintagePort vp1("Gallo",20,"tawny",15);
	cout<<vp1<<endl;
	VintagePort vp2;
	vp2=vp1;
	vp2-=5;
	vp2.Show();
	return 0;
}
