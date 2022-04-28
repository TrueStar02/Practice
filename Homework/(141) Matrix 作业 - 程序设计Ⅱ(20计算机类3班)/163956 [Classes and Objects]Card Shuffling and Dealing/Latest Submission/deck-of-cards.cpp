  #include "deck-of-cards.hpp"
  DeckOfCards::DeckOfCards()
  {    int x,y; 
        for(y=0;y<4;y++)
        for(x=0;x<13;x++)
        deck.push_back(Card(x,y));

  }
    Card  DeckOfCards::dealCard()
    {   Card temp=deck[0];
        deck.erase(deck.begin());
        return temp;
    }
    bool  DeckOfCards::moreCards() const{return deck.size();}
