#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

struct MinHeap {
    Node* heap[256];
    int size;
};

Node* createNode(char c, int f) {
    Node* node = new Node();
    node->ch = c;
    node->freq = f;
    node->left = node->right = NULL;
    return node;
}

void swap(Node*& a, Node*& b) {
    Node* temp = a;
    a = b;
    b = temp;
}

void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->heap[l]->freq < h->heap[smallest]->freq)
        smallest = l;
    if (r < h->size && h->heap[r]->freq < h->heap[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(h->heap[i], h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void heapifyUp(MinHeap* h, int i) {
    if (i && h->heap[(i-1)/2]->freq > h->heap[i]->freq) {
        swap(h->heap[i], h->heap[(i-1)/2]);
        heapifyUp(h, (i-1)/2);
    }
}

void insertHeap(MinHeap* h, Node* node) {
    h->heap[h->size] = node;
    heapifyUp(h, h->size);
    h->size++;
}

Node* extractMin(MinHeap* h) {
    Node* root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

void generateCodes(Node* root, char code[],
                   int depth, char codes[256][256]) {
    if (!root) return;

    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[(int)root->ch], code);
        return;
    }

    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, codes);

    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, codes);
}

int main() {
    char S[10005];
    int k;

    cin >> S >> k;
    int n = strlen(S);

    int freq[256] = {0};
    char codes[256][256] = {{0}};
    long long L = 0;

    for (int t = k; t <= n; t += k) {

        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < t; i++)
            freq[(int)S[i]]++;

        MinHeap h;
        h.size = 0;

        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0)
                insertHeap(&h, createNode((char)i, freq[i]));
        }

        if (h.size == 1) {
            strcpy(codes[(int)h.heap[0]->ch], "0");
        }
        else {
            while (h.size > 1) {
                Node* a = extractMin(&h);
                Node* b = extractMin(&h);

                Node* merged = createNode('\0', a->freq + b->freq);
                merged->left = a;
                merged->right = b;

                insertHeap(&h, merged);
            }

            char temp[256];
            generateCodes(h.heap[0], temp, 0, codes);
        }

        for (int i = t - k; i < t; i++)
            L += strlen(codes[(int)S[i]]);
    }

    cout << "Final Huffman Codes:\n";
    for (int i = 0; i < 256; i++) {
        if (codes[i][0] != '\0')
            cout << (char)i << " : " << codes[i] << "\n";
    }

    cout << "Total Encoded Length = " << L << "\n";
    return 0;
}
