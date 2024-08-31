#include <iostream>

struct Node {
  int value;
  Node *next;
  Node(int value) : value(value), next(nullptr) {}
};

// recursive method

class linkedList {
  private:
  Node *head;

  public:
  void addAtEnd(int val) {
    if (head == nullptr) {
      head = new Node(val);
      return;
    }

    Node *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = new Node(val);
  }
  // recursive method
  // void print(Node *head) {
  //   if (head == nullptr)
  //     return;
  //   // prints all data contained in a linked list
  //   std::cout << head->value << std::endl;
  //   print(head->next);
  // }
  // iterative method
  void print() {
    Node *curr = head;

    while (curr != nullptr) {
      std::cout << curr->value;
      if (curr->next != nullptr)
        std::cout << " ";
      curr = curr->next;
    }
  }
  void addAtPos(int val, int pos) {
    if (pos < 0)
      return;

    Node *newNode = new Node(val);
    if (pos == 0) {
      newNode->next = head;
      head = newNode;
    }

    Node *curr = head;

    for (int i = 0; i < pos - 1 && curr != nullptr; i++) {
      curr = curr->next;
    }
    if (curr == nullptr) {
      delete curr;
      return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
  }

  void deleteAtHead() {
    Node *temp = head;
    head->next = head;
    delete temp;
  }
};

int main() {
  linkedList list = linkedList();

  const int MAX_NUMBER = 25;
  const int MIN_NUMBER = 0;

  for (int i = MIN_NUMBER; i <= MAX_NUMBER; i++) {
    list.addAtEnd(i);
  }
  list.print();
  list.addAtPos(32, 5);
  std::cout << std::endl;
  list.print();
}
