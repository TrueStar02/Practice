// Problem#: 17803
// Submission#: 4641757
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <cstring>
#include "Sequence.h"
using namespace std;
Sequence::Sequence() {
 a = new int[1000];
 msize = 0;
 mempty = true;
}
Sequence::~Sequence() {
  delete []a;
}

int Sequence::size() {
 return msize;
}

bool Sequence::empty() {
 return mempty;
}

bool Sequence::find(int value) {
 int i;
 for (i = 0; i < msize; i++) {
  if (a[i] == value) {
   return true;
  }
 }
 return false;
}

int &Sequence::at(int pos) {
 return a[pos]; //ָ�ص�pos��
}

int Sequence::front() {
 return a[0];
}

int Sequence::back() {
 return a[msize - 1];
}

void Sequence::insert(int value) {
 a[msize] = value;
 msize ++;
 mempty = false;
}

void Sequence::insert(int pos, int value) {
 int i;
 for (i = msize; i > pos; i--) {
  a[i] = a[i - 1];
 }
 a[pos] = value;
 msize++;
 mempty = false;
}

void Sequence::clear() {
 delete []a;
 a = new int[1000];
 msize = 0;
 mempty = true;
}

void Sequence::reverse() { //ȫ����ת
 int i, temp;
 for (i = 0; i<= msize / 2 - 1; i++) {
  temp = a[i];
  a[i] = a[msize - 1 - i];
  a[msize - 1 - i] = temp;
 }
}
void Sequence::reverse(int fir, int las) { //�����ﵽ���ﷴת
 int i, temp, j;
 for (i = fir, j = las - 1; i< fir + (las-fir)/ 2; i++,j--) {
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
 }
}
void Sequence::replace(int value1, int value2) {
 int i;
 for (i = 0; i < msize; i++) {
  if(a[i] == value1) {
   a[i] = value2;
  }
 }
}
void Sequence::swap(Sequence &seq2) {
 int  *b;
 b = a;
 int temp = msize;
 bool temp2 = mempty;
 a = seq2.a;
 seq2.a = b;
 msize = seq2.msize;
 mempty = seq2.mempty;
 seq2.msize = temp;
 seq2.mempty = temp2;
}
