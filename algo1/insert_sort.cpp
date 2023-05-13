#include <iostream>
using namespace std;

int main() {
  // my implement differs from the doctor which is right shift on time
  // int a[]{9, 2, 10, 0, 5, 3, 90, 85};
  int a[]{9, 2, 10, 0};
  int n = sizeof(a) / sizeof(int);

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j > 0;) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        j--;
      } else {
        break;
      }
      for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
      }
      cout << '\n';
      // else {
      //   break;
      // }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
