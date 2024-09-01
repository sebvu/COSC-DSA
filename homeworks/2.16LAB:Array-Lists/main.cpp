#include "ArrayList.h"
#include <iostream>

using namespace std;

int main() {
  // Place your code here to test your solution
  ArrayList<int> intList;

  intList.append(1);
  intList.append(3);
  intList.append(5);
  intList.append(7);
  intList.append(9);

  intList.print();

  return 0;
}
