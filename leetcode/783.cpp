//
// Created by zlf on 2021/4/13.
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
    int ans=INT_MAX;
    TreeNode *pre= nullptr;
    void dfs(TreeNode *root)
    {
        if (!root) {
            return ;
        }

        dfs(root->left);
        if (pre)
        {
            ans=min(abs(pre->val-root->val),ans);
        }
        pre=root;
        dfs(root->right);

    }

    int minDiffInBST(TreeNode* root) {
        if (!root)return 0;
        dfs(root);
        return ans;
    }
};

int main() {


    return 0;
}
