#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  string filename = "input.txt";

  ifstream inputFile(filename);

  if (!inputFile.is_open()) {
    cout << "error" << endl;
  }

  vector<int> list1;
  vector<int> list2;

  string line;
  while (getline(inputFile, line)) {
    string str = "";
    bool flag = false;
    for (char ch : line) {
      // cout << num << endl;
      if (isdigit(ch)) {
        str += ch;
      } else if (!isdigit(ch) && !flag) {
        int num = atoi(str.c_str());
        list1.push_back(num);
        str = "";
        flag = true;
      }
    }
    int num = atoi(str.c_str());
    list2.push_back(num);
  }

  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());

  int totalDistance = 0;

  for (int i = 0; i < list1.size(); i++) {
    int distance = abs(list1[i] - list2[i]);
    totalDistance += distance;
  }

  // for(int i = 0; i < list1.size(); i++) {
  //   cout << list1[i] << endl;
  // }

  // for(int i = 0; i < list2.size(); i++) {
  //   cout << list2[i] << endl;
  // }

  inputFile.close();

  cout << totalDistance << endl;

  return 0;
}
