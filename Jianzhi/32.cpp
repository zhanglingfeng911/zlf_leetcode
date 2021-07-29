//
// Created by zlf on 2021/3/26.
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<int> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = que.front();
                que.pop();
                res.push_back(tmp->val);
                if (tmp->left) {
                    que.push(tmp->left);
                }
                if (tmp->right) {
                    que.push(tmp->right);
                }

            }
        }
        return res;
    }
};

class Solution2 {
public:

    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> res;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = que.front();
                que.pop();
                res.push_back(tmp->val);
                if (tmp->left) {
                    que.push(tmp->left);
                }
                if (tmp->right) {
                    que.push(tmp->right);
                }

            }
            ans.push_back(res);
        }
        return ans;
    }
};


class Solution3 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        bool is_left = false;
        while (!que.empty()) {
            vector<int> res;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = que.front();
                que.pop();
                res.push_back(tmp->val);
                if (tmp->left) {
                    que.push(tmp->left);
                }
                if (tmp->right) {
                    que.push(tmp->right);
                }

            }
            is_left = !is_left;
            if (is_left) {
                ans.push_back(res);
            }
            else{

//                reverse(res.begin(),res.end());
                ans.push_back(vector<int>(res.rbegin(),res.rend()));
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}
