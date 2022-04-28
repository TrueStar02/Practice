#include "tv.h"
const char *in[5]={"TV","AV","VGA","HDMI","DP"};
void TV::chanup()
{	if(channel<maxchannel)
		channel++;
	else
		channel=1;
}
void TV::chandown()
{	if(channel==1)
		channel=maxchannel;
	else
		channel--;
}
void TV::set_input()
{	if(input==4)
		input=0;
	else
		input++;
}
void TV::settings() const
{	cout<<"TV is "<<(state?"On":"Off")<<endl;
	if(state)
	{	cout<<"Volume:"<<volume<<endl;
		cout<<"Channel:"<<channel<<endl;
		cout<<"Input:"<<in[input]<<endl;
	}
}
