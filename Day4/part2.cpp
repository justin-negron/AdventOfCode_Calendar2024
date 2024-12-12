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
            if(matrix[i][j] == 'A') {
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
    if(m-1 >= 0 && n-1 >= 0 && m+1 < maxM && n+1 < maxN && matrix[m-1][n-1] == 'M' && matrix[m+1][n-1] == 'M' && matrix[m-1][n+1] == 'S' && matrix[m+1][n+1] == 'S') xmasCt++;

    if(m-1 >= 0 && n-1 >= 0 && m+1 < maxM && n+1 < maxN && matrix[m-1][n-1] == 'S' && matrix[m+1][n-1] == 'S' && matrix[m-1][n+1] == 'M' && matrix[m+1][n+1] == 'M') xmasCt++;

    if(m-1 >= 0 && n-1 >= 0 && m+1 < maxM && n+1 < maxN && matrix[m-1][n-1] == 'M' && matrix[m+1][n-1] == 'S' && matrix[m-1][n+1] == 'M' && matrix[m+1][n+1] == 'S') xmasCt++;

    if(m-1 >= 0 && n-1 >= 0 && m+1 < maxM && n+1 < maxN && matrix[m-1][n-1] == 'S' && matrix[m+1][n-1] == 'M' && matrix[m-1][n+1] == 'S' && matrix[m+1][n+1] == 'M') xmasCt++;

    return xmasCt;
}