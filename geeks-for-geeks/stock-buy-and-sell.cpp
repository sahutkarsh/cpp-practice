#include <bits/stdc++.h>
using namespace std;

int profit(int *arr, int n, vector<int> &buy, vector<int> &sell) {
    int flag = 0;
    int buy_index = 0, sell_index;
    for (int i=1;i<n-1;i++) {
        if (arr[i-1] > arr[i] && arr[i+1] > arr[i]) {
            //cout << arr[i] << " Minima" << endl;
            buy_index = i;
            buy.push_back(buy_index);
        }
        if (arr[i-1] < arr[i] && arr[i+1] < arr[i]) {
            //cout << arr[i] << " Maxima" << endl;
            if (buy.empty()) buy.push_back(buy_index);
            sell_index = i;
            sell.push_back(sell_index);
        }
    }
    int size = buy.size();
    if (size != sell.size()) sell.push_back(n-1);
    if (size != 0) flag = 1;
    return flag;
}

void print_profit(vector<int> &buy, vector<int> &sell) {
    for (int i=0; i<buy.size(); i++) {
        cout << "(" << buy[i] << " "<< sell[i] << ")" << " ";
    }
    cout << endl;
}

int main() {
	//code
	int T, n;
	cin >> T;
	while(T--) {
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++) cin >> arr[i];
	    vector<int> buy, sell;
	    int flag = profit(arr, n, buy, sell);
	    if (flag==0) cout << "No Profit" << endl;
	    else print_profit(buy, sell);
	}
	return 0;
}