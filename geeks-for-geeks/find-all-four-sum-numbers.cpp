#include <bits/stdc++.h>
using namespace std;

void validate_quads(unordered_multimap<int,int> &quads, int* arr, int n) {
    map<string, int> quads_str;
    for (auto itr = quads.begin(); itr != quads.end(); itr++) {
        vector<int> quad;
        quad.push_back(arr[(itr->first)/n]);
        quad.push_back(arr[(itr->first)%n]);
        quad.push_back(arr[(itr->second)/n]);
        quad.push_back(arr[(itr->second)%n]);
        sort(quad.begin(), quad.end());
        string str = "";
        for (int i=0; i<4; i++) str += (to_string(quad[i])+",");
        quads_str[str] = 1;
    }
    for (auto itr = quads_str.begin(); itr != quads_str.end(); itr++) {
        string quad_str = itr->first;
        string num = "";
        for(int i=0; i<quad_str.length(); i++) {
            if (quad_str[i] != ',') num += quad_str[i];
            else {
                cout << num << " ";
                num = "";
            }
        }
        cout << "$";
    }
    cout << endl;
}

bool validate_index(int enc1, int enc2, int n) {
    int a = enc1 / n;
    int b = enc1 % n;
    int c = enc2 / n;
    int d = enc2 % n;
    if (a==c || a==d || b==c || b==d) return false;
    return true;
}

void find_quadruplets(int *arr, int n, int target) {
    unordered_multimap<int,int> pair_sum, quads;
    int encoded, sum;
    bool flag = false;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            encoded = i*n+j;
            pair_sum.insert({encoded, (arr[i] + arr[j])});
        }
    }
    for (auto itr1 = pair_sum.begin(); itr1 != pair_sum.end(); itr1++) {
        for (auto itr2 = pair_sum.begin(); itr2 != pair_sum.end(); itr2++) {
            sum = (itr1->second) + (itr2->second);
            if (sum == target && itr1 != itr2) {
                if (validate_index(itr1->first, itr2->first, n)) {
                    quads.insert({itr1->first, itr2->first});
                    flag = true;
                }
            }
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    validate_quads(quads, arr, n);
}

int main() {
	//code
	int t, n, target;
	cin >> t;
	while(t--) {
	    cin >> n >> target;
	    int arr[n];
	    for (int i=0; i<n; i++) cin >> arr[i];
	    find_quadruplets(arr, n, target);
	}
	return 0;
}