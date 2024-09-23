#include "ArgumentManager.h"
#include "LinkedList.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {

  for (int i = 1; i <= 3; i++) {

    std::string inputTextFile = "input" + std::to_string(i) + ".txt";
    std::string outputTextFile = "output" + std::to_string(i) + ".txt";

    ArgumentManager am(argc, argv);
    string input = inputTextFile;   /* am.get("input"); */
    string output = outputTextFile; /* am.get("output"); */
    ifstream fin(input);
    ofstream fout(output);

    int MAX_UNIQUE_VALUES = 0;

    fin >> MAX_UNIQUE_VALUES;

    std::cout << MAX_UNIQUE_VALUES << std::endl;
  }
}
