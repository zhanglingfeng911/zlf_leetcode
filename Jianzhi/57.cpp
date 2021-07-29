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


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        unordered_set<int>set;
        vector<int>res;
        for (int i = 0; i < len; ++i) {
            if (set.count(target-nums[i]))
            {
                return {nums[i],target-nums[i]};
            }
            else
            {
                set.insert(nums[i]);
            }
        }

        return {};
    }
};

int main() {
    vector<int>nums={2,7,11,5};
    int target=9;
    Solution sl;
    vector<int>ret=sl.twoSum(nums,target);
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i]<<endl;
    }

    return 0;
}