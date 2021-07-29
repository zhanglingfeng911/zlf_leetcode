

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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int help(TreeNode *root)
    {
        if (!root)return 0;
        int left=help(root->left);
        if (left==-1)return -1;
        int right=help(root->right);

        if (right==-1)return -1;
        return abs(right-left)>1?-1:1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {

        return help(root)!=-1;

    }
};
int main() {


    return 0;
}