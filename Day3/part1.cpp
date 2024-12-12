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

    while (getline(inputFile, line)) {
        entireFile += line;
    }

    regex pattern("mul\\((\\d+),\\s*(\\d+)\\)");

    vector<string> matches;

    for(sregex_iterator it(entireFile.begin(), entireFile.end(), pattern), end; it != end; it++) {
        matches.push_back(it->str());
    }

    for(const auto& match : matches) {
        // cout << match << endl;
        
        string start = "(";
        string end = ")";

        unsigned first = match.find(start);
        unsigned last = match.find(end);

        string parsed = match.substr(first+1, last-4);
        // parsed = parsed.substr(first + start.size());

        int arr[3];
        string seg = "";

        string num1 = parsed.substr(0, parsed.find(","));
        string num2 = parsed.substr(parsed.find(",")+1, parsed.size());

        // cout << num1 << " " << num2 << endl;

        result += stoi(num1)*stoi(num2);

        // cout << parsed << endl;
    }

    cout << result << endl;

    return 0;
}