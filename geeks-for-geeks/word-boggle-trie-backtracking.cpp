#include <bits/stdc++.h>
using namespace std; 

/*bool isWord(string &str, string *dictionary, int n) 
{ 
    for (int i = 0; i < n; i++) 
        if (str.compare(dictionary[i]) == 0) 
            return true; 
    return false; 
}*/

struct Node {
    char data;
    unordered_map<char,Node*> child;
    bool leaf = true;
};

bool isWord(string word, Node* root) {
    int size = word.size(), i=0;
    Node* parent = root;
    while (true) {
        char key = word[i];
        if ((parent->child).find(key) == (parent->child).end()) return false;
        else {
            parent = (parent->child)[key];
            i += 1;
        }
        if (i==size && parent->leaf) break;
    }
    return true;
}

void trie_insert(string word, Node* root) {
    int size = word.size(), i=0;
    Node* parent = root;
    while (i < size) {
        if ((parent->child).find(word[i]) == (parent->child).end()) {
            parent->leaf = false;
            (parent->child)[word[i]] = new Node;
            parent = (parent->child)[word[i]];
            parent->data = word[i];
        }
        else {
            parent = (parent->child)[word[i]];
        }
        i += 1;
    }
}

void buildTrie(string *dictionary, int n, Node* root) {
    for (int i=0; i<n; i++) {
        string word = dictionary[i];
        trie_insert(word, root);
    }
}

void findWordsUtil(char **boggle, bool **visited, int i, 
                   int j, string& str, int M, int N, Node* root, vector<string> &words) 
{ 
    visited[i][j] = true; 
    str = str + boggle[i][j]; 
    if (isWord(str, root)) {
        words.push_back(str);
    }
    for (int row = i - 1; row <= i + 1 && row < M; row++) 
        for (int col = j - 1; col <= j + 1 && col < N; col++) 
            if (row >= 0 && col >= 0 && !visited[row][col]) 
                findWordsUtil(boggle, visited, row, col, str, M, N, root, words); 
    str.erase(str.length() - 1); 
    visited[i][j] = false; 
} 
  

void findWords(char **boggle, int M, int N, Node* root, vector<string> &words) 
{
    bool **visited = new bool*[M];
    for (int i=0; i<M; i++) visited[i] = new bool[N];
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) visited[i][j] = false;
    }
    string str = ""; 
    for (int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++)
            findWordsUtil(boggle, visited, i, j, str, M, N, root, words);
} 

int main() 
{ 
    int T, n, M, N;
    cin >> T;
    while(T--) {
        cin >> n;
        string dictionary[n];
        for (int i=0; i<n; i++) cin >> dictionary[i];
        cin >> M >> N;
        char **boggle = new char*[M];
        for (int i=0; i<M; i++) boggle[i] = new char[N];
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) cin >> boggle[i][j];
        }
        vector<string> words;
        Node *root = new Node;
        buildTrie(dictionary, n, root);
        findWords(boggle, M, N, root, words);
        sort(words.begin(), words.end());
        if (words.size()==0) {
            cout << -1 << endl;
            continue;
        }
        for (int i=1; i<words.size(); i++) {
            if (words[i-1] != words[i]) cout << words[i-1] << " ";
        }
        cout << words[words.size()-1];
        cout << endl;
    }
    return 0; 
} 