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

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}

//TLE
class Solution1 {
public:
    int purchasePlans(vector<int> &nums, int target) {
        int len = nums.size();

        vector<vector<int>> dp(target + 1, vector<int>(3));
        dp[0][0] = 1;

        for (int &num:nums) {
            for (int k = 2; k > 0; --k) {
                for (int j = target; j >= num; --j) {
                    dp[j][k] += dp[j - num][k - 1];

                }
            }
        }

        int maxvalue = 0;
        for (int i = target; i >= 0; --i) {
            maxvalue += dp[i][2];
        }
        return maxvalue;
    }
};

vector<int>copy_nums;
vector<int>v;
class Solution {
public:
    int purchasePlans(vector<int> &nums, int target) {

        sort(nums.begin(), nums.end());
        long long ret = 0;


        for (int i = 0; i < nums.size(); ++i) {
            if (i<nums.size()-1&&nums[i]==nums[i+1])
            {
                copy_nums.push_back(nums[i]);
                while (nums[i]==nums[i+1])
                {
                    i++;
                }

            }
            else{
                copy_nums.push_back(nums[i]);
            }
        }

        int len = copy_nums.size();
        int i = 0, j = len - 1;

        while (i < j) {
            if (copy_nums[i] + copy_nums[j] >=target) {
                if (copy_nums[i] + copy_nums[j]==target)
                {
                    ret++;
                }
                j--;

            } else {
                ret++;
                i++;
                v.push_back(copy_nums[i]);
                v.push_back(copy_nums[j]);
            }
        }
        long long count=0;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j <nums.size(); ++j) {
                if (nums[j]==v[i])
                {
                    while (nums[j]==nums[j+1])
                    {
                        count++;
                        j++;
                    }
                }
            }
        }

        ret+=count;
        return ret%mod;

    }
};

int main() {

    vector<int> nums = {2,5,3,5};
    int target = 6;
    Solution sl;
    cout << sl.purchasePlans(nums, target) << endl;
    return 0;
}