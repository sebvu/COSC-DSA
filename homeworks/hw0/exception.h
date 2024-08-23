#ifndef ERRORCLASSES_H
#define ERRORCLASSES_H

#include <iostream>

class caseDoesNotExist {
private:
  std::string colOrRow;
  char type;

public:
  caseDoesNotExist(std::string area, char type) : colOrRow(area), type(type) {}
  std::string getColOrRow() { return colOrRow; }
  int getType() { return type; }

  // void what() {
  //   std::cout << "Case does not exist at " << area << " type " << type
  //             << std::endl;
  // }
};

#endif
