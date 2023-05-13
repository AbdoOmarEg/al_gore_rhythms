#include <iostream>
#include <vector>
using namespace std;

// do it in rust

int main() {
  cout << "hello world";
  vector<int> v;
}

// Appending operation

class Vector {
private:
  int *arr = nullptr;
  int size = 0;
  int capacity{};

public:
  Vector(int size) : size(size) { // initializer list
    if (size < 0)
      size = 1;
    arr = new int[size]{};
  }

  ~Vector() {
    delete[] arr;
    arr = nullptr;
  }

  // Appending operation

  int get_fron() { return arr[0]; }

  int get_back() { return arr[size - 1]; }

  void push_back(int value) {
    int *arr2 = new int[size + 1];
    for (int i = 0; i < size; i++) {
      arr2[i] = arr[i];
    }
    arr2[size++] = value; // one liner
    swap(arr, arr2);
    delete[] arr2;
  }
};
