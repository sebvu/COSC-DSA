#pragma once

#include <iostream>

template <typename T> class ArrayList {
  public:
  ArrayList();   // Constructor
  ~ArrayList();  // Destructor

  void append(T value);             // Append a T value at the end of the list.
  T at(int index, T value);         // Return T value at given index, otherwise, return value.
  int find(T value);                // Return the index of T value, otherwise, return -1.
  void insert(int index, T value);  // Insert at given index T value.
  bool isEmpty();                   // Return if array is empty.
  void print();                     // Print out array content.
  bool remove(T value);             // Remove the first occurence of T value and return true, otherwise, return false.
  void sort();                      // Abstracted call for quickSorting method.
  bool removeAt(int index);         // Remove at index and return true, otherwise, return false.
  int getSize();                    // Return Size
  int getCapacity();                // Return Capacity

  private:
  T *list;
  int size, capacity;
  void doubleArrayList();                                // Double the capacity of the array list.
  void quickSort(T *array, int start, int end);          // Sort the array with ASCII values.
  int quickSortPartition(T *array, int start, int end);  // Partition the quickSort
};

template <typename T> ArrayList<T>::ArrayList() {  // Constructor
  list = new T[8];                                 // initialize an array of size 8
  size = 0, capacity = 8;
}

template <typename T> ArrayList<T>::~ArrayList() {  // Destructor
  delete[] list;
}

template <typename T> void ArrayList<T>::append(T value) {  // Append a T value at the end of the list.
  if (size == capacity)
    doubleArrayList();

  list[size] = value;
  size++;
}

template <typename T> T ArrayList<T>::at(int index, T value) {  // Return T value at given index, otherwise, return value.
  if (index >= size || index < 0)
    return value;

  return list[index];
}

template <typename T> int ArrayList<T>::find(T value) {  // Return the index of T value, otherwise, return -1.
  for (int i = 0; i < size; i++) {
    if (list[i] == value) {
      return i;
    }
  }
  return -1;
}

template <typename T> void ArrayList<T>::insert(int index, T value) {  // Insert at given index T value.
  if (index >= size || index < 0)
    return;
  if (size == capacity)
    doubleArrayList();

  for (int i = size; i > index; i--)
    list[i] == list[i - 1];

  list[index] = value;
  size++;
}

template <typename T> bool ArrayList<T>::isEmpty() { return size == 0; }  // Return if array is empty.

template <typename T> void ArrayList<T>::print() {  // Print out array content.
  for (int i = 0; i < size; i++) {
    if (i != 0)
      std::cout << ", ";
    std::cout << list[i];
  }
  std::cout << std::endl;
}

template <typename T> bool ArrayList<T>::remove(T value) {  // Remove the first occurence of T value and return true, otherwise, return false.
  for (int i = 0; i < size; i++) {
    if (list[i] == value) {
      for (int j = i; j < size; j++)
        list[j] = list[j + 1];
      size--;
      return true;
    }
  }
  return false;
}

template <typename T> void ArrayList<T>::sort() {  // Abstracted call for quickSorting method.
  quickSort(list, 0, size - 1);
}

template <typename T> void ArrayList<T>::quickSort(T *array, int start, int end) {  // Sort the array

  if (end <= start)
    return;

  int pivot = quickSortPartition(array, start, end);
  quickSort(array, start, pivot - 1);
  quickSort(array, pivot + 1, end);
}

template <typename T> int ArrayList<T>::quickSortPartition(T *array, int start, int end) {  // Partition for quick sort algorithm

  T pivot = array[end];
  int i = start - 1;

  for (int j = start; j < end; j++) {
    if (array[j] < pivot) {
      i++;
      T temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  i++;
  T temp = array[i];
  array[i] = array[end];
  array[end] = temp;

  return i;
}

template <typename T> bool ArrayList<T>::removeAt(int index) {  // Remove at index and return true, otherwise, return false.
  if (index >= size || index < 0)
    return false;

  for (int i = index; i < size; i++) {
    list[i] = list[i + 1];
  }
  size--;
  return true;
}

template <typename T> int ArrayList<T>::getSize() { return size; }  // Return Size

template <typename T> int ArrayList<T>::getCapacity() { return capacity; }  // Return Capacity

template <typename T> void ArrayList<T>::doubleArrayList() {  // Double the capacity of the array list.
  T *temp = new T[capacity * 2];

  for (int i = 0; i < size; i++)
    temp[i] = list[i];

  delete[] list;
  list = temp;
  capacity *= 2;
}
