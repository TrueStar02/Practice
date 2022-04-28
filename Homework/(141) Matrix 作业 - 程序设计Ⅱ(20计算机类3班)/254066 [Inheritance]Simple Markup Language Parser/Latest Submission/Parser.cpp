#include "Parser.hpp"
#include<cctype>
#include<typeinfo>

Bulider* Bulider::_instance=new Bulider();
State* DataState::_instance=new DataState();
State* TagNameState::_instance=new TagNameState();
Parser* Parser::_instance=new Parser();
Parser* Parser::getInstance(){return _instance;}
void Parser::destroyInstance(){delete _instance;}
void Parser::consumeOneChar(char ch)
{  
    
    _state->handleOneChar(getInstance(),ch);
    if(ch=='<')
    {   
        _state=TagNameState::getInstance();
    }
    else if(ch=='>')
    {    
        _state=DataState::getInstance();
    }
}