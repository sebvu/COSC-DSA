#include "ArgumentManager.h"
#include "exception.h"
#include <fstream>
#include <iostream>
#include <string>

void print(int **dataArray, ofstream &fout) {
  for (int row = 0; row < 15; row++) {
    for (int col = 0; col < 5; col++) {
      std::cout << dataArray[row][col] << " ";
      fout << dataArray[row][col] << " ";
    }
    fout << std::endl;
    std::cout << std::endl;
  }
}

int ParseCardRow(std::string card) {

  // results in pawn, rook, knight, bishop, queen, king or number from 2 - 10.
  char cardType = card[0];

  std::cout << cardType << std::endl;

  switch (cardType) {
  case 'P':
    return 0;
  case 'R':
    return 10;
  case 'N':
    return 11;
  case 'B':
    return 12;
  case 'Q':
    return 13;
  case 'K':
    return 14;
  default:
    int cardNumber = cardType - '0';
    if (card.length() == 3)
      return 9;
    else if (cardNumber < 10 && cardNumber > 1)
      // conversion from char to int
      return cardNumber - 1;
    else
      throw caseDoesNotExist("row", cardType);
  }
}

int ParseCardCol(std::string card) {

  char suit = card[card.length() - 1];

  switch (suit) {
  case 'A':
    return 0;
  case 'E':
    return 1;
  case 'F':
    return 2;
  case 'W':
    return 3;
  case 'H':
    return 4;
  default:
    throw caseDoesNotExist("col", suit);
  }
}

int main(int argc, char *argv[]) {
  try {
    for (int i = 1; i <= 3; i++) {

      std::string inputTextFile = "input" + std::to_string(i) + ".txt";
      std::string outputTextFile = "output" + std::to_string(i) + ".txt";

      ArgumentManager am(argc, argv);
      string input = inputTextFile;   /* am.get("input"); */
      string output = outputTextFile; /* am.get("output"); */
      ifstream fin(input);
      ofstream fout(output);

      std::string data;
      // allocate 15 different arrays
      int **dataArray = new int *[15];

      // hold 5 suites per array
      for (int i = 0; i < 15; i++) {
        dataArray[i] = new int[5];
        for (int j = 0; j < 5; j++) {
          dataArray[i][j] = 0;
        }
      }

      // extracts to data
      // getline(fin, data);
      // dataArray[10][2] = 1;

      getline(fin, data);

      while (data.length() > 1) {

        int delimeter = data.find(",");

        std::string singleData = data.substr(0, delimeter);
        int row = ParseCardRow(singleData);
        int col = ParseCardCol(singleData);
        std::cout << singleData << std::endl;
        dataArray[row][col]++;
        data = data.substr(delimeter + 2);
      }

      print(dataArray, fout);

      for (int i = 0; i < 15; i++) {
        delete[] dataArray[i];
      }
      delete[] dataArray;
    }
  } catch (exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  } catch (caseDoesNotExist &e) {
    std::cout << "Does not exist: " << e.getColOrRow() << " " << e.getType() << std::endl;
  } catch (...) {
    std::cout << "An error occurred" << std::endl;
  }
}
