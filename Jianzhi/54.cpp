//
// Created by zlf on 2021/3/29.
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
    int index=0,ret;
    void dfs(TreeNode *root,int k)
    {
        if (!root)
        {
            return;
        }
        dfs(root->right,k);
        index++;
        if (index==k)
        {
           ret=root->val;
            return;
        }
        dfs(root->left,k);
    }
    int kthLargest(TreeNode* root, int k) {
        if (!root)
        {
            return 0;
        }
         dfs(root,k);
        return ret;
    }
};

int main() {
     TreeNode *t1=new TreeNode(3);
     TreeNode *t2=new TreeNode(1);
     TreeNode *t3=new TreeNode(4);
     TreeNode *t4=new TreeNode(2);

     t1->left=t2;
     t1->right=t3;
     t2->left=t4;
     Solution sl;
      cout<<sl.kthLargest(t1,2)<<endl;


    return 0;
}