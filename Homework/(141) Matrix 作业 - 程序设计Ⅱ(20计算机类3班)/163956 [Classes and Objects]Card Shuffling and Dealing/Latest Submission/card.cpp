
#include "card.hpp"

const char* Card::faceNames[13]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
const char* Card::suitNames[4]= {"Hearts","Diamonds","Clubs","Spades"};
 Card::Card(int ce, int it):face(ce),suit(it){}
    std::string  Card::toString() const
    {std::string temp=faceNames[face];
                temp+=" of ";
                temp+=suitNames[suit];
               return temp; }

    int  Card::getFace() const{return face;}
    int  Card::getSuit() const{return suit;}
    
 