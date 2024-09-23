#include <iostream>
#include <map>
#include <stack>

bool ValidParenthesis(std::string string) {
  std::map<char, char> closingPair{{'(', ')'}, {'{', '}'}, {'[', ']'}};
  std::stack<char> stack;

  for (int i = 0; i < string.size(); i++) {
    if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
      stack.push(closingPair[string[i]]);
    } else {
      if (stack.empty() || stack.top() != string[i]) {
        return false;
      } else {
        stack.pop();
      }
    }
  }
  return stack.empty();
}

int main() { std::cout << ValidParenthesis("{()()}}"); }
