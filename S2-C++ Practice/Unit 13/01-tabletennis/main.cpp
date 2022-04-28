#include "tabletennis.h"
void show(const Player & p);
int main(void)
{	Player p1("Andy","Black",0);
	RatedPlayer rp1(999,"Zhendong","Fan",1);
	show(p1);
	show(rp1);
	Player p2=rp1;
	RatedPlayer rp2(111,p1);
	show(p2);
	show(rp2);
	cout<<"Rating:"<<rp2.Rating()<<endl;
}
void show(const Player & p)
{	p.Name();
	if(p.HasTable())
		cout<<"has a table\n";
	else
		cout<<"doesn't have a table\n";
}
