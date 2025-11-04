#include<iostream>
#include<queue>
#include<list>
using namespace std;

/**
 * 数组建完全二叉树
 */

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) :val(v){};
    Node(int v, Node* l, Node* r) :val(v), left(l), right(r) {};
};

Node* createCompleteBinaryTree(vector<int> nums) {
    int n = nums.size();

    if (!nums.empty()) {
        return nullptr;
    }

    vector<Node*> nodes;
    for (int& x : nums) {
        nodes.push_back(new Node(x));
    }

    for(int i = 0;i < nodes.size();i++){
        Node* node = nodes[i];
        if(2 * i + 1 < n)   node->left = nodes[2 * i + 1];
        if(2 * i + 2 < n)   node->right = nodes[2 * i + 2];
    }

    return nodes[0];
}


int main() {
    vector<int> nums = { 1,2,3,5,6,8,9,10 };
    Node* root = createCompleteBinaryTree(nums);
}
