#include <bits/stdc++.h>

using namespace std;

int isXmas(vector<vector<char>>, int, int, int, int);

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

    // cout << "here";

    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 'X') {
                result += isXmas(matrix, i, j, m, n);
            }
        }
    }

    cout << result << endl;

    return 0;
}

int isXmas(vector<vector<char>> matrix, int m, int n, int maxM, int maxN) {

    int xmasCt = 0;

    // left up
    if(m-3 >= 0 && n-3 >= 0 && matrix[m-1][n-1] == 'M' && matrix[m-2][n-2] == 'A' && matrix[m-3][n-3] == 'S') xmasCt++;

    // up
    if(m-3 >= 0 && matrix[m-1][n] == 'M' && matrix[m-2][n] == 'A' && matrix[m-3][n] == 'S') xmasCt++;

    // right up
    if(m-3 >= 0 && n+3 < maxN && matrix[m-1][n+1] == 'M' && matrix[m-2][n+2] == 'A' && matrix[m-3][n+3] == 'S') xmasCt++;

    // left
    if(n-3 >= 0 && matrix[m][n-1] == 'M' && matrix[m][n-2] == 'A' && matrix[m][n-3] == 'S') xmasCt++;

    // right
    if(n+3 < maxN && matrix[m][n+1] == 'M' && matrix[m][n+2] == 'A' && matrix[m][n+3] == 'S') xmasCt++;

    // down left
    if(m+3 < maxM && n-3 >= 0 && matrix[m+1][n-1] == 'M' && matrix[m+2][n-2] == 'A' && matrix[m+3][n-3] == 'S') xmasCt++;

    // down
    if(m+3 < maxM && matrix[m+1][n] == 'M' && matrix[m+2][n] == 'A' && matrix[m+3][n] == 'S') xmasCt++;

    // down right
    if(m+3 < maxM && n+3 < maxN && matrix[m+1][n+1] == 'M' && matrix[m+2][n+2] == 'A' && matrix[m+3][n+3] == 'S') xmasCt++;

    return xmasCt;
}