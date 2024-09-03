#include "ArgumentManager.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <string>

int getMaxUniqueValues(ifstream &fin) {
  std::string stringNumber = "";

  getline(fin, stringNumber);

  return stoi(stringNumber);
}

template <typename T> void returnOutput(ofstream &fout, LinkedList<T> &list, T value) {
  fout << "First: " << value << std::endl;
  fout << list.printInteractionList(value);
}

int main(int argc, char *argv[]) {

  for (int i = 1; i <= 3; i++) {

    std::string inputTextFile = "input" + std::to_string(i) + ".txt";
    std::string outputTextFile = "output" + std::to_string(i) + ".txt";

    ArgumentManager am(argc, argv);
    string input = inputTextFile;   /* am.get("input"); */
    string output = outputTextFile; /* am.get("output"); */
    ifstream fin(input);
    ofstream fout(output);

    if (!fin.is_open()) {
      std::cerr << "\033[1;31mFile did not open.\033[0m" << std::endl;
      return 1;
    }

    int const MAX_UNIQUE_VALUES = getMaxUniqueValues(fin);

    LinkedList<std::string> list(MAX_UNIQUE_VALUES);

    std::cout << MAX_UNIQUE_VALUES << std::endl;

    std::string line;

    while (getline(fin, line)) {
      int delimeter = line.find(" ");
      std::string value1 = line.substr(0, delimeter), value2 = line.substr(delimeter + 1, line.length());

      if (!list.contains(value1))
        list.append(value1);

      if (list.verifyComparison(value1, value2)) {
        returnOutput(fout, list, value1);
        break;
      }

      if (!list.contains(value2))
        list.append(value2);

      if (list.verifyComparison(value2, value1)) {
        returnOutput(fout, list, value2);
        break;
      }
    }
  }
}
