#include <bits/stdc++.h>

using namespace std;



int main() {

    string filename = "input.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "error" << endl;
    }

    string line = "";
    int result = 0;
    string entireFile = "";

    unordered_map<string, unordered_set<string>> numbefore;

    bool hitEmpty = false;

    vector<string> validOrder;

    while (getline(inputFile, line)) {

        if(line.empty()) hitEmpty = true;
        
        if(!hitEmpty) {
            string left = line.substr(0, line.find('|'));
            string right = line.substr(line.find('|')+1, line.size());

            if(!numbefore.count(left)) {
                unordered_set<string> newSet;
                newSet.insert(right);
                numbefore[left] = newSet;
            }
            else{
                numbefore[left].insert(right);
            }
        }
        else{
            if(line.empty()) continue;
            vector<string> validateOrder;

            stringstream ss(line);
            string token;

            while(getline(ss, token, ',')) {
                validateOrder.push_back(token);
            }

            vector<string> seen;
            bool invalid = false;
            for(int i = 0; i < validateOrder.size(); i++) {
                for(string str : seen) {
                    unordered_set<string> test = numbefore[validateOrder[i]];
                    if(find(test.begin(), test.end(), str) != test.end()) {
                        // invalid
                        invalid = true;
                    }
                }
                if(invalid) break;
                seen.push_back(validateOrder[i]);
            }
            if(!invalid) {
                string midNum = validateOrder[validateOrder.size()/2];
                result += stoi(midNum);
            }
        }
    }

    // for(const auto& pair : numbefore) {
    //     cout << pair.first << ": ";
    //     for(const auto& itr : pair.second) {
    //         cout << itr << ", ";
    //     }
    //     cout << endl;
    // }

    
    cout << result << endl;

    return 0;
}