#include "ArrayList.h"
#include "SinglyLinkedList.h"
// #include "DoublyLinkedList.h"
// #include "SinglyLinkedList.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>

const int MAX_LINES = 2643;
const std::string FILE_NAME = "random-words.txt";

// Generate a random number from 0 to 100000
int randomNumber();
// Generate a random word from a file
std::string randomWord(std::ifstream &file, int maxLines);

// Test case for ArrayList
void arrayListTest(bool isInt, std::ifstream &inputFile);

void singlyLinkedListTest(bool isInt, std::ifstream &inputTile);

int main() {
  std::ifstream inputFile(FILE_NAME);

  if (!inputFile.is_open()) {
    std::cerr << "File not found" << std::endl;
    return 1;
  }

  std::cout << "Array List Int Implementation" << std::endl << "----------" << std::endl;
  arrayListTest(true, inputFile);
  std::cout << "Array List String Implementation" << std::endl << "----------" << std::endl;
  arrayListTest(false, inputFile);
  std::cout << "Singly Linked List Int Implementation" << std::endl << "----------" << std::endl;
  singlyLinkedListTest(true, inputFile);
  std::cout << "Singly Linked List String Implementation" << std::endl << "----------" << std::endl;
  singlyLinkedListTest(false, inputFile);

  inputFile.close();
  return 0;
}

int randomNumber() {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, 100000);
  return dist(rd);
}

std::string randomWord(std::ifstream &file, int maxLines) {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(1, maxLines);
  int lineNumber = dist(rd);

  // Reset file to the beginning
  file.clear();
  file.seekg(0);

  std::string word;
  for (int i = 1; i <= lineNumber; ++i) {
    if (!std::getline(file, word)) {
      return "";
    }
  }

  return word;
}

void singlyLinkedListTest(bool isInt, std::ifstream &inputFile) {
  if (isInt) {
    singlyLinkedList<int> singlyLinkedList;

    for (int i = 0; i < 20; i++) {
      singlyLinkedList.append(randomNumber());
    }
    std::cout << "Size of array: " << singlyLinkedList.getSize() << std::endl;
    singlyLinkedList.print();

  } else {
    singlyLinkedList<std::string> singlyLinkedList;

    for (int i = 0; i < 20; i++) {
      singlyLinkedList.append(randomWord(inputFile, MAX_LINES));
    }
    std::cout << "Size of array: " << singlyLinkedList.getSize() << std::endl;
    singlyLinkedList.print();
  }
}

void arrayListTest(bool isInt, std::ifstream &inputFile) {
  if (isInt) {
    ArrayList<int> intList;

    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 10000);

    for (int i = 0; i < 20; ++i) {
      intList.append(i == 15 ? 1008500 : dist(rd));
    }

    std::cout << "Size of Array: " << intList.getSize() << "\nCapacity of Array: " << intList.getCapacity() << std::endl;
    intList.print();

    intList.removeAt(3);
    std::cout << "Removed index 3" << std::endl;
    intList.print();

    intList.remove(1008500);
    std::cout << "Removed number 1008500" << std::endl;
    intList.print();

    std::cout << "Array List Sorted" << std::endl;
    intList.sort();
    intList.print();

  } else {
    ArrayList<std::string> stringList;

    for (int i = 0; i < 20; ++i) {
      stringList.append(i == 15 ? "GabyDaBest" : randomWord(inputFile, MAX_LINES));
    }

    std::cout << "Size of Array: " << stringList.getSize() << "\nCapacity of Array: " << stringList.getCapacity() << std::endl;
    stringList.print();

    stringList.removeAt(3);
    std::cout << "Removed index 3" << std::endl;
    stringList.print();

    stringList.remove("GabyDaBest");
    std::cout << "Removed word GabyDaBest" << std::endl;
    stringList.print();

    std::cout << "Array List Sorted" << std::endl;
    stringList.sort();
    stringList.print();
  }

  std::cout << std::endl;
}
