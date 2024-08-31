#pragma once
#include <iostream>
using namespace std;

struct Node {
  int value;
  Node *next = nullptr;
  Node(int val, Node *nxt = nullptr) {
    value = val;
    next = nxt;
  }
};

class LinkedList {
  public:
  LinkedList();   // Default Constructor
  ~LinkedList();  // Destructor

  void Append(int value);             // Add a value to the end of the list
  int Get(int index);                 // Return the value at the index requested, or 0
  bool Find(int value);               // Returns true if the value is found and false if not
  void Insert(int index, int value);  // Insert value at index
  bool IsEmpty();                     // True if the list is currently empty
  void Print();
  bool Delete(int value);    // Delete the first occurrence of value; true if successful
  bool DeleteAt(int index);  // Delete the value at the location; true if successful
  int Size();                // Number of elements in the list

  private:
  Node *head;  // Items are linked to the head
  int size;
};

LinkedList::LinkedList() {
  head = nullptr;
  size = 0;
}

LinkedList::~LinkedList() {}  // Destructor

void LinkedList::Append(int value) {

  Node *temp = new Node(value);
  if (head == nullptr) {
    head = temp;
    size++;
    return;
  }

  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = temp;
  size++;
}

int LinkedList::Get(int index) {
  if (index < 0 || index >= size)
    return 0;

  Node *curr = head;

  for (int i = 0; i < index; i++)
    curr = curr->next;
  return curr->value;
}

bool LinkedList::Find(int value) {
  Node *curr = head;

  while (curr->value != value) {
    if (curr->next == nullptr)
      return false;
    else
      curr = curr->next;
  }
  return true;
}

void LinkedList::Insert(int index, int value) {
  if (index < 0 || index >= size)
    return;

  Node *newNode = new Node(value);

  if (index == 0) {
    head = newNode;
    size++;
    return;
  }

  Node *curr = head;

  for (int i = 0; i < index - 1; i++)
    curr = curr->next;

  newNode->next = curr->next;
  curr->next = newNode;
  size++;
}

bool LinkedList::IsEmpty() { return size == 0; }

void LinkedList::Print() {

  Node *curr = head;

  while (curr != nullptr) {
    if (curr != head)
      std::cout << "->";
    std::cout << curr->value;
    curr = curr->next;
  }

  std::cout << std::endl;
}

bool LinkedList::Delete(int value) {

  if (head->value == value) {
    Node *temp = head;
    head = head->next;
    size--;
    delete temp;
    return true;
  }

  Node *curr = head;

  while (curr->next != nullptr) {
    if (curr->next->value == value) {
      Node *temp = curr->next;
      curr->next = curr->next->next;
      size--;
      delete temp;
      return true;
    }
    curr = curr->next;
  }
  return false;
}

bool LinkedList::DeleteAt(int index) {
  if (index < 0 || index >= size)
    return false;
  if (index == 0) {
    Node *temp = head;
    head = head->next;
    size--;
    delete temp;
    return true;
  }

  Node *curr = head;

  for (int i = 0; i < index - 1; i++)
    curr = curr->next;

  Node *temp = curr->next;
  curr->next = curr->next->next;
  size--;
  delete temp;

  return true;
}

int LinkedList::Size() { return size; }
