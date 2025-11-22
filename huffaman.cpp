#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};

void buildCodes(Node* root, string code, unordered_map<char,string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = code;
        return;
    }

    buildCodes(root->left,  code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

int main() {
    string text = "huffman coding";

    unordered_map<char,int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto &p : freq)
        pq.push(new Node(p.first, p.second));

    // Build tree
    while (pq.size() > 1) {
        Node* left = pq.top();  pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();

    unordered_map<char,string> codes;
    buildCodes(root, "", codes);

    cout << "Huffman Codes:\n";
    for (auto &p : codes)
        cout << p.first << " : " << p.second << "\n";

    return 0;
}
