#pragma once
#include <iostream>
#include <string>

template <typename T> class Node {
  private:
  int size;
  T *interactionList;

  public:
  T data;
  Node *next;
  Node(T data, int totalUniqueValues);
  ~Node() { delete[] interactionList; }  // Destructor

  bool orderContains(T value);
  void orderAppend(T value);
  int getSize();
  std::string print();
};

template <typename T> Node<T>::Node(T data, int totalUniqueValues) : data(data), next(nullptr), interactionList(new T[totalUniqueValues]), size(0) {}

template <typename T> bool Node<T>::orderContains(T value) {
  for (int i = 0; i < size; i++) {
    if (interactionList[i] == value) {
      return true;
    }
  }
  return false;
}

template <typename T> void Node<T>::orderAppend(T value) {
  interactionList[size] = value;
  size++;
}

template <typename T> std::string Node<T>::print() {
  std::string printedWords = "";

  std::cout << "size is: " << size << std::endl;
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      std::cout << ", ";
      printedWords.append(", ");
    }
    std::cout << interactionList[i];
    printedWords.append(interactionList[i]);
  }
  std::cout << std::endl;
  return printedWords;
}

template <typename T> int Node<T>::getSize() { return size; }

template <typename T> class LinkedList {
  private:
  Node<T> *head;
  int TOTAL_UNIQUE_VALUES;

  public:
  LinkedList(int totalUniqueValues);
  ~LinkedList();

  void append(T value);                       // append to linked list
  bool contains(T value);                     // check if value exists in linked list
  bool verifyComparison(T main, T stranger);  // verify the comparisons, true or false if the first full match has been made
  std::string printInteractionList(T value);  // print list belonging to value
};

template <typename T> LinkedList<T>::LinkedList(int totalUniqueValues) : head(nullptr), TOTAL_UNIQUE_VALUES(totalUniqueValues) {}

template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *curr = head;

  while (curr != nullptr) {
    Node<T> *tmp = curr;
    curr = curr->next;
    delete tmp;
  }
}

template <typename T> void LinkedList<T>::append(T value) {
  if (head == nullptr) {
    head = new Node<T>(value, TOTAL_UNIQUE_VALUES);
    return;
  }

  Node<T> *curr = head;

  while (curr->next != nullptr)
    curr = curr->next;
  curr->next = new Node<T>(value, TOTAL_UNIQUE_VALUES);
}

template <typename T> bool LinkedList<T>::contains(T value) {
  Node<T> *curr = head;

  while (curr != nullptr) {
    if (curr->data == value)
      return true;
    curr = curr->next;
  }
  return false;
}

template <typename T> bool LinkedList<T>::verifyComparison(T main, T stranger) {
  Node<T> *curr = head;

  while (curr->data != main)
    curr = curr->next;

  if (!curr->orderContains(stranger))
    curr->orderAppend(stranger);

  if (curr->getSize() == TOTAL_UNIQUE_VALUES - 1)  // - 1 to exclude the main word itself
    return true;

  return false;
}

template <typename T> std::string LinkedList<T>::printInteractionList(T value) {
  Node<T> *curr = head;

  while (curr->data != value)
    curr = curr->next;

  return curr->print();
}
