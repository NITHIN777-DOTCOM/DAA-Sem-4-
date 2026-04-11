#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// comparator (min heap)
struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// print codes
void printCodes(Node* root, string code) {
    if(!root) return;

    if(root->ch != '#')
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;

    priority_queue<Node*, vector<Node*>, cmp> pq;

    // input characters and frequencies
    for(int i = 0; i < n; i++) {
        char c;
        int f;
        cin >> c >> f;
        pq.push(new Node(c, f));
    }

    // build tree
    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // print codes
    printCodes(pq.top(), "");

    return 0;
}