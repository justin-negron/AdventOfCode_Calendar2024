#include <bits/stdc++.h>

using namespace std;

unordered_map<int, unordered_set<int>> numbefore;

bool compare(int, int);

int main() {

    string filename = "input.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "error" << endl;
    }

    string line = "";
    int result = 0;
    string entireFile = "";

    

    bool hitEmpty = false;

    vector<vector<int>> failedOrders;

    while (getline(inputFile, line)) {

        if(line.empty()) hitEmpty = true;
        
        if(!hitEmpty) {
            int left = stoi(line.substr(0, line.find('|')));
            int right = stoi(line.substr(line.find('|')+1, line.size()));

            if(!numbefore.count(left)) {
                unordered_set<int> newSet;
                newSet.insert(right);
                numbefore[left] = newSet;
            }
            else{
                numbefore[left].insert(right);
            }
        }
        else{
            if(line.empty()) continue;
            vector<int> validateOrder;

            stringstream ss(line);
            string token;

            while(getline(ss, token, ',')) {
                validateOrder.push_back(stoi(token));
            }

            vector<int> seen;
            bool invalid = false;
            for(int i = 0; i < validateOrder.size(); i++) {
                for(int str : seen) {
                    unordered_set<int> test = numbefore[validateOrder[i]];
                    if(find(test.begin(), test.end(), str) != test.end()) {
                        // invalid
                        invalid = true;
                    }
                }
                if(invalid) {
                    failedOrders.push_back(validateOrder);
                    break;
                }
                seen.push_back(validateOrder[i]);
            }
        }
    }

    for(vector<int> order : failedOrders) {

        sort(order.begin(), order.end(), compare);

        result += order[order.size()/2];

        // for(int num : order) {
        //     cout << num << " ";
        // }
        // cout << endl;
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

bool compare(int a, int b) {
    return numbefore[a].count(b) > 0;
}