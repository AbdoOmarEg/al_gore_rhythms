#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v{9, 2, 10, 1, 0};

  for (int i = 1; i < v.size(); i++) {
    int j = i - 1;
    while (v[j] < v[j + 1] && j >= 0) {
      swap(v[j], v[j + 1]);
      j--;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
