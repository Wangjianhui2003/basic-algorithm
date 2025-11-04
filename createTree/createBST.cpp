#include<iostream>
#include<queue>
#include<list>
using namespace std;

/**
 * 建平衡二叉搜索树
 */

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v, Node* l, Node* r) :val(v), left(l), right(r) {};
};

Node* createBST(vector<int> nums);
Node* build(vector<int> nums, int left, int right);

Node* createBST(vector<int> nums) {
    return build(nums, 0, nums.size());
}

Node* build(vector<int> nums, int left, int right) {
    if (left == right) return nullptr;
    int mid = left + (right - left) / 2;
    return new Node(nums[mid], build(nums, left, mid), build(nums, mid + 1, right));
}

void traceInorder(Node* node) {
    if (node != nullptr) {
        traceInorder(node->left);
        cout << node->val << " ";
        traceInorder(node->right);
    }
}

int main() {
    vector<int> nums = { 1,2,3,5,6,8,9,10 };
    Node* root = createBST(nums);
    traceInorder(root);
}
