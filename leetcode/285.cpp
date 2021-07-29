//
// Created by zlf on 2021/4/5.
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
#include <stack>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}

};
class Solution2 {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (!root)
        {
            return nullptr;
        }

        stack<TreeNode*>stk;
        bool  isfind= false;
//        TreeNode *res= nullptr;
        while (!stk.empty()||root)
        {
            while (root)
            {
                stk.push(root);
                root=root->left;
            }
            if (!stk.empty())
            {
                TreeNode *tmp=stk.top();
                stk.pop();

                if (isfind) return tmp;
                if (tmp==p)
                {
                    isfind= true;

                }
                if (tmp->right)
                {
                    root=tmp->right;
                }
            }
        }
        return nullptr;


    }
};


class Solution {
public:
    TreeNode *pre= nullptr;
    TreeNode *suc=nullptr;
     void help(TreeNode *root, TreeNode *p) {
         if (!root)
         {
             return ;
         }
         help(root->left,p);
         if (pre==p)
         {
             suc=root;
         }
         pre=root;
         help(root->right,p);

     }
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (!root)
        {
            return nullptr;
        }
        help(root,p);
        return suc;

    }
};
int main() {

    TreeNode *t1=new TreeNode(1);
    TreeNode *t2=new TreeNode(2);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t5=new TreeNode(5);

    t1->left=t2;
    t2->right=t3;
    t3->left=t4;
    t1->right=t5;

    Solution sl;
    cout<<sl.inorderSuccessor(t1,t4)->val<<endl;
    return 0;
}
