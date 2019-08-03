#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        cout << hex << showbase << left << nouppercase;
        cout << (long long int)A << endl;

        cout << dec << right << setprecision(2) << setw(15) << setfill('_') << showpos << fixed;
        cout << B << endl;

        cout << scientific << uppercase << noshowpos << setprecision(9);
        cout << C << endl;

	}
	return 0;

}