//
// Created by zlf on 2021/7/25.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    TreeNode *pre = nullptr;

    void flatten(TreeNode *root) {

        if(!root) {
            return ;
        }

        flatten(root->right);
        flatten(root->left);

        root->left = nullptr;
        root->right = pre;
        pre = root;
    }
};


int main() {


    return 0;
}