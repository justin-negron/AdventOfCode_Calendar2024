#include <bits/stdc++.h>

using namespace std;

char UP = '^', RIGHT = '>', DOWN = 'v', LEFT = '<';

unordered_map<char, pair<int, int>> dirMap = {{UP, {-1,0}},{RIGHT, {0,1}},{DOWN,{1,0}},{LEFT,{0,-1}}};
set<pair<int, int>> seen;

void moveGuard(vector<vector<char>>, int, int, int, int, char);
pair<int, int> findCaret(vector<vector<char>> matrix);

int main() {

    string filename = "input.txt";

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "error" << endl;
    }

    string line = "";
    int result = 0;
    string entireFile = "";

    vector<vector<char>> matrix;

    while (getline(inputFile, line)) {
        vector<char> charVec(line.begin(), line.end());
        matrix.push_back(charVec);
    }

    int m = matrix.size();
    int n = matrix[0].size();

    pair<int, int> index = findCaret(matrix);
    int caret_i = index.first;
    int caret_j = index.second;

    moveGuard(matrix, caret_i, caret_j, m, n, matrix[caret_i][caret_j]);
    
    cout << seen.size()+1 << endl;

    return 0;
}

void moveGuard(vector<vector<char>> matrix, int i, int j, int m, int n, char direction) {

    int ahead_i = i + dirMap[direction].first;
    int ahead_j = j + dirMap[direction].second;

    if(ahead_i < 0 || ahead_j < 0 || ahead_i >= m || ahead_j >= n) return;

    // cout << ahead_i << " " << ahead_j << endl;



    seen.insert(make_pair(i, j));

    if(matrix[ahead_i][ahead_j] == '#') {
        if(direction == UP) {
            matrix[i][j] = RIGHT;
            direction = RIGHT;
        }
        else if(direction == RIGHT) {
            matrix[i][j] = DOWN;
            direction = DOWN;
        }
        else if(direction == DOWN) {
            matrix[i][j] = LEFT;
            direction = LEFT;
        }
        else if(direction == LEFT) {
            matrix[i][j] = UP;
            direction = UP;
        }
        moveGuard(matrix, i, j, m, n, direction);
    }
    else{
        matrix[ahead_i][ahead_j] == '.';
        // matrix[i][j] = '.';
        // cout << "we are here";

        moveGuard(matrix, ahead_i, ahead_j, m, n, direction);
    }

    // for(vector<char> arr : matrix) {
    //     for(char ch : arr) {
    //         cout << ch;
    //     }
    //     cout << endl;
    // }
    // cout << "===================" << endl;

    return;
}

pair<int, int> findCaret(vector<vector<char>> matrix) {

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == UP || matrix[i][j] == DOWN || matrix[i][j] == LEFT || matrix[i][j] == RIGHT) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}