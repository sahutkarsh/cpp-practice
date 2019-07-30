#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: protected Cache {
    public:
        LRUCache(int capacity) {
            cp = capacity;
        }
        int get(int key) {
            if (mp.find(key)==mp.end()) return -1;
            else return (*mp[key]).value;
        }
        int display_status() {
            // This is an additional debugging function, delete during final submission
            cout << "Map Size: " << mp.size() << " Sequence: ";
            if(mp.size()>cp){
                cout << "Error" << endl;
                return 0;
            }
            Node* current = head;
            for (int i=0; i<mp.size(); i++) {
                cout << (*current).value << " ";
                current = (*current).next;
            }
            cout << endl;
            return 0;
        }
        void set(int key, int value) {
            int key_exist = get(key);
            if(key_exist==-1) {
                Node *node = new Node(key, value);
                mp[key] = node;
                if (mp.size() > 1) {
                    (*head).prev = node;
                    (*node).next = head;
                    if (mp.size() > cp) {
                        int remove_key = (*tail).key;
                        tail = (*tail).prev;
                        mp.erase(remove_key);
                    }
                }
                else {
                    tail = node;
                }
                head = node;
            }
            else {
                Node *node = mp[key];
                (*node).value = value;
                if(node!=head) {
                    if(node==tail) {
                        tail = (*node).prev;
                    }
                    else {
                        (*((*node).prev)).next = (*node).next;
                        (*((*node).next)).prev = (*node).prev;
                    }
                    (*head).prev = node;
                    (*node).next = head;
                    head = node;
                }
            }
            //display_status();
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}