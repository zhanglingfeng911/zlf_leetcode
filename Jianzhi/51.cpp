//
// Created by zlf on 2021/7/18.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:

    int merge_sort(vector<int> &nums, vector<int> &aux, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + ((right - left) >> 1);
        int ans = merge_sort(nums, aux, left, mid) +
                  merge_sort(nums, aux, mid + 1, right);
        for (int i = left; i <= right; ++i) {
            aux[i] = nums[i];
        }

        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (aux[i] <= aux[j]) {
                nums[k] = aux[i];
                ++i;
            } else {
                nums[k] = aux[j];
                ans += mid - i + 1;
                ++j;
            }
            ++k;
        }

        while (i <= mid) {
            nums[k] = aux[i];
            ans += mid - i + 1;
            ++i;
            ++k;
        }

        while (j <= right) {
            nums[k] = aux[j];
            ++j;
            ++k;
        }

        return  ans;
    }

    int reversePairs(vector<int> &nums) {
        int len = nums.size();
        vector<int> aux(len);
        return merge_sort(nums, aux, 0, len - 1);
    }
};

int main() {

    vector<int> nums = {7, 5, 6, 4};
    Solution sl;
    cout << sl.reversePairs(nums) << endl;

    return 0;
}