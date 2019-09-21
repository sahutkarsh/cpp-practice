#include <bits/stdc++.h>
using namespace std;

void print_array(long int *arr, int n) {
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

long int trapped_water(long int *arr, int n) {
    long int *left = arr;
    long int *right = arr + n - 1;
    long int left_max = 0, right_max = 0, volume = 0;
    while (left <= right) {
        if (*left < *right) {
            if (*left > left_max) left_max = *left;
            else volume += (left_max - *left);
            left += 1;
        }
        else {
            if (*right > right_max) right_max = *right;
            else volume += (right_max - *right);
            right -= 1;
        }
    }
    return volume;
}

int main() {
	int T, n;
	cin >> T;
	while(T--) {
	    cin >> n;
	    long int arr[n];
	    for (int i=0; i<n; i++) cin >> arr[i];
	    long int volume = trapped_water(arr, n);
	    cout << volume << endl;
	}
	return 0;
}