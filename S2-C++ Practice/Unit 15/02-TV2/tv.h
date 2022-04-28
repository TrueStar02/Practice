#ifndef TV_H_
#define TV_H_
#include<iostream>
using namespace std;
class TV;
class Remote
{	public:
		void onoff(TV & t);
		void volup(TV & t);
		void voldown(TV & t);
		void chanup(TV & t);
		void chandown(TV & t);
		void set_chan(TV & t,int n);
		void set_input(TV & t);
		void settings(TV & t) const;
};
class TV
{	private:
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
		friend void Remote::set_chan(TV & t,int n);
};
inline void Remote::onoff(TV & t){t.onoff();}
inline void Remote::volup(TV & t){t.volup();}
inline void Remote::voldown(TV & t){t.voldown();}
inline void Remote::chanup(TV & t){t.chanup();}
inline void Remote::chandown(TV & t){t.chandown();}
inline void Remote::set_chan(TV & t,int n){if(n>0&&n<=t.maxchannel)t.channel=n;}
inline void Remote::set_input(TV & t){t.set_input();}
inline void Remote::settings(TV & t) const{t.settings();}
#endif
