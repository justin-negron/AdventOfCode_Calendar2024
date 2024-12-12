#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {

  string filename = "input.txt";

  ifstream inputFile(filename);

  if(!inputFile.is_open()) {
    cout << "error" << endl;
  }

  vector<int> list1;
  unordered_map<int, int> list2;

  

  string line;
  while(getline(inputFile, line)) {
    string str = "";
    bool flag = false;
    for(char ch : line) {
      //cout << num << endl;
      if(isdigit(ch)) {
        str += ch;
      }
      else if(!isdigit(ch) && !flag) {
        int num = atoi(str.c_str());
        list1.push_back(num);
        str = "";
        flag = true;
      }
    }
    int num = atoi(str.c_str());
    if(list2.count(num)) {
      list2[num]++;
    }
    else{
      list2.insert({num, 1});
    }
    
  }

  int similarityScore = 0;

  for(int i = 0; i < list1.size(); i++) {
    similarityScore += list1[i] * list2[list1[i]];
  }

  // for(int i = 0; i < list1.size(); i++) {
  //   cout << list1[i] << endl;
  // }

  // for(int i = 0; i < list2.size(); i++) {
  //   cout << list2[i] << endl;
  // }


  inputFile.close();

  cout << similarityScore << endl;


  return 0;
  
}
