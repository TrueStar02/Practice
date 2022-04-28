#include "Biginteger.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::ostream;
 
// default constructor
BigInteger::BigInteger() {
  data_ = NULL;
  size_ = 0;
}
 
// constructor
BigInteger::BigInteger(const string& number) {
  size_ = number.length();
  data_ = new int[size_];
  for (int i = 0, j = size_-1; i < size_; i++, j--) {
    data_[i] = number[j] - '0';
  }
}
 
// constructor
BigInteger::BigInteger(const BigInteger& other) {
  size_ = other.size_;
  data_ = new int[size_];
  for (int i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}
 
// destructor
BigInteger::~BigInteger() {
  delete []data_;
}
 
// overload '<<'
ostream& operator<<(ostream& out, const BigInteger& Bint) {
  for (int i = Bint.size_ - 1; i >= 0; i--) {
    out << Bint.data_[i];
  }
  return out;
}
 
// overload '+'
BigInteger operator+(const BigInteger& left,
                      const BigInteger& right) {
  BigInteger temp;
  int minSize;
  bool flag = false;  // right bigger
 
  // find the bigger one
  if (left.size_ > right.size_) {
    temp.size_ = left.size_;
    flag = true;
  } else {
    temp.size_ = right.size_;
  }
 
  // caculate
  temp.data_ = new int[temp.size_+1];
  minSize = left.size_ + right.size_ - temp.size_;
  for (int i = 0; i < temp.size_; i++) {
    if (i < minSize) {
      temp.data_[i] = left.data_[i] + right.data_[i];
    } else {
      temp.data_[i] = (flag ? left.data_[i] : right.data_[i]);
    }
  }
  temp.data_[temp.size_] = 0;
 
  // deal with the carry
  for (int i = 0; i < temp.size_; i++) {
    if (temp.data_[i] >= 10) {
      temp.data_[i+1]++;
      temp.data_[i] -= 10;
    }
  }
  if (temp.data_[temp.size_] > 0) {
    temp.size_++;
  }
  return temp;
}
 
// overload '-'
// promise that left >= right
BigInteger operator-(const BigInteger& left,
                     const BigInteger& right) {
  BigInteger temp;
  temp.size_ = left.size_;
  temp.data_ = new int[temp.size_];
 
  // caculate
  for (int i = 0; i < left.size_; i++) {
    if (i < right.size_) {
      temp.data_[i] = left.data_[i] - right.data_[i];
    } else {
      temp.data_[i] = left.data_[i];
    }
  }
 
  // deal with the carry
  for (int i = 0; i < temp.size_-1; i++) {
    if (temp.data_[i] < 0) {
      temp.data_[i+1]--;
      temp.data_[i] += 10;
    }
  }
  if (temp.data_[temp.size_-1] != 0)
    return temp;
  temp.size_--;
  for (int i = temp.size_-1; i >= 0 ; i--) {
    if  (temp.data_[i] == 0) {
      temp.size_--;
    } else {
      break;
    }
  }
  if (temp.size_ == 0)
    temp.size_ = 1;
  return temp;
}