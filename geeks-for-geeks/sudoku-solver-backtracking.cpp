#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> &mat) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}

bool check(vector<vector<int>> &mat, int r, int c) {
    unordered_map<int,int> row, col, grid;
    for (int i=0; i<9; i++) {
        if (row.find(mat[r][i]) == row.end()) {
            if (mat[r][i] != 0) row[mat[r][i]] = 1;
        }
        else return false;
        if (col.find(mat[i][c]) == col.end()) {
            if (mat[i][c] != 0) col[mat[i][c]] = 1;
        }
        else return false;
    }
    int grid_r = 3 * int(r/3), grid_c = 3 * int(c/3);
    for (int i=grid_r; i<(grid_r+3); i++) {
        for (int j=grid_c; j<(grid_c+3); j++) {
            if (grid.find(mat[i][j]) == grid.end()) {
                if (mat[i][j] != 0) grid[mat[i][j]] = 1;
            }
            else return false;
        }
    }
    return true;
}

bool next_gap(pair<int,int> &gap, vector<vector<int>> &mat) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (mat[i][j] == 0) {
                gap.first = i;
                gap.second = j;
                return false;
            }
        }
    }
    return true;
}

bool backTrack(vector<vector<int>> &mat) {
    pair<int,int> gap;
    bool solved = next_gap(gap, mat);
    if (solved) return true;
    for (int i=1; i<=9; i++) {
        mat[gap.first][gap.second] = i;
        bool valid = check(mat, gap.first, gap.second);
        if (valid) {
            bool terminate = backTrack(mat);
            if (terminate) return true;
        }
        mat[gap.first][gap.second] = 0;
    }
    return false;
}

int main() {
	int T, temp;
	cin >> T;
	while (T--) {
	    vector<vector<int>> mat;
	    for (int i=0; i<9; i++) {
	        vector<int> row;
	        for (int j=0; j<9; j++) {
	            cin >> temp;
	            row.push_back(temp);
	        }
	        mat.push_back(row);
	    }
	    bool solved = backTrack(mat);
	    print_matrix(mat);
	}
	return 0;
}