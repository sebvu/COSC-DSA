#include <iostream>

int factorial(int x) {
  if (x == 1)
    return x;

  return x * factorial(x - 1);
}

int main() { std::cout << factorial(5); }
