#include "ArrayList.h"
// #include "DoublyLinkedList.h"
// #include "SinglyLinkedList.h"
#include <iostream>
#include <random>

// Knowledge checking for ArrayList, and LinkedLists.
// All implementations are using templates, and will demonstrate sorting.

int main() {

  std::cout << "Array List Implementation" << std::endl << "----------" << std::endl;
  ArrayList<int> intList;

  for (int i = 0; i < 20; i++) {
    std::random_device randomWordIndex;
    std::uniform_int_distribution<int> dist(0, 10000);  // INDEXED ZERO. have to do - 1 because it is 1 value above the actual max index
    if (i == 15)
      intList.append(1008500);
    intList.append(dist(randomWordIndex));
  }

  std::cout << "Size of Array: " << intList.getSize() << "\nCapacity of Array: " << intList.getCapacity() << std::endl;
  intList.print();
  intList.removeAt(3);
  std::cout << "Removed index 3" << std::endl;
  std::cout << "Size of Array: " << intList.getSize() << "\nCapacity of Array: " << intList.getCapacity() << std::endl;
  intList.print();
  intList.remove(1008500);
  std::cout << "Removed number 1008500" << std::endl;
  std::cout << "Size of Array: " << intList.getSize() << "\nCapacity of Array: " << intList.getCapacity() << std::endl;
  intList.print();

  std::cout << "Array List Sorted" << std::endl;

  intList.sort();
  intList.print();
  std::cout << std::endl;

  std::cout << "Singly Linked List Implementation" << std::endl;

  std::cout << "Singly Linked List Sorted" << std::endl;

  std::cout << "Doubly Linked List Implementation" << std::endl;

  std::cout << "Doubly Linked List Sorted" << std::endl;
}
