#pragma once

template <typename T> struct Node {
  T data;
  Node *next;
  Node *prev;
  Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T> class DoublyLinkedList {
  private:
  Node<T> *head;

  public:
};
