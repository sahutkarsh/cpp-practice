bool check_validity(string str) {
    str = str + ".";
    vector<string> splits;
    vector<int> numbers;
    string temp_str = "";
    int temp_num;
    for(int i=0; i<str.length(); i++) {
        if (str[i] != '.') temp_str += string(1, str[i]);
        else {
            splits.push_back(temp_str);
            temp_num = stoi(temp_str);
            numbers.push_back(temp_num);
            temp_str = "";
        }
    }
    for (int i=0; i<4; i++) {
        temp_str = splits[i];
        temp_num = numbers[i];
        if (temp_str.length() > 3 || temp_num < 0 || temp_num > 255) return false;
        if (temp_str.length() > 1 && temp_num == 0) return false;
        if (temp_str.length() > 1 && temp_num != 0 && temp_str[0] == '0') return false;
    }
    return true;
}

void create_ip(string A, vector<string> &ip) {
    int len = A.size();
    string str = A;
    for (int i=0; i<len-2; i++) {
        for (int j=i+1; j<len-1; j++) {
            for (int k=j+2; k<len; k++) {
                str = str.substr(0,k-1) + "." + str.substr(k,1);
                str = str.substr(0,j-1) + "." + str.substr(j,1);
                str = str.substr(0,i-1) + "." + str.substr(i,1);
            }
            if (check_validity(str)) {
                ip.push_back(str);
                str = A;
            }
        }
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ip;
    int len = A.length();
    if (len < 3 || len > 12) return ip;
    sort(A.begin(), A.end());
    create_ip(A, ip);
    return ip;
}
