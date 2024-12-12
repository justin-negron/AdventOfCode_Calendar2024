#include <bits/stdc++.h>

using namespace std;

int main() {

    string filename = "input.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "error" << endl;
    }

    string line = "";
    int totalCount = 0;

    while (getline(inputFile, line)) {
        string str = "";
        bool inc = false;
        vector<int> arr;

        string last = "";
        for(char ch : line) {
            if(isdigit(ch)) {
                str += ch;
            }
            else{
                arr.push_back(stoi(str));
                str = "";
            }
            last = str;
        }
        arr.push_back(stoi(last));

        bool safe = true;

        if(arr[0] < arr[1]) {
            inc = true;
        }
        else{
            inc = false;
        }
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i-1] == arr[i] || abs(arr[i-1] - arr[i]) > 3 || arr[i-1] < arr[i] && !inc || arr[i-1] > arr[i] && inc) {
                safe = false;
                break;
            }
        }

        if(safe) totalCount++;
    }

    cout << totalCount << endl;

    return 0;
}