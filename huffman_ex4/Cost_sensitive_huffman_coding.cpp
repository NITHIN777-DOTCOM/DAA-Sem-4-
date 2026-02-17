#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string sym;
    long long w;
    Node *l, *r;
    Node(string s, long long w) : sym(s), w(w), l(NULL), r(NULL) {}
};

struct cmp
{
    bool operator()(Node *a, Node *b)
    {
        return a->w > b->w;
    }
};

void gen(Node *root, string code, map<string, string> &codes, long long &cost)
{
    if (!root->l && !root->r)
    {
        codes[root->sym] = code;
        cost += root->w * code.size();
        return;
    }
    gen(root->l, code + "0", codes, cost);
    gen(root->r, code + "1", codes, cost);
}

int main()
{
    int n;
    cout << "Enter the number of symbols : " << endl;
    cin >> n;

    priority_queue<Node *, vector<Node *>, cmp> pq;

    vector<string> sym(n);
    vector<long long> f(n), c(n);
    cout << "Enter the weights and transmisson cost of each symbol : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> sym[i] >> f[i] >> c[i];
        pq.push(new Node(sym[i], f[i] * c[i]));
    }

    while (pq.size() > 1)
    {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();
        Node *m = new Node(a->sym + b->sym, a->w + b->w);
        m->l = a;
        m->r = b;
        pq.push(m);
    }

    map<string, string> codes;
    long long totalCost = 0;
    gen(pq.top(), "", codes, totalCost);

    for (auto &x : codes)
        cout << x.first << " " << x.second << "\n";

    cout << "The minimum Cost = " << totalCost << "\n";
}
