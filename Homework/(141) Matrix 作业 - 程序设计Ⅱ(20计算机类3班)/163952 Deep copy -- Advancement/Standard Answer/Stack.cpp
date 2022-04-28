#include "Stack.hpp"
#include <iostream>

Stack::Stack() {
  p.data = NULL;
  p.count = NULL;
}

Stack::Stack(const Stack& other) {
  if (other.empty()) {
    p.data = NULL;
    p.count = NULL;
  } else {
    p.data = other.p.data;
    p.count = other.p.count;
    (*p.count)++;
  }
}

Stack::~Stack() {
  clear();
  p.data = NULL;
  p.count = NULL;
}

Stack Stack::operator=(const Stack& other) {
  if (&other == this) { return *this; }
  clear();

  if (other.empty()) {
    p.data = NULL;
    p.count = NULL;
  } else {
    p.data = other.p.data;
    p.count = other.p.count;
    (*p.count)++;
  }
  return *this;
}

void Stack::push(int num) {
  copyOnWrite();
  node* newNode = new node(num, p.data);
  p.data = newNode;
}

void Stack::pop() {
  copyOnWrite();
  if (p.data != NULL) {
    node* temp = p.data;
    p.data = p.data->next;
    delete temp;
  }
}

int Stack::top() const {
  if (!empty()) {
    return p.data->num;
  } else {
    return 0;
  }
}

bool Stack::empty() const {
  return p.data == NULL;
}

void Stack::clear() {
  if (p.count == NULL) { return; }

  if (*(p.count) > 1) {
    (*p.count)--;
    p.count = NULL;
    p.data = NULL;
  } else {
    while (p.data != NULL) {
      node* temp = p.data;
      p.data = p.data->next;
      delete temp;
    }
    p.data = NULL;

    delete p.count;
    p.count = NULL;

  }
}

void Stack::copyOnWrite() {
  if (p.count == NULL) {
    p.count = new int(1);
  } else if (*(p.count) > 1) {
    *(p.count)--;

    p.count = new int(1);

    node* other = p.data;
    p.data = new node(other->num);
    node* curp = p.data;
    for (other = other->next; other != NULL; other = other->next) {
      curp->next = new node(other->num);
      curp = curp->next;
    }
  }
}
