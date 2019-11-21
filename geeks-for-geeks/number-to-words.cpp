#include <bits/stdc++.h>
using namespace std;

vector<string> single = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                             "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                             "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                       "Eighty", "Ninety"};
vector<string> powers = {"Hundred", "Thousand", "Million", "Billion"};

string three_digit(vector<int> &digits, int start) {
    int mid = start + 1, end = start + 2;
    if (digits[start] == 0 && digits[mid] == 0 && digits[end] == 0) return "";
    string word = "";
    if (digits[end] != 0) word = single[digits[end]] + powers[0];
    if (digits[mid] < 2) {
        int idx = digits[mid] * 10 + digits[start];
        if (idx != 0) word += single[idx];
    }
    else {
        word += tens[digits[mid]];
        if (digits[start] != 0) word += single[digits[start]];
    }
    return word;
}

void get_digits(vector<int> &digits, int n) {
    int temp = n;
    while (temp != 0) {
        digits.push_back(temp%10);
        temp /= 10;
    }
}

void convert(int n) {
    if (n < 20) {
        cout << single[n];
        return;
    }
    vector<int> digits;
    get_digits(digits, n);
    int len = digits.size();
    if (len % 3 != 0) {
        int pad = 3 - (len%3);
        while (pad--) digits.push_back(0);
    }
    len = digits.size();
    string words = three_digit(digits, 0);
    if (len > 3) {
        int idx = 1, start = 3;
        while (start < len) {
            string section = three_digit(digits, start);
            if (section != "") {
                words = three_digit(digits, start) + powers[idx] + words;
            }
            idx += 1;
            start += 3;
        }
    }
    cout << words;
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        convert(n);
        cout << endl;
    }
    return 0;
}