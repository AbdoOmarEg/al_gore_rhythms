#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v{9, 85, 10, 0, 5, 3};

  for (int i = 0; i < v.size() - 1; i++) {
    int min = v[i];
    int min_idx = i;
    for (int j = v.size() - 1; j > i; j--) {
      if (min > v[j]) {
        min = v[j];
        min_idx = j;
      }
    }
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
    swap(v[min_idx], v[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
