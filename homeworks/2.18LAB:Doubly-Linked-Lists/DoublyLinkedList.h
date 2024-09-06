#pragma once
#include <iostream>

template <typename T> struct Node {
  T value;
  Node<T> *next;
  Node<T> *prev;
  Node(T value, Node *next = nullptr, Node *prev = nullptr) : value(value), next(next), prev(prev) {}
};

template <typename T> class DoublyLinkedList {
  private:
  Node<T> *head;
  Node<T> *tail;
  int size;

  public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void Append(T value);             // append at the end of the list
  void Prepend(T value);            // prepend to beginning
  T operator[](int index);          // look into this
  bool Find(T value);               // return true if value is found, false otherwise
  void Insert(int index, T value);  // add item at requested index
  bool IsEmpty();                   // return a bool if list is empty
  void Print();                     // print current list in order using -> as the spacers
  void PrintReverse();              // print in reverse with a -> between each item as the spicers
  bool Delete(T value);             // find first occurence and delete. close gap by moving all subs. itmes. return true if item removed and false otherwise
  bool DeleteAt(int index);         // remove item at requested index and close gap. return true or false if index was removed
  int Size();                       // return current number of items in list
};

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
template <typename T> DoublyLinkedList<T>::~DoublyLinkedList() {
  Node<T> *curr = head;

  while (curr != nullptr) {
    Node<T> *tmp = curr->next;
    delete curr;
    curr = tmp;
  }
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T> void DoublyLinkedList<T>::Append(T value) {
  Node<T> *newNode = new Node<T>(value);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  size++;
  return;
}
template <typename T> void DoublyLinkedList<T>::Prepend(T value) {
  Node<T> *newNode = new Node<T>(value);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  size++;
  return;
}
template <typename T> T DoublyLinkedList<T>::operator[](int index) {
  if (index >= size || index < -size)  // must include >=, as -1 is the FIRST prev value.
    return T();

  if (index < 0) {
    Node<T> *curr = tail;
    for (int i = -1; i > index; i--)
      curr = curr->prev;
    return curr->value;
  } else {
    Node<T> *curr = head;
    for (int i = 0; i < index; i++)
      curr = curr->next;
    return curr->value;
  }
}
template <typename T> bool DoublyLinkedList<T>::Find(T value) {
  Node<T> *curr = head;

  while (curr != nullptr) {
    if (curr->value == value)
      return true;
    curr = curr->next;
  }
  return false;
}
template <typename T> void DoublyLinkedList<T>::Insert(int index, T value) {
  bool isNegative = false;

  if (index < 0) {
    isNegative = true;
    index = abs(index);
  }

  if (isNegative) {
    if (index >= size) {
      Prepend(value);
      return;
    }
  } else {
    if (index == 0) {
      Prepend(value);
      return;
    } else if (index >= size) {
      if (isNegative)
        Prepend(value);
      else
        Append(value);
      return;
    }
  }

  Node<T> *newNode = new Node<T>(value);

  if (isNegative) {
    Node<T> *curr = tail;
    for (int i = 1; i < index; i++)
      curr = curr->prev;
    Node<T> *tmp = curr->prev;
    curr->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
    newNode->next = curr;
  } else {
    Node<T> *curr = head;
    for (int i = 1; i < index; i++)
      curr = curr->next;
    Node<T> *tmp = curr->next;
    curr->next = newNode;
    tmp->prev = newNode;
    newNode->next = tmp;
    newNode->prev = curr;
  }
  size++;
  return;
}
template <typename T> bool DoublyLinkedList<T>::IsEmpty() { return size == 0; }
template <typename T> void DoublyLinkedList<T>::Print() {
  Node<T> *curr = head;

  while (curr != nullptr) {
    if (curr != head)
      std::cout << "->";
    std::cout << curr->value;
    curr = curr->next;
  }
  std::cout << std::endl;
}
template <typename T> void DoublyLinkedList<T>::PrintReverse() {
  Node<T> *curr = tail;

  while (curr != nullptr) {
    if (curr != tail)
      std::cout << "->";
    std::cout << curr->value;
    curr = curr->prev;
  }
  std::cout << std::endl;
}
template <typename T> bool DoublyLinkedList<T>::Delete(T value) {
  Node<T> *curr = head;

  while (curr != nullptr) {
    if (curr->value == value) {
      Node<T> *tmp = curr;
      if (curr == head && curr == tail) {
        head = nullptr;
        tail = nullptr;
      } else if (curr == head) {
        head = curr->next;
        head->prev = nullptr;
      } else if (curr == tail) {
        tail = curr->prev;
        tail->next = nullptr;
      } else {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
      }
      delete tmp;
      size--;
      return true;
    }
    curr = curr->next;
  }
  return false;
}
template <typename T> bool DoublyLinkedList<T>::DeleteAt(int index) {
  if (size == 0)
    return false;

  bool isNegative = false;

  if (index < 0) {
    isNegative = true;
    index = abs(index);
  }

  if (isNegative) {
    if (index > size) {
      return false;
    } else if (index == 1) {
      Node<T> *tmp = tail;
      if (size == 1) {
        head = nullptr, tail = nullptr;
      } else {
        tail = tail->prev;
        tail->next = nullptr;
      }
      delete tmp;
    } else if (index == size) {
      Node<T> *tmp = head;
      head = head->next;
      head->prev = nullptr;
      delete tmp;
    } else {
      Node<T> *curr = head;
      for (int i = 1; i < index; i++)
        curr = curr->prev;
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      delete curr;
    }
  } else {
    if (index >= size) {
      return false;
    } else if (index == 0) {
      Node<T> *tmp = head;
      if (size == 1) {
        head = nullptr, tail = nullptr;
      } else {
        head = head->next;
        head->prev = nullptr;
      }
      delete tmp;
    } else if (index == size - 1) {
      Node<T> *tmp = tail;
      tail = tail->prev;
      tail->next = nullptr;
      delete tmp;
    } else {
      Node<T> *curr = head;
      for (int i = 0; i < index; i++)
        curr = curr->next;
      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;
      delete curr;
    }
  }
  size--;
  return true;
}
template <typename T> int DoublyLinkedList<T>::Size() { return size; }
