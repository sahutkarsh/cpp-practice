#include <bits/stdc++.h>
using namespace std;

int* positive_array(int *arr, int n) {
    int *pos = arr;
    for (int i=0; i<n; i++) {
        if (arr[i] == 0) {
            swap(arr[i], *pos);
            pos++;
        }
    }
    return pos;
}

int mark_index(int *arr, int n) {
    for(int i=0;i<n;i++) if (abs(arr[i]-1) < n) arr[arr[i]-1] *= -1;
    int i;
    for(i=0;i<n;i++) if (arr[i] > 0) return (i+1);
    return (n+1);
} 

int find_missing(int *arr, int n) {
    int *pos = positive_array(arr, n);
    int size = (arr+n) - pos;
    int missing = mark_index(pos, size);
    return missing;
}

int main() {
	//code
	int T, n, temp;
	cin >> T;
	while(T--!=0) {
	    cin >> n;
	    int arr[n];
	    for (int i=0; i<n; i++) {
	        cin >> temp;
	        if (temp<0) temp = 0;
	        arr[i] = temp;
	    }
	    int missing = find_missing(arr, n);
	    cout << missing << endl;
	}
	return 0;
}