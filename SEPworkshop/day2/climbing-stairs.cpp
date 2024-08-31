#include <iostream>

int climbingStairs(int n) {
  if (n == 0)
    return 1;
  else if (n == -1)
    return 0;
  else
    return climbingStairs(n - 1) + climbingStairs(n - 2);
}

int main() { std::cout << climbingStairs(5); }
