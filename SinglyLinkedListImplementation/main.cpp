#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "NullDereference"

#include <iostream>
#include <string>

using namespace std;

class Iterator {
public:
  explicit Iterator(string *data) : data(std::move(*data)), next(nullptr) {}
  
  string data;
  Iterator *next;
  
  friend istream &operator>>(istream &, Iterator &);
  
  friend ostream &operator<<(ostream &, Iterator &);
};

class LinkedList {
public:
  LinkedList() : head(nullptr) {}
  
  ~LinkedList();
  
  void insert(string *data, size_t index);
  
  [[nodiscard]] size_t len() const {
    size_t length = 0;
    Iterator *temp = head;
    while (temp) {
      length++;
      temp = temp->next;
    }
    return length;
  }
  
  void pop_back() {
    if (head) {
      Iterator *temp = head->next;
      delete head;
      head = temp;
    }
  }
  
  void push(string *data);

private:
  Iterator *head;
  
  friend istream &operator>>(istream &, LinkedList &);
  
  friend ostream &operator<<(ostream &, const LinkedList &);
  
  static void deallocateMemory(Iterator *node);
  
  static void insert(string *data, Iterator **iter);
};

int main() {
  LinkedList list;
  cin >> list;
  string s;
  getline(cin, s);
  while (s != "Exit") {
    if (s == "DeleteLeft")
      list.pop_back();
    else if (s == "AddRight") {
      getline(cin, s);
      list.push(&s);
    } else if (s == "AddLeft") {
      getline(cin, s);
      list.insert(&s, (size_t) 0);
    }
    getline(cin, s);
  }
  cout << list.len() << endl;
  cout << list;
  return 0;
}

istream &operator>>(istream &in, Iterator &iterator) {
  in >> iterator.data;
  return in;
}

istream &operator>>(istream &in, LinkedList &List) {
  int n;
  in >> n;
  string str;
  getline(in, str); // truncate the input
  Iterator **iter = &List.head;
  while (n > 0) {
    getline(in, str);
    *iter = new Iterator(&str);
    n--;
    iter = &(*iter)->next;
  }
  return in;
}

ostream &operator<<(ostream &out, const LinkedList &List) {
  Iterator *iter = List.head;
  while (iter) {
    out << *iter << endl;
    iter = iter->next;
  }
  return out;
}

ostream &operator<<(ostream &out, Iterator &iterator) {
  return out << iterator.data;
}

LinkedList::~LinkedList() {
  deallocateMemory(head);
}

void LinkedList::deallocateMemory(Iterator *node) {
  if (node) {
    deallocateMemory(node->next);
    delete node;
  }
}

void LinkedList::insert(string *data, size_t index) {
  Iterator *temp;
  if (index == 0) {
    temp = head;
    head = new Iterator(data);
    head->next = temp;
  } else {
    Iterator *previous = nullptr;
    temp = head;
    while (index && temp) {
      index--;
      previous = temp;
      temp = temp->next;
    }
    if (!index) {
      previous->next = new Iterator(data);
      previous->next->next = temp;
    }
  }
}

void LinkedList::insert(string *data, Iterator **iter) {
  if (*iter)
    insert(data, &(*iter)->next);
  else *iter = new Iterator(data);
}

void LinkedList::push(std::string *data) {
  LinkedList::insert(data, &head);
}

#pragma clang diagnostic pop
