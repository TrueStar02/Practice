#ifndef TV_H_
#define TV_H_
#include<iostream>
using namespace std;
class TV
{	private:
		friend class Remote;
		bool state;
		int volume;
		int maxchannel;
		int channel;
		int input;
	public:
		explicit TV(bool s=0,int mc=125):state(s),volume(25),maxchannel(mc),channel(2),input(0){}
		void onoff(){state^=1;}
		void volup(){if(volume<100)volume++;}
		void voldown(){if(volume>0)volume--;}
		void chanup();
		void chandown();
		void set_input();
		void settings() const;
};
class Remote
{	public:
		void onoff(TV & t){t.onoff();}
		void volup(TV & t){t.volup();}
		void voldown(TV & t){t.voldown();}
		void chanup(TV & t){t.chanup();}
		void chandown(TV & t){t.chandown();}
		void set_chan(TV & t,int n){if(n>0&&n<=t.maxchannel)t.channel=n;}
		void set_input(TV & t){t.set_input();}
		void settings(TV & t) const{t.settings();}
};
#endif
