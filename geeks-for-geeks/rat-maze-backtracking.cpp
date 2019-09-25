#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void moveLoc(pair<int,int> &loc, string dir) {
    if (dir == "U") loc.first -= 1;
    else if (dir == "D") loc.first += 1;
    else if (dir == "L") loc.second -= 1;
    else if (dir == "R") loc.second += 1;
}

void revLoc(pair<int,int> &loc, string dir) {
    if (dir == "U") loc.first += 1;
    else if (dir == "D") loc.first -= 1;
    else if (dir == "L") loc.second += 1;
    else if (dir == "R") loc.second -= 1;
}

bool isValid(pair<int,int> &loc, int n, int m[MAX][MAX], unordered_map<int,int> &visited) {
    int r = loc.first, c = loc.second;
    if (r < 0 || c < 0) return false;
    if (r > n-1 || c > n-1) return false;
    if (m[r][c] == 0) return false;
    if (visited[r*n+c] == 1) return false;
    return true;
}

void backTrack(pair<int,int> &loc, int n, vector<string> &paths, string &path, int m[MAX][MAX], unordered_map<int,int> &visited, int index) {
    //if (index > 2) return;
    if (loc.first == n-1 && loc.second == n-1) {
        //cout << "Path Found!" << endl;
        paths.push_back(path);
        return;
    }
    vector<string> dir = {"U", "L", "R", "D"};
    for (auto itr = dir.begin(); itr != dir.end(); itr++) {
        path += *itr;
        //cout << path;
        moveLoc(loc, *itr);
        if (isValid(loc, n, m, visited)) {
            //cout << " Pass" << endl;
            //cout << "Position: " << loc.first << " " << loc.second << endl;
            visited[loc.first * n + loc.second] = 1;
            backTrack(loc, n, paths, path, m, visited, index+1);
            visited[loc.first * n + loc.second] = 0;
            path.pop_back();
            revLoc(loc, *itr);
        }
        else {
            //cout << " Fail" << endl;
            //cout << "Position: " << loc.first << " " << loc.second << endl;
            path.pop_back();
            revLoc(loc, *itr);
        }
    }
}

void findPath(int m[MAX][MAX], int n, vector<string> &paths) {
    vector<string> dir = {"U", "L", "R", "D"};
    for (auto itr = dir.begin(); itr != dir.end(); itr++) {
        unordered_map<int,int> visited;
        visited[0] = 1;
        pair<int,int> loc = make_pair(0,0);
        string path = "";
        path += *itr;
        moveLoc(loc, *itr);
        if (isValid(loc,n,m,visited)) {
            visited[loc.first * n + loc.second] = 1;
            backTrack(loc, n, paths, path, m, visited, 0);
            visited[loc.first * n + loc.second] = 0;
        }
        else {
            path.pop_back();
            revLoc(loc, *itr);
        }
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here
    vector<string> paths;
    findPath(m,n,paths);
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */