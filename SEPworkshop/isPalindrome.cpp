#include <iostream>

bool isPalindrome(std::string s, int start, int end) {
  if (s.length() <= 1) {
    return true;
  }

  if (start < end) {
    if (s[start] == s[end]) {
      return isPalindrome(s, start + 1, end - 1);
    } else {
      return false;
    }
  }
  return true;
}

int main() {

  std::string word = "racecar"; // true
  std::cout << isPalindrome(word, 0, word.length() - 1);

  word = "a"; // true
  std::cout << isPalindrome(word, 0, word.length() - 1);

  word = "malimpope"; // false
  std::cout << isPalindrome(word, 0, word.length() - 1);
}
