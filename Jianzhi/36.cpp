//
// Created by zlf on 2021/7/17.
//

//
// Created by zlf on 2021/3/31.
//
#include<iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:

    Node* head = nullptr;
    Node* pre_node = nullptr;
    void  dfs(Node* root) {

        if(!root) {
            return;
        }

        dfs(root->left);

        if (!pre_node) {
            head = root;
        } else {
            pre_node->right = root;
        }

        root->left = pre_node;
        pre_node = root;

        dfs(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if(!root) {
            return root;
        }

        dfs(root);

        //head的前驱是最后一个节点
        head->left = pre_node;

        //最后一个节点的后继是第一个节点
        pre_node->right  = head;
        return head;
    }
};

int main() {


    return 0;
}