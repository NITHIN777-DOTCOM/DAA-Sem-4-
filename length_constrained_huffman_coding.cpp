#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int freq;
    int symbol;
    Node *left, *right;
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

Node *buildHuffman(vector<int> &freq)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (int i = 0; i < freq.size(); i++)
    {
        Node *n = new Node();
        n->freq = freq[i];
        n->symbol = i;
        n->left = n->right = NULL;
        pq.push(n);
    }

    while (pq.size() > 1)
    {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();

        Node *parent = new Node();
        parent->freq = a->freq + b->freq;
        parent->symbol = -1;
        parent->left = a;
        parent->right = b;

        pq.push(parent);
    }
    return pq.top();
}

void computeLengths(Node *root, int depth, vector<int> &len)
{
    if (!root)
        return;

    if (root->symbol != -1)
    {
        len[root->symbol] = depth;
        return;
    }
    computeLengths(root->left, depth + 1, len);
    computeLengths(root->right, depth + 1, len);
}

int main()
{
    int n, Lmax;
    cout << "Enter n : \n";
    cin >> n;
    cout << "Enter Lmax : \n";
    cin >> Lmax;
    vector<int> freq(n);
    cout << "Enter frequiencies : \n";
    for (int i = 0; i < n; i++)
        cin >> freq[i];

    if (n > (1 << Lmax))
    {
        cout << "Not possible\n";
        return 0;
    }

    Node *root = buildHuffman(freq);

    vector<int> length(n, 0);
    computeLengths(root, 0, length);

    for (int i = 0; i < n; i++)
    {
        if (length[i] > Lmax)
        {
            cout << "Not possible\n";
            return 0;
        }
    }

    long long W = 0;
    for (int i = 0; i < n; i++)
        W += (long long)freq[i] * length[i];

    cout << "Minimum Weighted Path Length = " << W << "\n";
    return 0;
}
