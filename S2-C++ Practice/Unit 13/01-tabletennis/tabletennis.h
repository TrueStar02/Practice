#ifndef TABLETENNIS_H_
#define TABLETENNIS_H_
#include<iostream>
using namespace std;
class Player
{	private:
		string firstname;
		string lastname;
		bool hastable;
	public:
		Player(const string fn="NaN",const string ln="NaN",bool ht=0);
		void Name() const;
		bool HasTable() const;
		void ResetTable(bool v);
};
class RatedPlayer:public Player
{	private:
		unsigned int rating;
	public:
		RatedPlayer(unsigned int r=0,const string fn="NaN",const string ln="NaN",bool ht=0);
		RatedPlayer(unsigned int r,const Player & p);
		unsigned int Rating() const;
		void ResetRating(unsigned int r);
};
#endif
