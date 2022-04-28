#include "List.hpp"
#include <string>
#include <sstream>
#include <assert.h>
#include <exception>

void list::clear() {
  listPointer p = this->head;
  listPointer q = NULL;
  while (p != NULL) {
    q = p;
    p = p->next;
    delete q;
  }
  this->head = NULL;
  this->_size = 0;
}

list::list() {
  this->head = this->tail = NULL;
  this->_size = 0;
}

list::list(const list& another) {
  this->head = this->tail = NULL;
  this->_size = 0;
  this->assign(another);
}

list::list(const data_type datas[], int length) {
  this->head = this->tail = NULL;
  this->_size = 0;
  this->assign(datas, length);
}

list& list::operator=(const list& another) {
    this->assign(another);
    return *(this);
}

list::~list() { this->clear(); }

bool list::empty() const { return this->_size == 0; }

list::size_type list::size() const { return this->_size; }

list::data_type& list::front() const {
  return this->empty() ? *reinterpret_cast<data_type*>(NULL) : head->data;
}

list::data_type& list::back() const {
  return this->empty() ? *reinterpret_cast<data_type*>(NULL) : tail->data;
}

inline std::string int2String(int a) {
  std::stringstream ss;
  ss << a;
  return ss.str();
}

std::string list::toString(void) const {
  if (this->_size == 0) {
    return "NULL";
  }
  std::string ret;
  listPointer p = this->head;
  ret += "NULL<-";
  while (p != NULL) {
    ret += int2String(p->data);
    if (p != this->tail) {
      ret += "<->";
    }
    p = p->next;
  }
  ret += "->NULL";
  return ret;
}

void list::assign(const list& another) {
  if (!(this == &another)) {
    this->clear();
    node* p = another.head;
    while (p != NULL) {
      this->push_back(p->data);
      p = p->next;
    }
  }
}

void list::assign(const data_type datas[], int length) {
  this->clear();
  for (int i = 0; i < length; i++) {
    this->push_back(datas[i]);
  }
}

void list::push_front(const data_type& data) {
  this->insert(0, data);
  assert(this->head->data == data);
}

void list::push_back(const data_type& data) {
  this->insert(this->_size, data);
  assert(this->tail->data == data);
}

void list::pop_front(void) { this->erase(0); }

void list::pop_back(void) { this->erase(this->_size - 1); }

void list::insert(int position, const data_type& data) {
  if (position == 0) {
    listPointer temp = new listNode(data, this->head);
    this->head = temp;
    assert(this->head != NULL);
    if (this->_size == 0) {
      this->tail = this->head;
    } else {
      this->head->next->prev = head;
    }
    this->_size++;
  } else if (position == this->_size) {
    listPointer temp = new listNode(data, NULL, this->tail);
    this->tail->next = temp;
    this->tail = this->tail->next;
    this->_size++;
  } else {
    listPointer p = at(position - 1);
    if (p != NULL) {
      listPointer temp = new listNode(data, p->next, p);
      p->next->prev = temp;
      p->next = temp;
      this->_size++;
      assert(this->at(position)->data == data);
    }
  }
}

void list::erase(int position) {
  if (this->empty()) return;
  if (position == 0) {
    if (this->_size == 1) {
      delete this->head;
      this->tail = this->head = NULL;
    } else {
      assert(head->next != NULL);
      this->head = this->head->next;
      delete this->head->prev;
      this->head->prev = NULL;
      this->_size--;
    }
  } else if (position == this->_size - 1) {
    this->tail = this->tail->prev;
    assert(tail != NULL);
    delete this->tail->next;
    this->tail->next = NULL;
    this->_size--;
  } else {
    listPointer p = at(position);
    if (p != NULL) {
      p->prev->next = p->next;
      p->next->prev = p->prev;
      delete p;
      this->_size--;
    }
  }
}

void list::split(int position, list* dest1, list* dest2) {
  if (dest1 == dest2) {
    throw dest1;
    return;
  }
  if (position < 0 || position > this->_size) return;
  listPointer p = this->head;
  int counter = 0;
  list temp1, temp2;
  while (p != NULL) {
    if (counter == position) {
      break;
    }
    temp1.push_back(p->data);
    p = p->next;
    counter++;
  }
  while (p != NULL) {
    temp2.push_back(p->data);
    p = p->next;
  }
  (*dest1) = temp1;
  (*dest2) = temp2;
}

list& list::merge(const list& src1, const list& src2) {
  list temp;
  if (src1.empty()) {
    temp = src2;
  } else {
    temp = src1;
    listPointer p = src2.head;
    while (p != NULL) {
      temp.push_back(p->data);
      p = p->next;
    }
  }
  *(this) = temp;
  return *(this);
}

list& list::remove_if(bool (*condition)(list::listPointer)) {
  listPointer p = this->head;
  while (p != NULL) {
    if (condition(p)) {
      if (p == this->head) {
        this->head = this->head->next;
        if (this->head != NULL) {
          this->head->prev = NULL;
        }
        delete p;
        this->_size--;
        p = this->head;
        if (p == NULL) {
          this->tail = NULL;
        }
      } else if (p == this->tail) {
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        delete p;
        this->_size--;
        p = NULL;
      } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        listNode* q = p->next;
        delete p;
        p = q;
        this->_size--;
      }
    } else {
      p = p->next;
    }
  }
  return *(this);
}

list& list::unique(void) {
  listPointer slow, fast;
  slow = this->head;
  while (slow != NULL) {
    fast = slow->next;
    while (fast != NULL) {
      if (fast->data == slow->data) {
        if (fast == this->head) {
          this->head = this->head->next;
          if (this->head != NULL) {
            this->head->prev = NULL;
          } else {
            this->tail = NULL;
          }
          fast = this->head;
        } else if (fast == this->tail) {
          this->tail = this->tail->prev;
          this->tail->next = NULL;
          delete fast;
          fast = NULL;
        } else {
          fast->next->prev = fast->prev;
          fast->prev->next = fast->next;
          listPointer temp = fast;
          fast = fast->next;
          delete temp;
        }
        this->_size--;
      } else {
        fast = fast->next;
      }
    }
    slow = slow->next;
  }
  return *(this);
}

list& list::reverse(void) {
  listPointer p = this->head;
  while (p != NULL) {
    listPointer q = p->prev;
    p->prev = p->next;
    p->next = q;
    p = p->prev;
  }
  listPointer q = this->tail;
  this->tail = this->head;
  this->head = q;
  return *(this);
}

list::data_type& list::operator[](int index) {
  listPointer p = at(index);
  assert(p != NULL);
  return p->data;
}

list& list::operator+=(const list& another) {
  return this->merge(*this, another);
}

std::ostream& operator<<(std::ostream& os, const list& li) {
  return (os << li.toString());
}

