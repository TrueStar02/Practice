#include<iostream>
#include "Bulider.hpp"
using namespace std;

Bulider* Bulider::getInstance(){return _instance;}
void Bulider::destroyInstance(){delete _instance;}
void Bulider::handleOneToken(Token token)
{   if(_error)return;
    if(token.type=="0") 
    {   token.depth=_stack.size();
        int x=token.content.find_first_not_of(" \n"),y=token.content.find_last_not_of("\n ");
        if(x!=string::npos)
        {token.content=string(token.content.begin()+x,token.content.begin()+y+1);
        if(token.content!="")
            _tokens.push_back(token);
        }
    }
    else if(token.type=="1")
    {   token.depth=_stack.size();
        
        _tokens.push_back(token);
        _stack.push(token);
    }
    else if(token.type=="2")
    {   if(!_stack.size())_error=1;
        else if(token.content==_stack.top().content)
            _stack.pop();
        else
            _error=1;
    }
    else
        _error=1;
}
void Bulider::display()
{   if(_error||_stack.size())
        cout<<"INVALID INPUT\n";
    else
    {   for(int x=0;x<_tokens.size();x++)
        {   for(int y=0;y<_tokens[x].depth;y++)
                cout<<"  ";
            cout<<_tokens[x].content;
            if(_tokens[x].type=="1")
            cout<<":";
            cout<<endl;
        }
    }
}