#include <bits/stdc++.h>
using namespace std; 

struct Node {
    char data;
    unordered_map<char,Node*> child;
    bool leaf = false;
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
            (parent->child)[word[i]] = new Node;
            parent = (parent->child)[word[i]];
            parent->data = word[i];
        }
        else {
            parent = (parent->child)[word[i]];
        }
        i += 1;
    }
    parent->leaf = true;
}

void buildTrie(string *dictionary, int n, Node* root) {
    for (int i=0; i<n; i++) {
        string word = dictionary[i];
        trie_insert(word, root);
    }
}

int main() 
{ 
    int T, n;
    string word;
    cin >> T;
    while(T--) {
        cin >> n;
        string dictionary[n];
        for (int i=0; i<n; i++) cin >> dictionary[i];
        cin >> word;
        Node *root = new Node;
        buildTrie(dictionary, n, root);
        cout << isWord(word, root) << endl;
    }
    return 0; 
} 