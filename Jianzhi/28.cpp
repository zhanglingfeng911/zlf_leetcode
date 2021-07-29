//
// Created by zlf on 2021/4/4.
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool help(TreeNode *r1, TreeNode *r2) {
        if (!r1 && !r2) {
            return true;
        }
        if (!r1 || !r2) {
            return false;
        }
        if (r1->val != r2->val) {
            return false;
        }

        return help(r1->left, r2->right) && help(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root)return true;
        return help(root->left, root->right);

    }
};

int main() {


    return 0;
}