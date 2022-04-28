#include "tabletennis.h"
Player::Player(const string fn,const string ln,bool ht)
{	firstname=fn;
	lastname=ln;
	hastable=ht;
}
void Player::Name() const
{	cout<<lastname<<","<<firstname<<" ";
}
bool Player::HasTable() const
{	return hastable;
}
void Player::ResetTable(bool v)
{	hastable=v;
}
RatedPlayer::RatedPlayer(unsigned int r,const string fn,const string ln,bool ht):Player(fn,ln,ht)
{	rating=r;
}
RatedPlayer::RatedPlayer(unsigned int r,const Player & p):Player(p)
{	rating=r;
}
unsigned int RatedPlayer::Rating() const
{	return rating;
}
void RatedPlayer::ResetRating(unsigned int r)
{	rating=r;
}
