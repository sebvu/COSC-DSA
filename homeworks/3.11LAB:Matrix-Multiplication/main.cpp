#include <iomanip>  // For std::setw
#include <iostream>

void Print(int **matrix, int numRows, int numCols) {
  int max_width = 0;
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int width = std::to_string(matrix[row][col]).length();
      if (width > max_width) {
        max_width = width;
      }
    }
  }
  for (int row = 0; row < numRows; row++) {
    std::cout << "|";
    for (int col = 0; col < numCols; col++) {
      std::cout << " " << std::setw(max_width) << std::right << matrix[row][col];
      if (col < numCols - 1) {
        std::cout << " |";
      }
    }
    std::cout << " |" << std::endl;
  }
}

int main() {
  int numRows1 = 0, numCols1 = 0;
  std::cin >> numRows1 >> numCols1;

  int **matrix1 = new int *[numRows1];
  for (int row = 0; row < numRows1; row++) {
    matrix1[row] = new int[numCols1];
    for (int col = 0; col < numCols1; col++) {
      std::cin >> matrix1[row][col];
    }
  }

  int numRows2 = 0, numCols2 = 0;
  std::cin >> numRows2 >> numCols2;

  if (numCols1 != numRows2) {
    std::cout << "Matrix Multiplication Invalid!" << std::endl;
    for (int row = 0; row < numRows1; row++) {
      delete[] matrix1[row];
    }
    delete[] matrix1;
    return 1;
  }

  int **matrix2 = new int *[numRows2];
  for (int row = 0; row < numRows2; row++) {
    matrix2[row] = new int[numCols2];
    for (int col = 0; col < numCols2; col++) {
      std::cin >> matrix2[row][col];
    }
  }
  int **answer = new int *[numRows1];
  for (int row = 0; row < numRows1; row++) {
    answer[row] = new int[numCols2];
    for (int col = 0; col < numCols2; col++) {
      answer[row][col] = 0;
      for (int k = 0; k < numCols1; k++) {
        answer[row][col] += matrix1[row][k] * matrix2[k][col];
      }
    }
  }

  Print(answer, numRows1, numCols2);

  for (int row = 0; row < numRows1; row++) {
    delete[] matrix1[row];
    delete[] answer[row];
  }
  delete[] matrix1;
  delete[] answer;

  for (int row = 0; row < numRows2; row++) {
    delete[] matrix2[row];
  }
  delete[] matrix2;

  return 0;
}
