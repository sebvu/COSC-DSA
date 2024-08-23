#include <iostream>

long fibs(long num) {

  if (num == 0 || num == 1)
    return 1;

  return fibs(num - 1) + fibs(num - 2);
}

long factorial(long num) {

  if (num == 0 || num == 1)
    return 1;

  return num * factorial(num - 1);
}

int main() {

  long number = 100;

  // long result = factorial(number);

  // std::cout << result << std::endl;

  /* same implemenetation

  result = 1;

  for (int i = 1; i <= 20; i++) {
    result *= i;
  } */

  // std::cout << result << std::endl << "----fibs----" << std::endl;

  // result = fibs(number);

  // std::cout << result << std::endl;

  long last = 1, secondlast = 1;

  for (int i = 2; i <= number; i++) {
    long current = last + secondlast;
    // std::cout << current << std::endl;
    secondlast = last;
    last = current;
  }
  std::cout << last << std::endl;
}
