#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void printSpiral(struct Node *root);
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printSpiral(root);
    cout<<endl;
  }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

void order_push(Node* root, deque<Node*> &dq, deque<Node*> &dq_dsp, bool rev) {
    if (rev) {
        if(root->right != NULL) dq_dsp.push_back(root->right);
        if (root->left != NULL) dq_dsp.push_back(root->left);
        if (root->right != NULL) dq.push_front(root->right);
        if (root->left != NULL) dq.push_front(root->left);     
    }
    else {
        if(root->left != NULL) dq_dsp.push_back(root->left);
        if (root->right != NULL) dq_dsp.push_back(root->right);
        if (root->left != NULL) dq.push_front(root->left);
        if (root->right != NULL) dq.push_front(root->right);
    }
}

void printSpiral(Node *root)
{
    //Your code here
    queue<Node*> q, q_dsp;
    deque<Node*> dq, dq_dsp;
    bool rev = false;
    Node *temp;
    Node *null_node = new Node(-1);
    q.push(root);
    q.push(null_node);
    q_dsp.push(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == null_node) {
            for (int i=0; i<dq.size(); i++) q.push(dq[i]);
            dq.clear();
            for (int i=0; i<dq_dsp.size(); i++) q_dsp.push(dq_dsp[i]);
            dq_dsp.clear();
            if (q.size() == 0) break;
            if (rev) rev = false;
            else rev = true;
            q.push(null_node);
            continue;
        }
        order_push(temp, dq, dq_dsp, rev);
    }
    while(!q_dsp.empty()) {
        temp = q_dsp.front();
        cout << temp->data << " ";
        q_dsp.pop();
    }
}