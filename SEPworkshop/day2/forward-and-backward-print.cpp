#include <iostream>

void forwardAndBackwards(int x) {

  std::cout << x;

  if (x != 1)
    forwardAndBackwards(x - 1);
  else
    return;
}

int main() { forwardAndBackwards(5); }
