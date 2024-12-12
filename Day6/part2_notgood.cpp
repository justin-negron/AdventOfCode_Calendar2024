#include <bits/stdc++.h>

using namespace std;

char UP = '^', RIGHT = '>', DOWN = 'v', LEFT = '<';

unordered_map<char, pair<int, int>> dirMap = {{UP, {-1,0}},{RIGHT, {0,1}},{DOWN,{1,0}},{LEFT,{0,-1}}};
set<pair<int, int>> seen;
map<pair<int, int>, char> canLoopAgain;
set<pair<int, int>> infObs;

void moveGuard(vector<vector<char>>, int, int, int, int, int, int, char, char);

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

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == UP || matrix[i][j] == DOWN || matrix[i][j] == LEFT || matrix[i][j] == RIGHT) {
                int start_i = i;
                int start_j = j;
                char startDir = matrix[i][j];
                moveGuard(matrix, i, j, m, n, start_i, start_j, matrix[i][j], startDir);
                break;
            }
        }
    }
    
    for(pair<int, int> pr : infObs) {
        cout << pr.first << " " << pr.second << endl;
    }

    cout << infObs.size()+1 << endl;

    return 0;
}

void moveGuard(vector<vector<char>> matrix, int i, int j, int m, int n, int start_i, int start_j, char direction, char startDir) {

    int ahead_i = i + dirMap[direction].first;
    int ahead_j = j + dirMap[direction].second;

    if(ahead_i < 0 || ahead_j < 0 || ahead_i >= m || ahead_j >= n) return;

    // cout << ahead_i << " " << ahead_j << endl;

    if(seen.count(make_pair(i, j)) > 0) {
        if(canLoopAgain[make_pair(i,j)] == direction) {
            if(infObs.count(make_pair(ahead_i, ahead_j)) == 0) {
                infObs.insert(make_pair(ahead_i, ahead_j));
                moveGuard(matrix, start_i, start_j, m, n, start_i, start_j, startDir, startDir);
            }
        }
    }

    seen.insert(make_pair(i, j));
    if(direction == UP) {
        canLoopAgain.insert({make_pair(i, j), LEFT});
    }
    else if(direction == RIGHT) {
        canLoopAgain.insert({make_pair(i, j), UP});
    }
    else if(direction == DOWN) {
        canLoopAgain.insert({make_pair(i, j), RIGHT});
    }
    else if(direction == LEFT) {
        canLoopAgain.insert({make_pair(i, j), DOWN});
    }

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
        moveGuard(matrix, i, j, m, n, start_i, start_j, direction, startDir);
    }
    else{
        matrix[ahead_i][ahead_j] == '.';
        // matrix[i][j] = '.';
        // cout << "we are here";

        moveGuard(matrix, ahead_i, ahead_j, m, n, start_i, start_j, direction, startDir);
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