#include <iostream>

std::string printRev(std::string s, int start, int end) {

  if (start < end) {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    return printRev(s, start + 1, end - 1);
  }
  return s;
}

int main() {

  std::string word = "computer";

  std::cout << word << std::endl;

  std::string reversedWord = printRev(word, 0, word.length() - 1);

  std::cout << reversedWord << std::endl;

  return 0;
}
