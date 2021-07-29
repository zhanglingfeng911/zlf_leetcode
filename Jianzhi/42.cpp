
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
    int maxSubArray(vector<int>& nums) {

        int cur_sum = 0;
        int max_sum = INT_MIN;
        for (int num : nums) {
            if(cur_sum <=0) {
                cur_sum = num;
            } else {
                cur_sum += num;
            }

            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;

    }
};

int main() {

    vector<int> nums = {-1};
    Solution sl;
    cout << sl.maxSubArray(nums) << endl;
    return 0;
}