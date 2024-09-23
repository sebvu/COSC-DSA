#pragma once

class Matrix {
  public:
  Matrix(int rows, int cols);
  ~Matrix();
  void FillMatrix();
  void PrintMatrix() const;
  void Multiply(const Matrix &other, Matrix &result) const;
  int GetRows() const { return rows; }
  int GetCols() const { return cols; }

  private:
  int **data;
  int rows;
  int cols;
};
