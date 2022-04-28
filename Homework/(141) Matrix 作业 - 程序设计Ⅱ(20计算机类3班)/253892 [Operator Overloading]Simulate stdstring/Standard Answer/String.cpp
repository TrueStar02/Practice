#include "String.h"
#include <cstdio>
#include <cstring>
 
char String::_error_sign = '\0';
 
String::String() {
  _buff = 0;
  _length = 0;
  _size = 0;
}
 
String::String(const char *src) {
  _size = std::strlen(src) + 1;
  _buff = new char[_size];
  std::memset(_buff, 0, _size);
  std::snprintf(_buff, _size, "%s", src);
  _length = std::strlen(_buff);
}
 
String::String(const String &src) {
  _length = src._length;
  _size = src._size;
  _buff = new char[_size];
  std::memset(_buff, 0, _size);
  std::snprintf(_buff, _size, "%s", src._buff);
}
 
String::~String() {
  if (_buff)
    delete[] _buff;
}
 
void String::assign(const char *src) {
  this->clear();
  _size = std::strlen(src) + 1;
  _buff = new char[_size];
  std::memset(_buff, 0, _size);
  std::snprintf(_buff, _size, "%s", src);
  _length = std::strlen(_buff);
}
 
void String::append(const char &other) {
  if (this->empty()) {
    this->assign("A");
    _buff[0] = other;
  } else {
    if (_length + 1 < _size) {
      _buff[_length++] = other;
    } else {
      _size *= 2;
      char *new_buff = new char[_size];
      std::memset(new_buff, 0, _size);
      snprintf(new_buff, _size, "%s", _buff);
      delete[] _buff;
      _buff = new_buff;
      _buff[_length++] = other;
    }
  }
}
 
void String::clear() {
  _length = _size = 0;
  if (_buff) {
    delete[] _buff;
    _buff = 0;
  }
}
 
int String::compare(const String &other) const {
  int len = (_length > other._length ? other._length : _length);
  for (int i = 0; i < len; ++i) {
    if (_buff[i] < other._buff[i])
      return -1;
    else if (_buff[i] > other._buff[i])
      return 1;
  }
  if (_length < other._length)
    return -1;
  else if (_length > other._length)
    return 1;
  else
    return 0;
}
 
const char* String::c_str() const {
  if (!this->empty())
    return _buff;
  else
    return "";
}
 
bool String::empty() const {
  if (_length == 0 )
    return true;
  else
    return false;
}
 
int String::find(const String &other, int pos) const {
  if (other.empty())
    return -3;
  if (pos >= _length || pos < 0)
    return -2;
  if (other._length > _length - pos)
    return -1;
  int* overlay_value = new int[other._length + 1];
  overlay_value[0] = -1;
  int i, index = 0, p_index = 0, t_index = pos;
  for (i = 1; i < other._length; ++i) {
    index = overlay_value[i - 1];
    while (index >= 0 && other._buff[index + 1] != other._buff[i])
      index = overlay_value[index];
    if (other._buff[index + 1] == other._buff[i]) {
      overlay_value[i] = index + 1;
    } else {
      overlay_value[i] = -1;
    }
  }
  while (p_index < other._length && t_index < _length) {
    if (_buff[t_index] == other._buff[p_index]) {
      ++t_index;
      ++p_index;
    } else if (p_index == 0) {
      ++t_index;
    } else {
      p_index = overlay_value[p_index - 1] + 1;
    }
  }
  delete[] overlay_value;
  if (p_index == other._length) {
    return t_index - p_index;
  } else {
    return _length;
  }
}
 
int String::length() const {
  return _length;
}
 
String String::substr(const int &pos, const int &count) const {
  String ret;
  if (pos >= _length || pos + count > _length)
    return ret;
  ret._buff = new char[count + 1];
  ret._size = count + 1;
  std::memset(ret._buff, 0, ret._size);
  std::snprintf(ret._buff, count + 1, "%s", _buff + pos);
  ret._length = std::strlen(ret._buff);
  return ret;
}
 
char& String::operator[](const int &index) {
  if (index >= 0 && index < _length)
    return _buff[index];
  else
    return _error_sign;
}
 
void String::operator=(const String &other) {
  this->assign(other.c_str());
}
 
void String::operator=(const char *src) {
  this->assign(src);
}
 
String String::operator+(const String &other) const {
  String ret;
  ret._size = _length + other._length + 1;
  ret._buff = new char[ret._size];
  std::snprintf(ret._buff, _length + 1, "%s", _buff);
  std::snprintf(ret._buff + _length, other._length + 1, "%s", other._buff);
  ret._length = std::strlen(ret._buff);
  return ret;
}
 
bool String::operator<(const String &other) const {
  return this->compare(other) == -1 ? true : false;
}
 
bool String::operator<=(const String &other) const {
  return this->compare(other) == 1 ? false : true;
}
 
bool String::operator>(const String &other) const {
  return this->compare(other) == 1 ? true : false;
}
 
bool String::operator>=(const String &other) const {
  return this->compare(other) == -1 ? false : true;
}
 
bool String::operator==(const String &other) const {
  return this->compare(other) == 0 ? true : false;
}
 
bool String::operator!=(const String &other) const {
  return this->compare(other) == 0 ? false : true;
}
 
std::ostream& operator<<(std::ostream& out, const String &str) {
  out << str.c_str();
  return out;
}