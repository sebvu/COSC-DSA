#pragma once
#include <iostream>

template <typename T> struct Node {
  T data;
  Node *next;
  Node(T data, Node *next = nullptr) : data(data), next(next) {}
};

template <typename T> class singlyLinkedList {
  private:
  Node<T> *head;
  int size;

  public:
  singlyLinkedList();
  ~singlyLinkedList();

  void append(T value);        // Append new value to linked list
  void print();                // Print current linked list implementation
  int getSize(Node<T> *head);  // return size
};

template <typename T> singlyLinkedList<T>::singlyLinkedList() : size(0), head(nullptr) {}

template <typename T> singlyLinkedList<T>::~singlyLinkedList() {
  Node<T> *curr = head;
  while (curr != nullptr) {
    Node<T> *next = curr->next;
    delete curr;
    curr = next;
  }
}

template <typename T> void singlyLinkedList<T>::append(T value) {
  if (size == 0) {
    head = new Node<T>(value);
  } else {
    Node<T> *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = new Node<T>(value);
  }
  size++;
}

// template <typename T> int singlyLinkedList<T>::getSize() { return size; }

template <typename T> void singlyLinkedList<T>::print() {

  Node<T> *curr = head;

  while (curr != nullptr) {
    std::cout << curr->data << "->";
    curr = curr->next;
  }
  std::cout << "nullptr" << std::endl;
}

template <typename T> int getSize(Node<T> *head) {
  if (head == nullptr)
    return 0;

  return 1 + getSize(head->next);
}
