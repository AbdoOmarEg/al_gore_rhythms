// TODO: ask ur rustacean friend about the allocation bug that you thought about
#include <iostream>
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
    if (size < 0)
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

  // Homework starts here//

  // 0 1 2 3 4
  // 4 0 1 2 3
  // 4 0 1 2 3
  // 0 1 2 3 4
  // 0 1
  // 0 0
  // size = 2
  // int borrow = arr[size - 1];
  // arr[i] = arr[i - 1]
  //
  void right_rotation() {
    int borrow = arr[size - 1];

    for (int i = size - 1; i > 0; i--) {
      arr[i] = arr[i - 1];
    }

    arr[0] = borrow;
  }

  void left_rotation() {
    int borrow = arr[0];

    for (int i = 0; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }

    arr[size - 1] = borrow;
  }

  // 0 1 2 3 4
  // 3 4 0 1 2
  // 3 4 0 1 2
  // arr[i] = arr[i - 1]

  void right_rotation(int times) {
    times = times % size;
    // cout << times << '\n';
    for (int i = 0; i < times; i++) {
      right_rotation();
    }
  }

  // 4 0 1 2 3
  // 4 0 2 2 3
  // 4 0 2 3
  //
  int pop(int idx) {
    int borrow = arr[idx];
    for (int i = idx; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    size--;
    return borrow;
  }

  // 0 1 2 3 4
  // 0 1 2 3 4
  // 1 2 3 4 0
  // 0 1 2 4 3
  // 2
  int find_transposition(int val) {
    int idx = find(val);

    if (idx == -1)
      return -1;
    if (idx == 0)
      return 0;

    // int temp = arr[idx];
    // arr[idx] = arr[(idx - 1)];
    // arr[(idx - 1)] = temp;
    swap(arr[idx], arr[idx - 1]);
    // TODO: ask the dr. about this " (idx - 1) % size "

    return (idx - 1);
  }

  // Homework ends here//
};
int main() {
  Vector v(0);
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.print();

  cout << v.find_transposition(1);
  cout << '\n';
  v.print();
}
