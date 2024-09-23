#include <iostream>

void quickSort() {}

void quickSortPartition() {}

void insertionSort(int array) {}

void bubbleSort(int array[], int count) {
  bool notOrdered = true;

  while (notOrdered) {
    notOrdered = false;
    for (int i = 0; i < count - 1; i++) {
      if (array[i] > array[i + 1]) {
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
        notOrdered = true;
      }
    }
    if (!notOrdered)
      return;
  }
}

void Print(int array[], int count) {
  for (int i = 0; i < count; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

void BinarySearch(int array, int lower, int upper) {}

int main() {
  int array[10] = {1, 16, 6, 8, 1, 3, 5, 62, 38, 7};

  Print(array, 10);

  bubbleSort(array, 10);

  Print(array, 10);
}
