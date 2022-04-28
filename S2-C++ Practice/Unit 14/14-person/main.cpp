#include "person.h"
int main(void)
{	srand((unsigned int)time(0));
	int x;
	Person *ptr[4];
	ptr[0]=new Person("Bill","Gates");
	ptr[1]=new Gunslinger(*ptr[0],1.08,3);
	ptr[2]=new PorkerPlayer(*ptr[0]);
	ptr[3]=new BadDude(*ptr[1]);
	for(x=0;x<4;x++)
		ptr[x]->Show();
	for(x=1;x<4;x++)
		ptr[x]->Set();
	for(x=0;x<4;x++)
		ptr[x]->Show();
	Gunslinger g=*ptr[1];
	PorkerPlayer p=*ptr[2];
	BadDude b=*ptr[3];
	g.Draw()=1.2;
	g.Show();
	Porker temp=p.Draw();	
	temp.Show();
	b.Gdraw()=0.99;
	b.Show();
	temp=b.Cdraw();
	temp.Show();
	return 0;
}
