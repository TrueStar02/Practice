#include "tv.h"
int main(void)
{	TV s42;
	TV s58(1,22);
	cout<<"42\" TV:\n";
	s42.settings();
	cout<<"58\" TV:\n";
	s58.settings();
	Remote r;
	r.onoff(s42);
	r.volup(s42);
	r.set_chan(s58,9);
	r.set_input(s58);
	r.set_input(s58);
	cout<<"42\" TV:\n";
	s42.settings();
	cout<<"58\" TV:\n";
	s58.settings();
	s58.set_mode(r);
	r.showmode();
	return 0;
}
