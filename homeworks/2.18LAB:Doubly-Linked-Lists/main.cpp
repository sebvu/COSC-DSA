#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
  // Place your code here to test your solution
  DoublyLinkedList<int> list;

  list.Insert(-5, 5);

  list.Print();

  std::cout << list.IsEmpty() << std::endl;

  list.Append(55);

  list.Print();

  std::cout << list.IsEmpty() << std::endl;

  list.DeleteAt(0);

  list.Print();

  std::cout << list.IsEmpty() << std::endl;

  list.DeleteAt(0);

  list.Print();

  std::cout << list.IsEmpty() << std::endl;

  return 0;
}
