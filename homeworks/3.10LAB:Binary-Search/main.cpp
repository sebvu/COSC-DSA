#include <fstream>
#include <iostream>

template <typename T> class ArrayList {
  private:
  T *list;
  int size, capacity, recursions;
  void DoubleArrayList();

  public:
  ArrayList();   // Constructor
  ~ArrayList();  // Destructor

  void Append(T value);                             // Append values at the end of list
  void BubbleSort();                                // Sort list with bubblesort
  void Print();                                     // Print out current values
  int GetSize();                                    // Get current size
  int GetBinaryRecursions();                        // Return total recursions
  int GetBinaryComparisons();                       // Return total comparisons
  void ResetBinaryCounters();                       // Reset current recursions and comparisons
  int BinarySearch(int num, int lower, int upper);  // Return the index of num
};

template <typename T> ArrayList<T>::ArrayList() : list(new T[8]), size(0), capacity(8), recursions(0) {}

template <typename T> ArrayList<T>::~ArrayList() {
  delete[] list;
  capacity = 0, size = 0;
}

template <typename T> void ArrayList<T>::DoubleArrayList() {
  T *temp = new T[capacity * 2];

  for (int i = 0; i < capacity; i++) {
    temp[i] = list[i];
  }

  delete[] list;
  list = temp;
  capacity *= 2;
}

template <typename T> void ArrayList<T>::Append(T value) {
  if (capacity == size)
    DoubleArrayList();
  list[size] = value;
  size++;
}

template <typename T> void ArrayList<T>::BubbleSort() {
  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;
    for (int i = 0; i < size - 1; i++) {
      if (list[i] > list[i + 1]) {
        T tmp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = tmp;
        isSorted = false;
      }
    }
  }
}

template <typename T> void ArrayList<T>::Print() {
  for (int i = 0; i < size; i++) {
    if (i != 0)
      std::cout << ", ";
    std::cout << list[i];
  }
  std::cout << std::endl;
}

template <typename T> int ArrayList<T>::GetSize() { return size; }

template <typename T> int ArrayList<T>::GetBinaryRecursions() { return recursions; }

template <typename T> int ArrayList<T>::GetBinaryComparisons() { return (recursions * 2) - 1; }

template <typename T> void ArrayList<T>::ResetBinaryCounters() { recursions = 0; }

template <typename T> int ArrayList<T>::BinarySearch(int num, int lower, int upper) {
  recursions++;
  int middleIndex = (upper + lower) / 2;

  if (list[middleIndex] == num) {
    return middleIndex;
  }

  if (lower > upper || lower == upper) {
    // if (recursions == 6) // no cheesing >:(
    //   recursions++;
    return -1;
  }

  if (list[middleIndex] > num) {
    return BinarySearch(num, lower, middleIndex - 1);
  } else {
    return BinarySearch(num, middleIndex + 1, upper);
  }
}

int main() {

  std::string inputFile;
  int number;

  std::cin >> inputFile >> number;

  std::ifstream input(inputFile);

  if (!input.is_open()) {
    std::cerr << "File did not open.";
    return 1;
  }

  ArrayList<int> list;
  std::string line;

  while (getline(input, line))
    list.Append(stoi(line));

  list.BubbleSort();

  list.ResetBinaryCounters();

  std::cout << "index: " << list.BinarySearch(number, 0, list.GetSize() - 1) << ", recursions: " << list.GetBinaryRecursions() << ", comparisons: " << list.GetBinaryComparisons() << std::endl;
}
