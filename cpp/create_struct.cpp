#include <bits/stdc++.h>
using namespace std;

// C++如何定义结构体
struct Node {
    int v;
    Node *left;
    Node *right;
    Node(int v) : v(v), left(nullptr), right(nullptr) {}
    Node(int v, Node *l, Node *r) : v(v), left(l), right(r) {}
};

// 结构体数组 struct array
struct Student {
    string name;
    int score;
};

Student arr[3] = {{"Tom", 90}, {"Alice", 95}, {"Bob", 88}};

int main(int argc, char const *argv[]) {
    Node node1{24};
    cout << node1.v;
    Node *node2 = new Node(25);
    cout << node2->v;
    return 0;
}
