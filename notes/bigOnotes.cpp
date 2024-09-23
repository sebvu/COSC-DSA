#include <iostream>

struct Node {
  int value;
  Node *next;
  Node(int value, Node *next = nullptr) : value(value), next(next) {}
};

void Print(Node *head) {
  Node *curr = head;

  while (curr != nullptr) {
    if (curr != head)
      std::cout << "->";
    std::cout << curr->value;
    curr = curr->next;
  }
  std::cout << std::endl;
}

void PrintReverse(Node *current) {
  if (current == nullptr) {
    return;
  }
  PrintReverse(current->next);
  std::cout << current->value << "->";
}

int main() {
  Node *head = new Node(1);
  head = new Node(2, head);

  Print(head);
  PrintReverse(head);

  return 0;
}
