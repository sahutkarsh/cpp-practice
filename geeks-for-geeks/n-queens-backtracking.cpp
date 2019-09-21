#include <bits/stdc++.h>
using namespace std;

bool check_config(vector<int> state) {
    unordered_map <int,int> sum, diff;
    int s, d;
    for (int i=0; i<state.size(); i++) {
        d = state[i] - i;
        s = state[i] + i;
        if (diff.find(d) != diff.end()) return false;
        else diff[d] = 1;
        if (sum.find(s) != sum.end()) return false;
        else sum[s] = 1;
    }
    return true;
}

void backTrack(vector<int> state, int index, int n, vector<vector<int>> &perms, unordered_map<int,int> &columns) {
    if (index == n) {
        perms.push_back(state);
        return;
    }
    for (int i=0; i<n; i++) {
        if (columns.find(i) != columns.end()) continue;
        columns[i] = 1;
        state.push_back(i);
        if (check_config(state)) backTrack(state, index+1, n, perms, columns);
        state.pop_back();
        columns.erase(i);
    }
}

int main() {
	//code
	int T, n;
	cin >> T;
	while (T--) {
	    cin >> n;
	    vector<vector<int>> perms;
	    for (int i=0; i<n; i++) {
	        vector<int> state;
	        unordered_map<int,int> columns;
	        columns[i] = 1;
	        state.push_back(i);
	        backTrack(state, 1, n, perms, columns);
	    }
	    if (perms.empty()) {
	        cout << -1 << endl;
	        return 0;
	    }
	    for (auto itr = perms.begin(); itr != perms.end(); itr++) {
	        cout << "[";
	        for (int i=0; i<n; i++) {
	            cout << (*itr)[i] + 1 << " ";
	        }
	        cout << "] ";
	    }
	    cout << endl;
	}
	return 0;
}