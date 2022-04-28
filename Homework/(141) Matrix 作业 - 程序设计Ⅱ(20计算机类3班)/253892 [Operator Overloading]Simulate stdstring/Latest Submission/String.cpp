#include "String.h"
#include <iostream>
#include <cstring>
#include <string>
   String::String()
    {
        _buff=new char[1];
        _buff[0]='\0';
    	_length=0;
    	_size=0;
	}
    String::String(const char *src)
    {
    	_size=strlen(src);
    	_buff=new char[_size+1];
    	strcpy(_buff,src);
	}
    String::String(const String &src)
    {
    	_size=src._size;
    	_buff=new char[_size+1];
    	strcpy(_buff,src._buff);
	}
    // destructor
    String::~String()
    {
    	if(_buff!=NULL) delete[] _buff;
	}
    // member methods
    void String::assign(const char *src)
    {
        delete[] _buff;
    	_size=strlen(src);
    	_buff=new char[_size+1];
    	strcpy(_buff,src);
	}
    void String::append(const char &other)
    {	
    	char * temp=_buff;
        _buff=new char[_size+2];
        _size++;
        strcpy(_buff,temp);
        delete[] temp;
        _buff[_size-1]=other;
        _buff[_size]='\0';

	}
    void String::clear()
    {
    	_length=0;
    	_size=0;
        delete[] _buff;
        _buff=new char[1];
        _buff[0]='\0';
	}
    int String::compare(const String &other) const
    {
    	 int i=strcmp(_buff,other._buff);
        if(!i)
        return 0;
        if(i>0)return 1;
        return -1;
	}
    const char* String::c_str() const
    {
    	return _buff;
	}
    bool String::empty() const
    {
    	return !_size;
	}
    int String::find(const String &other, int pos) const
    {
    	 char * t=strstr(_buff+pos,other._buff);
        if(t==NULL)return _size;
        else return t-_buff;

	}
    int String::length() const
    {
    	return _size;
	}
    String String::substr(const int &pos, const int &count) const
    {
    	 char temp[count+1];
        strncpy(temp,_buff+pos,count);
        temp[count]='\0';
        return String(temp);

	}
    // overload operators
    char& String::operator[](const int &index)
    {
    	return _buff[index];
	}
    void String::operator=(const String &other)
    {
      delete[] _buff;
    	_size=other._size;
    	_buff=new char[_size+1];
    	strcpy(_buff,other._buff);
    }
    void String::operator=(const char *src)
    {
        delete[] _buff;
    	_size=strlen(src);
    	_buff=new char[_size+1];
    	strcpy(_buff,src);
    }
    String String::operator+(const String &other) const
    {
      char temp[_size+other._size+1];
        strcpy(temp,_buff);
        strcat(temp,other._buff);
        return String(temp);
    }
    bool String::operator<(const String &other) const{return strcmp(_buff,other._buff)<0;}
    bool String::operator<=(const String &other) const{return strcmp(_buff,other._buff)<=0;}
    bool String::operator>(const String &other) const{return strcmp(_buff,other._buff)>0;}
    bool String::operator>=(const String &other) const{return strcmp(_buff,other._buff)>=0;}
    bool String::operator==(const String &other) const{return strcmp(_buff,other._buff)==0;}
    bool String::operator!=(const String &other) const{return strcmp(_buff,other._buff);}

    // friend methods
  std::ostream& operator<<(std::ostream& out, const String &str)
{
       out<<str._buff;
           return out;
    
}