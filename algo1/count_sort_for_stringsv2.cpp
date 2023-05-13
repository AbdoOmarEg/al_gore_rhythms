#include <iostream>
#include <vector>
using namespace std;

void countSort2(vector<string> &array) {
  for (int i = 0; i < array.size(); i++) {
    cout << array[i] << " ";
  }
  cout << '\n';

  vector<int> freq(26);

  for (int i = 0; i < array.size(); i++) {
    // for (int j = 0; j < array[i].length(); i++) {
    //   if ()
    // }
    freq[array[i][0] - 'a']++;
  }

  for (int j = 0; j < 26; j++) {
    if (freq[j] > 0) {
      for (int i = 0; i < array.size(); i++) {
        if (array[i][0] - 'a' == j && freq[j] > 0) {
          cout << array[i] << " ";
          freq[j]--;
        }
      }
    }
  }
}

void count(vector<string> &array) {
  vector<vector<string>> letters_to_strings(26);
  for (int i = 0; i < array.size(); i++) {
    letters_to_strings[array[i][0] - 'a'].push_back(array[i]);
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < letters_to_strings[i].size(); j++) {
      cout << letters_to_strings[i][j] << " ";
    }
  }
}

int main() {
  vector<string> array = {"ziad", "belal", "adam", "baheir", "ali"};
  count(array);
}
