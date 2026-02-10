#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int f;
    Node *l, *r;
    Node(char c, int f) : ch(c), f(f), l(NULL), r(NULL) {}
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

void dfs(Node* root, string s, map<char,string>& code) {
    if (!root) return;
    if (!root->l && !root->r)
        code[root->ch] = s;
    dfs(root->l, s + "0", code);
    dfs(root->r, s + "1", code);
}

int main() {
    string s; 
    cin >> s;

    map<char,int> freq;
    for (char c : s) freq[c]++;

    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node *a = pq.top(); pq.pop();
        Node *b = pq.top(); pq.pop();
        Node *m = new Node('$', a->f + b->f);
        m->l = a; m->r = b;
        pq.push(m);
    }

    map<char,string> code;
    dfs(pq.top(), "", code);

    int L = 0;
    for (char c : s) L += code[c].size();

    for (auto p : code)
        cout << p.first << " : " << p.second << endl;

    cout << "Total bits = " << L << endl;
}
