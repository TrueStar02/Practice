#ifndef PARSER_HPP_
#define PARSER_HPP_
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)
#include "State.hpp"
#include "Bulider.hpp"
#include <string>
#include <iostream>
using namespace std;

class Parser {
public:
 static Parser* getInstance();
 static void destroyInstance();

 void setState(State* state) { _state = state; }
  Bulider* getBulider() { return _bulider; }

  void read() {
    string line;
    for(int x=0;x<=5;x++)
    {  std::getline(std::cin, line);
      _str += line;
    }
  }
 void parse() {
    int index = 0;
    while (index < _str.size()) {
      cout<<"Process char"<<_str[index]<<endl;
      consumeOneChar(_str[index]);
      cout<<"Process char"<<_str[index]<<endl;
      ++index;
    }
    _bulider->display();
  }

private:
  static Parser* _instance;

  std::string _str;
 State* _state;
  Bulider* _bulider;

 Parser() {
    // default state
    _state = DataState::getInstance();
    _bulider = Bulider::getInstance();
  }
 ~Parser() {
    // destroy ALL states (not only the current one)
    DataState::destroyInstance();
    TagNameState::destroyInstance();
    // destroy the bulider
    Bulider::destroyInstance();
  }
  DISALLOW_COPY_AND_ASSIGN(Parser);

  void consumeOneChar(char ch);
};

#endif