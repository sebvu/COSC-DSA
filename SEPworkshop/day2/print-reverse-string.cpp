#include <iostream>

void reverse(std::string word, int x) {

  std::cout << word[x];

  if (x == 0)
    return;
  else
    reverse(word, x - 1);
}

int main() {

  std::string word = "hallo";

  reverse(word, word.length());
}
