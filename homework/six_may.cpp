#include <iostream>
#include <type_traits>
using namespace std;

class Vector {

private:
  int *arr = nullptr;
  int size = 0;
  int capacity = 0;

  void expand_capacity() {
    capacity *= 2;
    int *arr2 = new int[capacity];

    for (int i = 0; i < size; i++) {
      arr2[i] = arr[i];
    }

    swap(arr2, arr);
    delete[] arr2;
  }

public:
  Vector(int size) : size(size) {
    if (size < 1)
      size = 1;
    capacity = size + 1;
    arr = new int[capacity];
  }

  ~Vector() {
    delete[] arr;
    arr = nullptr;
  }

  void push_back(int val) {
    // make if
    if (size == capacity) {
      expand_capacity();
    }
    arr[size++] = val;
  }

  int get(int idx) { return arr[idx]; }

  void set(int idx, int val) { arr[idx] = val; };

  void print() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << '\n';
  }

  int find(int val) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == val)
        return i;
    }
    return -1;
  }

  void insert(int val, int idx) {

    if (size == capacity) {
      expand_capacity();
    }

    size++;

    for (int i = size - 1; i > idx; i--) {
      arr[i] = arr[i - 1];
    }

    arr[idx] = val;
  }
};
