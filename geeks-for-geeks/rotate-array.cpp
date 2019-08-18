#include <iostream>
using namespace std;

int rotated_index(int index, int n, int d) {
    int rotated = index + d;
    if (rotated > (n-1)) {
        rotated = rotated - n;
    }
    return rotated;
}

int inverse_rotated(int index, int n, int d) {
    int rotated = index - d;
    if (rotated < 0) {
        rotated = rotated + n;
    }
    return rotated;
}

void rotate(int *arr, int n, int d) {
    int vacant=0, temp=arr[vacant], rotated, update_start=0;
    int iterations = 0;
    while (iterations!=(n)) {
        iterations++;
        rotated = rotated_index(vacant, n, d);
        arr[vacant] = arr[rotated];
        vacant = rotated;
        if(vacant==update_start) {
            update_start++;
            arr[inverse_rotated(vacant, n, d)] = temp;
            vacant = update_start;
            temp = arr[vacant];
        }
    }
}

int main() {
	//code
	int T, N, D;
	cin >> T;
	while(T--!=0) {
	    cin >> N >> D;
	    int arr[N];
	    for (int i=0; i<N; i++) cin >> arr[i];
	    rotate(arr, N, D);
	    for (int i=0; i<N; i++) cout << arr[i] << " ";
	    cout << endl;
	}
	return 0;
}