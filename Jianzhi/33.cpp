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

class Solution {
public:

    bool helper(vector<int> &postorder, int i, int j) {
        if (i >= j) {
            return true;
        }
        int root = postorder[j];
        int mid = i;
        while (postorder[mid] < root) {
            mid++;
        }
        int k = mid;
        while (k < j) {
            if (postorder[k] < root) {
                return false;
            } else
                k++;

        }

        return helper(postorder, i, mid - 1) && helper(postorder, mid, j - 1);
    }

    bool verifyPostorder(vector<int> &postorder) {
        int len = postorder.size();
        if (len == 1) { return true; }
        return helper(postorder, 0, len - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 6, 5};
    vector<int> nums1 = {1, 6, 3, 2, 5};
    Solution sl;
    cout << sl.verifyPostorder(nums1) << endl;

    return 0;
}