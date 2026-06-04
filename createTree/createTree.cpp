#include <bits/stdc++.h>
using namespace std;

struct Node {
    char v;
    Node* left;
    Node* right;
    Node() {}
    Node(char v, Node* left, Node* right) :v(v), left(left), right(right) {}
};

/**
 * 用先序字符串建树
 * ABC##DE#G##F##
 */
Node* build_tree_by_string(const string& s, int& idx) {
    if (idx >= (int)s.size()) return nullptr;
    if (s[idx] == '#') {
        idx++;
        return nullptr;
    }
    Node* node = new Node(s[idx], nullptr, nullptr);
    idx++;
    node->left = build_tree_by_string(s, idx);
    node->right = build_tree_by_string(s, idx);
    return node;
}

void preorder(Node* node) {
    if (node == nullptr) {
        cout << "";
        return;
    }
    cout << node->v;
    preorder(node->left);
    preorder(node->right);
}

void test1() {
    string s;
    cin >> s;
    int idx = 0;
    Node* node = build_tree_by_string(s, idx);
    preorder(node);
}

int main(int argc, char const* argv[])
{
    test1();
    return 0;
}
