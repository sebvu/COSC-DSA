#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
  // Place your code here to test your solution
  LinkedList intList;

  intList.Append(1);
  intList.Append(3);
  intList.Append(5);
  intList.Append(7);
  intList.Append(9);

  intList.Print();

  intList.DeleteAt(2);

  intList.Print();

  return 0;
}
