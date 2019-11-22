#include <bits/stdc++.h>
using namespace std;

void print_table(vector<vector<int>> &table) {
    for (int i=0; i<table.size(); i++) {
        for (int j=0; j<table[0].size(); j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void build_lcs_table(string a, string b, vector<vector<int>> &table) {
    int m = a.size(), n = b.size();
    for (int i=0; i<=m; i++) {
        vector<int> temp (n+1, 0);
        table.push_back(temp);
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i-1] == b[j-1]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
}
    
string get_lcs(string a, string b, vector<vector<int>> &table) {
    int i = a.size(), j = b.size();
    string lcs = "";
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs = a[i-1] + lcs;
            i -= 1;
            j -= 1;
        }
        else if (table[i-1][j] > table[i][j-1]) i -= 1;
        else j-=1;
    }
    return lcs;
}

int main() {
    string a = "AGGTAB", b = "GXTXAYB";
    vector<vector<int>> table;
    build_lcs_table(a, b, table);
    print_table(table);
    int len = table[a.size()][b.size()]; cout << len << endl;
    string lcs = get_lcs(a, b, table); cout << lcs << endl;
}