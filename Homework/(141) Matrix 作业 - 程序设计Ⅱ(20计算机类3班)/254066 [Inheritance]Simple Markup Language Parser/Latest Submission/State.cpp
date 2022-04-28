#include "State.hpp"
#include<iostream>
#include<cctype>
using namespace std;

State* DataState::getInstance()
{return _instance;}
void DataState::destroyInstance()
{delete _instance;}

void DataState::handleOneChar(Parser* parser, char ch)
{   
    
    if(ch=='>')
    {   
            _cache+=ch;
        emit(Bulider::getInstance());
    }
    else if(ch=='<')
    {   emit(Bulider::getInstance());

    }
    else
    {   if(ch!='\n')
        _cache+=ch;

    }

}
void DataState::emit(Bulider* dest)
{   Token t;
    if(_cache.length()&&_cache[_cache.length()-1]=='>')
    {   t.type="3";
        dest->handleOneToken(t);
    }
    else
    {   t.type="0";
        t.content=_cache;
        dest->handleOneToken(t);
    }
    _cache="";
}
State* TagNameState::getInstance()
{return _instance;}
void TagNameState::destroyInstance()
{delete _instance;}

void TagNameState::handleOneChar(Parser* parser, char ch)
{   
    if(ch=='<')
    {   _cache+=ch;
        emit(Bulider::getInstance());

    }
    else if(ch=='>')
        emit(Bulider::getInstance());
    else
        _cache+=ch;

}
void TagNameState::emit(Bulider* dest)
{   Token t;
    if(_cache[_cache.length()&&_cache.length()-1]=='<')
    {   t.type="3";
        dest->handleOneToken(t);
    }
    else if(_cache.length()&&_cache[0]=='/')
    {   t.type="2";
        t.content=string(_cache.begin()+1,_cache.end());
        dest->handleOneToken(t);
    }
    else
    {   t.type="1";
        t.content=_cache;
        dest->handleOneToken(t);
    }
    _cache="";

}