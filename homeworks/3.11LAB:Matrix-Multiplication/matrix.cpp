#include "matrix.h"
#include <iomanip>
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
  data = new int *[rows];
  for (int i = 0; i < rows; ++i) {
    data[i] = new int[cols];
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < rows; ++i) {
    delete[] data[i];
  }
  delete[] data;
}

void Matrix::FillMatrix() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cin >> data[i][j];
    }
  }
}

void Matrix::PrintMatrix() const {
  int max_width = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      int width = std::to_string(data[i][j]).length();
      if (width > max_width) {
        max_width = width;
      }
    }
  }
  max_width += 2;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << "| " << std::setw(max_width) << data[i][j];
    }
    std::cout << "|" << std::endl;
  }
}

void Matrix::Multiply(const Matrix &other, Matrix &result) const {
  if (cols != other.rows) {
    throw std::runtime_error("Matrix dimensions do not match for multiplication.");
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < other.cols; ++j) {
      result.data[i][j] = 0;
      for (int k = 0; k < cols; ++k) {
        result.data[i][j] += data[i][k] * other.data[k][j];
      }
    }
  }
}
