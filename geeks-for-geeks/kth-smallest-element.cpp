#include <iostream>
using namespace std;

int partition(int *arr, int low, int high) {
    int i = low - 1;
    int pivot = arr[high];
    for (int j=low; j<high; j++) {
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

int quick_select(int *arr, int low, int high, int k, int n) {
    if (low <= high) {
        int pos = partition(arr, low, high);
        if (pos==(k-1)) {
            return pos;
        }
        if (pos > (k-1)) return quick_select(arr, low, pos-1, k, n);
        else return quick_select(arr, pos+1, high, k, n);
    }
    return 0;
}

int main() {
	//code
	int T, N, K, answer;
	cin >> T;
	while (T--!=0) {
	   cin >> N;
	   int arr[N];
	   for (int i=0;i<N;i++) cin >> arr[i];
	   cin >> K;
	   answer = quick_select(arr, 0, N-1, K, N);
	   cout << arr[answer] << endl;
	}
	return 0;
}