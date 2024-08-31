#include <iostream>

struct node {
  int data;
  node *next;
};

void remove(node *prev) {
  node *temp;
  temp = prev->next;
  prev->next = temp->next;
  delete temp;
}

void insert(node *curr, int data) {
  node *temp = new node;
  temp->data = 5;
  temp->next = curr->next;
  curr->next = temp;
}

// Exercises
// Concatenate two given list into one big list.
// Insert an element in a linked lsit in sorted order. Teh function will be called for every element to be insert.
// Always insert elements at one end, and delete elements from the other end (LIFO)

int main() {}
