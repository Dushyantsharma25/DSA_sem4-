#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

struct compare {
    bool operator()(node* l, node* r) {
        return l->data > r->data;
    }
};

void generate_codes(node* root, string code, unordered_map<int, string>& huffman_codes) {
    if (!root) return;

    // If this is a leaf node, store the code
    if (!root->left && !root->right) {
        huffman_codes[root->data] = code;
    }

    generate_codes(root->left, code + "0", huffman_codes);
    generate_codes(root->right, code + "1", huffman_codes);
}

void hoffman_tree(vector<node*>& nodes) {
    priority_queue<node*, vector<node*>, compare> pq(nodes.begin(), nodes.end());

    while (pq.size() > 1) {
        node* left = pq.top();
        pq.pop();
        node* right = pq.top();
        pq.pop();

        node* parent = new node(left->data + right->data);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    nodes.clear();
    nodes.push_back(pq.top());
}

int main() {
    int n;
    cout << "Enter number of nodes \n";
    cin >> n;
    vector<node*> nodes;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << endl;
        cin >> data;
        nodes.push_back(new node(data));
    }

    hoffman_tree(nodes);

    // The root of the Huffman Tree will be the only remaining node
    node* root = nodes[0];
    cout << "Root of Huffman Tree: " << root->data << endl;

    // Generate Huffman codes
    unordered_map<int, string> huffman_codes;
    generate_codes(root, "", huffman_codes);

    // Print Huffman codes
    cout << "Huffman Codes:\n";
    for (auto& pair : huffman_codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
