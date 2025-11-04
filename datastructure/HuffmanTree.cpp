#include<iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    double weight;
    int lchild, rchild, parent;
};

// 寻找权值最小的两个未合并结点(parent == -1)
void Select2Min(TreeNode huffmanTree[], int n, int& idx1, int& idx2)
{
    // 初始化为最大值
    double weight1 = INFINITY, weight2 = INFINITY;
    idx1 = idx2 = -1;

    // 找到未合并结点中最小的两个
    for (int i = 0; i < n; i++) {
        if (huffmanTree[i].parent == -1) {
            if (huffmanTree[i].weight < weight1) {
                // 当前结点权值比最小值还小，更新最小和次小
                weight2 = weight1;
                idx2 = idx1;
                weight1 = huffmanTree[i].weight;
                idx1 = i;
            }
            else if (huffmanTree[i].weight < weight2) {
                // 当前结点权值比次小值小，更新次小
                weight2 = huffmanTree[i].weight;
                idx2 = i;
            }
        }
    }
}

//原地构建哈夫曼树
void createHuffmanTree(TreeNode huffmanTree[], double weight[], int n)
{
    // 初始化
    for (int i = 0; i < 2 * n - 1; i++) {
        huffmanTree[i].lchild = -1;
        huffmanTree[i].rchild = -1;
        huffmanTree[i].parent = -1;
    }

    // 构造n棵只含有根结点的二叉树
    for (int i = 0; i < n; i++) {
        huffmanTree[i].weight = weight[i];
    }

    // 进行n-1次合并
    for (int i = n; i < 2 * n - 1; i++) {
        int idx1, idx2;
        Select2Min(huffmanTree, i, idx1, idx2);  // 获取两个最小权值结点

        // 合并为新结点
        huffmanTree[idx1].parent = i;
        huffmanTree[idx2].parent = i;
        huffmanTree[i].weight = huffmanTree[idx1].weight + huffmanTree[idx2].weight;
        huffmanTree[i].lchild = idx1;
        huffmanTree[i].rchild = idx2;
    }
}

//哈夫曼编码
void createHuffmanCode(TreeNode huffmanTree[], int n) {
    //huffmanTree的前n个是叶子结点，后n个是非叶子节点
    for (int i = 0; i < n; i++) {
        string code = "";
        int currentNode = i;
        int parent;

        // 从叶子结点回溯到根结点，生成编码
        while ((parent = huffmanTree[currentNode].parent) != -1) {
            // 判断是左孩子还是右孩子
            if (huffmanTree[parent].lchild == currentNode) {
                code = "0" + code;  // 左孩子编码为0
            }
            else {
                code = "1" + code;  // 右孩子编码为1
            }
            currentNode = parent;
        }
        cout << "权值为" << huffmanTree[i].weight << "的霍夫曼编码为：" << code << endl;
    }
}

int main() {
    TreeNode huffmanTree[20];
    int n = 10;
    double w[20] = { 0.35,0.20,0.11,0.09,0.08,0.07,0.04,0.03,0.02,0.01 };
    createHuffmanTree(huffmanTree, w, n);  //贪心法构建哈夫曼树
    createHuffmanCode(huffmanTree, n); //回溯生成哈夫曼编码
    return 0;
}

