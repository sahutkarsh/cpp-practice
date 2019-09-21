#include <bits/stdc++.h>
using namespace std;

void permute(vector<int> state, int start, vector<vector<int>> &perms) {
    int n = state.size();
    if (start == n-1) return;
    for (int i=start; i<n; i++) {
        vector<int> temp = state;
        swap(temp[start], temp[i]);
        if (i != start) perms.push_back(temp);
        permute(temp, start+1, perms);
    }
}

bool check_config(vector<int> state, int n) {
    unordered_map <int,int> sum, diff;
    int s, d;
    for (int i=0; i<n; i++) {
        d = state[i] - i;
        s = state[i] + i;
        if (diff.find(d) != diff.end()) return false;
        else diff[d] = 1;
        if (sum.find(s) != sum.end()) return false;
        else sum[s] = 1;
    }
    return true;
}

int main() {
	//code
	int T, n;
	cin >> T;
	while (T--) {
	    cin >> n;
	    vector<int> state;
	    for (int i=0; i<n; i++) state.push_back(i);
	    vector<vector<int>> perms, config;
	    perms.push_back(state);
	    permute(state, 0, perms);
	    for (auto itr = perms.begin(); itr != perms.end(); itr++) {
	        bool valid = check_config(*itr, n);
	        if (valid) config.push_back(*itr);
	    }
	    if (config.empty()) {
	        cout << -1 << endl;
	        return 0;
	    }
	    for (auto itr = config.begin(); itr != config.end(); itr++) {
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