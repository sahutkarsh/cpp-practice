#include <bits/stdc++.h>
using namespace std;

void tokenize(vector<string> &tokens, string line, string delimiter){
    line.append(delimiter);
    int len = line.length();
    int j=0;
    for (int i=0;i<len;i++){
        if(line.substr(i,1)==delimiter){
            string token = line.substr(j, i-j);
            tokens.push_back(token);
            j=i+1;
        }
    }
    
}

void fetch_attributes(vector<string> &tokens, map<string,string> &attribute_map){
    int len = tokens.size();
    int reduce = 2;
    for(int i=1;i<=len-3;i=i+3){
        if (i==(len-3)) reduce=3;
        attribute_map[tokens[i]] = tokens[i+2].substr(1, tokens[i+2].length()-reduce);
    }
}

struct action_info {
    string type;
    string tag_name;
    map <string,string> attributes;
};

struct node {
        string name;
        bool root = false;
        map <string, string> attributes;
        map <string, struct node*> child;
};

struct action_info get_action(string line){
    struct action_info action;
    if (line[1]=='/'){
        action.type = "close";
        action.tag_name = line.substr(2, line.length()-3);
    }
    else {
        action.type = "open";
        vector <string> tokens;
        map <string,string> attribute_map;
        tokenize(tokens, line, " ");
        if (tokens.size()>1){
            fetch_attributes(tokens, attribute_map);
            action.tag_name = tokens[0].substr(1,tokens[0].length()-1);
        }
        else action.tag_name = tokens[0].substr(1,tokens[0].length()-2);
        action.attributes = attribute_map;
    }
    return action;
}

string solve_query(map <string, struct node*> &tag_pointers, string query_string) {
    vector <string> query_tokens;
    tokenize(query_tokens, query_string, "~");
    string tag_chain = query_tokens[0];
    string req_attribute = query_tokens[1];
    query_tokens.clear();
    tokenize(query_tokens, tag_chain, ".");
    if(tag_pointers.find(query_tokens[0])==tag_pointers.end()) return "Not Found!";
    struct node req_node = *tag_pointers[query_tokens[0]];
    if(req_node.root==false) return "Not Found!";
    if(query_tokens.size()>1){
        for(int i=1;i<query_tokens.size();i++){
            if (req_node.child.find(query_tokens[i])==req_node.child.end()) {
                return "Not Found!";
            }
            else req_node = *(req_node.child[query_tokens[i]]);
        }
    }
    if(req_node.attributes.find(req_attribute)==req_node.attributes.end()){
        return "Not Found!";
    }
    else return req_node.attributes[req_attribute];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, Q;
    cin >> N >> Q;
    cin.ignore(1, '\n');
    char code[N][201], query[Q][201];

    for (int i=0;i<N;i++){
        cin.getline(code[i], sizeof(code[i]));
    }
    for (int i=0;i<Q;i++){
        cin.getline(query[i], sizeof(query[i]));
    }

    struct action_info action;
    struct node* head;
    map <string, struct node*> tag_pointers;
    stack <string> head_labels;

    head_labels.push("initial");
    struct node initial;
    tag_pointers["initial"] = &initial;

    for (int i=0;i<N;i++){
        action = get_action(code[i]);
        if (action.type=="open"){
            struct node *tag = new struct node;
            (*tag).name = action.tag_name;
            (*tag).attributes = action.attributes;

            if(head_labels.top()!="initial") (*head).child[action.tag_name] = tag;
            else (*tag).root = true;
            head = tag;
            head_labels.push(action.tag_name);
            tag_pointers[action.tag_name] = tag;
        }
        else {
            head_labels.pop();
            head = tag_pointers[head_labels.top()];
        }
    }

    for (int i=0;i<Q;i++){
        string answer = solve_query(tag_pointers, query[i]);
        cout << answer << endl;
    }
    return 0;
}