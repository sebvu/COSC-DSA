#pragma once
#include <iostream>
using namespace std;

template <typename T> class ArrayList {
  public:
  ArrayList();   // Default Constructor
  ~ArrayList();  // Destructor

  void append(T value);             // Add a value to the end of the list
  T at(int index, T value);         // Return the element at index or the default value
  int getCapacity();                // Return the current maximum capacity of the array list
  int find(T value);                // Return index of first occurrence of value or -1 if not found
  void insert(int index, T value);  // Insert value at index
  bool isEmpty();                   // True if the list is currently empty
  void print();
  bool remove(T value);      // Find the first occurrence of value and remove the
                             // value; true if success
  bool removeAt(int index);  // Remove the value at the specified index; true if success
  int Size();                // Number of elements in the list
  void doubleArrayList();

  private:
  T *list;  // Items are stored in this dynamic array
  int size, capacity;
};

// Add your code here

template <typename T> void ArrayList<T>::doubleArrayList() {
  T *temp = new T[2 * capacity];
  for (int i = 0; i < size; i++) {
    temp[i] = list[i];
  }
  delete[] list;
  // changing 'SHELVES' to TEMP
  list = temp;
  capacity *= 2;
}

template <typename T> ArrayList<T>::ArrayList() {
  list = new T[8];
  size = 0;
  capacity = 8;
}

template <typename T> ArrayList<T>::~ArrayList() {}

template <typename T> void ArrayList<T>::append(T value) {
  if (capacity == size)
    doubleArrayList();
  list[size] = value;
  size++;
}

template <typename T> T ArrayList<T>::at(int index, T value) {
  if (index < size && index >= 0)
    return list[index];
  else
    return value;
}

template <typename T> int ArrayList<T>::getCapacity() { return capacity; }

template <typename T> int ArrayList<T>::find(T value) {
  for (int i = 0; i < size; i++) {
    if (list[i] == value)
      return i;
  }
  return -1;
}

template <typename T> void ArrayList<T>::insert(int index, T value) {
  if (value < 0)
    return;

  if (index < size) {
    if (size == capacity)
      doubleArrayList();
    for (int i = size - 1; i >= index; i--) {
      list[i + 1] = list[i];
    }
    list[index] == value;
  } else {
    list[size] = value;
  }
  size++;
}

template <typename T> bool ArrayList<T>::isEmpty() { return size == 0; }

template <typename T> void ArrayList<T>::print() {
  for (int i = 0; i < size; i++) {
    if (i > 0)
      std::cout << ", ";
    std::cout << list[i];
  }
  std::cout << std::endl;
};

template <typename T> bool ArrayList<T>::remove(T value) {
  for (int i = 0; i < size; i++) {
    if (list[i] == value) {
      for (int j = i; i < size; i++)
        list[j] = list[j + 1];
      size--;
      return true;
    }
  }
  return false;
}

template <typename T> bool ArrayList<T>::removeAt(int index) {
  if (index < size && index >= 0) {
    for (int i = index; i < size; i++)
      list[i] = list[i + 1];
    size--;
    return true;
  }
  return false;
}

template <typename T> int ArrayList<T>::Size() { return size; }
