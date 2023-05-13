#include <iostream>
#include <vector>
using namespace std;

int main() {
  // doctor's implementation was to add 50000 to the orig array
  // vector<int> freq(50000 + 50000 + 1);
  vector<int> nums{-5, 2, -3, 1, 1234, -2453};
  vector<int> nums2(nums.size());
  int max = abs(nums[0]);
  for (int i = 1; i < nums.size(); i++) {
    if (abs(nums[i]) > max) {
      max = nums[i];
    }
  }
  max = abs(max);
  vector<int> freq(max * 2 + 1);
  for (int i = 0; i < nums.size(); i++) {
    freq[nums[i] + max]++;
  }

  int k = 0;
  for (int i = 0; i < freq.size(); i++) {
    if (freq[i] != 0) {
      while (freq[i] > 0) {
        nums2[k] = i - max;
        cout << i - max << " ";
        freq[i]--;
        k++;
      }
    }
  }
  cout << "\n";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums2[i] << " ";
  }
}
