#include <bits/stdc++.h>
using namespace std;

int matrixChain(int *arr, int n) {
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i=1; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            int x = j;
            int y = i+j;
            int minComp = INT_MAX;
            for (int k=x; k<y; k++) {
                int current = dp[x][k] + dp[k+1][y];
                current += arr[x] * arr[k+1] * arr[y+1];
                minComp = min(minComp, current);
            }
            dp[x][y] = minComp;
        }
    }
    return dp[0][n-1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for (int i=0; i<n; i++) cin >> arr[i];
	    int res = matrixChain(arr, n-1);
	    cout << res << endl;
	}
	return 0;
}