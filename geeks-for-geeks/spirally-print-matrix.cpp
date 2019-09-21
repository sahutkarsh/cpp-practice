#include <bits/stdc++.h>
using namespace std;

bool loop(int **arr, int m, int n, int r, int c) {
    if (m-1 == 0) return false;
    for (int i=r+1; i<=r+(m-1); i++) {
        //cout << "Down: " << i << " " << c << endl;
        cout << arr[i][c] << " ";
    }
    if (n-1 == 0) return false;
    for (int i=c-1; i>=c-(n-1); i--) {
        //cout << "Left: " << r+(m-1) << " " << i << endl;
        cout << arr[r+m-1][i] << " ";
    }
    if (m-2 == 0) return false;
    for (int i=r+m-2; i>=r+1; i--) {
        //cout << "Up: " << i << " " << c-(n-1) << endl;
        cout << arr[i][c-n+1] << " ";
    }
    if (n-2 == 0) return false;
    for (int i=c-n+2; i<=c-1; i++) {
        //cout << "Right: " << r+1 << " " << i << endl;
        cout << arr[r+1][i] << " ";
    }
    return true;
}

void spiral(int **arr, int m, int n) {
    for (int i=0; i<n; i++) cout << arr[0][i] << " ";
    bool flag = true;
    int r = 0, c = n-1;
    while (flag) {
        //cout << endl << "New Loop: " << r << " " << c << " " << m << " " << n << endl;
        flag = loop(arr, m, n, r, c);
        m-=2; n-=2; r++; c--;
    }
}

int main() {
	int T, m, n;
	cin >> T;
	while(T--) {
	    cin >> m >> n;
	    int **arr = new int* [m];
	    for (int i=0; i<m; i++) arr[i] = new int[n];
	    for (int i=0; i<m; i++) for (int j=0; j<n; j++) cin >> arr[i][j];
	    spiral(arr, m, n);
	}
	return 0;
}